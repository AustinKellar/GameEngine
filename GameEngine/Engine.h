#include <gl/freeglut.h>

class Engine;
static Engine* instance;

class Engine
{
	public: 
		// fields
		char* window_title;
		int window_height;
		int window_width;
		int window_x;
		int window_y;

		// constructor and destructor
		Engine(char* window_title, int window_width, int window_height);
		~Engine();

		// methods
		void startGame(int* argc, char** argv);
	private:
		void centerOnScreen();
		void init();
		void drawObject();
		void display();
		void setupDisplayCallback();
		static void displayCallback();
};

