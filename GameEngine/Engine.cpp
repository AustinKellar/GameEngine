#include "Engine.h"

// constructors and destructors

Engine::Engine(char* window_title, int window_width, int window_height)
{
	this->window_title = window_title;
	this->window_width = window_width;
	this->window_height = window_height;
	this->game_objects = new std::vector<GameObject*>();
}

Engine::~Engine()
{

}

// public methods

void Engine::startGame(int* argc, char ** argv)
{
	GLFWwindow* window;

	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	window = glfwCreateWindow(window_width, window_height, window_title, nullptr, nullptr);
	if (!window)
	{
		fprintf(stderr, "Failed to open GLFW window\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}


	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	// set up view
	glViewport(0, 0, window_width, window_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0, window_width, 0.0, window_height, 0.0, 1.0); // this creates a canvas you can do 2D drawing on

	while (!glfwWindowShouldClose(window))
	{
		display();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	exit(EXIT_SUCCESS);
}

GameObject* Engine::instantiate(GameObject* game_object)
{
	game_objects->push_back(game_object);
	return game_object;
}

// private methods

void Engine::init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Engine::update()
{
	for (int i = 0; i < game_objects->size(); i++) 
	{
		(*game_objects)[i]->update();
	}
}

void Engine::display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(10);
	glLineWidth(2.5);
	glColor3f(1.0, 1.0, 1.0);
	update();
}
