#include "GameObject.h"

GameObject::GameObject()
{
	position = nullptr;
	width = 0;
	height = 0;
	half_width = 0;
	half_height = 0;
	velocity = nullptr;
	area = 0;
	ul = nullptr;
	ur = nullptr;
	ll = nullptr;
	lr = nullptr;
}

GameObject::GameObject(Vector2* position, float width, float height)
{
	this->position = position;
	this->width = width;
	this->height = height;
	this->half_width = (width / 2.f);
	this->half_height = (height / 2.f);
	this->velocity = new Vector2(0.f, 0.f);
	this->area = width * height;

	this->ul = new Vector2(position->x - half_width, position->y + half_height);
	this->ur = new Vector2(position->x + half_width, position->y + half_height);
	this->ll = new Vector2(position->x - half_width, position->y - half_height);
	this->lr = new Vector2(position->x + half_width, position->y - half_height);
}

GameObject::~GameObject()
{

}

void GameObject::update()
{
	applyPhysics();
	draw();
}

void GameObject::applyPhysics()
{
	this->position->x += this->velocity->x;
	this->position->y += this->velocity->y;
}

void GameObject::draw()
{
	glBegin(GL_QUADS);

	ll->x = position->x - half_width;
	ll->y = position->y - half_height;

	ul->x = position->x - half_width;
	ul->y = position->y + half_height;

	ur->x = position->x + half_width;
	ur->y = position->y + half_height;

	lr->x = position->x + half_width;
	lr->y = position->y - half_height;

	glVertex3f(ll->x, ll->y, 0.0);
	glVertex3f(ul->x, ul->y, 0.0);
	glVertex3f(ur->x, ur->y, 0.0);
	glVertex3f(lr->x, lr->y, 0.0);

	glEnd();
}