#include "Engine.h"
char window_title[] = "Breakout";

int main(int argc, char** argv)
{
	Engine* gameEngine = new Engine(window_title, 800, 600);
	GameObject* test = gameEngine->instantiate(new GameObject(new Vector2(100.f, 100.f), 20.f, 20.f));
	test->velocity = new Vector2(0.2f, 0.f);
	gameEngine->startGame();

	return 0;
}