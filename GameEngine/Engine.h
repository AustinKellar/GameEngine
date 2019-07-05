#include <GLFW/glfw3.h>
#include "GameObject.h"
#include <vector>

class Engine;
static Engine* instance;

class Engine
{
	public: 
		// fields
		char* window_title;
		int window_height;
		int window_width;

		// constructor and destructor
		Engine(char* window_title, int window_width, int window_height);
		~Engine();

		// methods
		void startGame(int* argc, char** argv);
		GameObject* instantiate(GameObject* game_object);
	private:
		void init();
		void update();
		void display();
		std::vector<GameObject*>* game_objects;
};

