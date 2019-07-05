#include "Engine.h"
#include <functional>

Engine::Engine(char* window_title, int window_width, int window_height)
{
	this->window_title = window_title;
	this->window_width = window_width;
	this->window_height = window_height;
}

void Engine::startGame(int* argc, char ** argv)
{
	glutInit(argc, argv);
	centerOnScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_x, window_y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(window_title);
	init();
	setupDisplayCallback();
	glutMainLoop();
}

void Engine::centerOnScreen()
{
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
}

void Engine::init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Engine::drawObject()
{
	glutWireIcosahedron();
}

void Engine::display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawObject();
	glutSwapBuffers();
}

void Engine::setupDisplayCallback()
{
	instance = this;
	glutDisplayFunc(Engine::displayCallback);
}

void Engine::displayCallback()
{
	instance->display();
}