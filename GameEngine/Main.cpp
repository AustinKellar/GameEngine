#include "Engine.h"
char window_title[] = "Breakout";

void main(int argc, char** argv)
{
	Engine* gameEngine = new Engine(window_title, 800, 600);
	gameEngine->startGame(&argc, argv);
}