#pragma once
#include <iostream>
#include <gl/freeglut.h>
#include "Vector2.h"

class Engine;

class GameObject
{
	public:
		Vector2* position;
		float width;
		float height;
		float half_width;
		float half_height;
		Vector2* velocity;
		float area;
		Vector2* ul;
		Vector2* ur;
		Vector2* ll;
		Vector2* lr;

		GameObject();
		GameObject(Vector2* position, float width, float height);
		~GameObject();

		virtual void update();
		private:
			void applyPhysics();
			void draw();
};

