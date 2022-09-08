#include "Tank.h"

Tank::Tank()
{
}

Tank::Tank(String file, float x, float y, float w, float h)
{
	this->file = file;
	this->w = w;
	this->h = h;
	image.loadFromFile("images/" + this->file);
	image.createMaskFromColor(Color(0, 0, 0));
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(x, y, w, h));
	rect = new Rect<float>(sprite.getGlobalBounds());
}

void Tank::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Tank::getPositionX()
{
	return x;
}

float Tank::getPositionY()
{
	return y;
}

void Tank::setPositionX(float x)
{
	this->x = x;
}

void Tank::setPositionY(float y)
{
	this->y = y;
}

void Tank::addSprite(int x, int y, int w, int h)
{
	this->sprite.setTextureRect(IntRect(x, y, w, h));
}

int Tank::getDir()
{
	return this->dir;
}

void Tank::setDir(int dir)
{
	this->dir = dir;
}

float Tank::getCur()
{
	return this->cur;
}

void Tank::setCur(float cur)
{
	this->cur = cur;
}

void Tank::setCount(int count)
{
	this->count = count;
}

int Tank::getCount()
{
	return this->count;
}

float Tank::getSpeed()
{
	return this->speed;
}

float Tank::getDy()
{
	return this->dy;
}

float Tank::getDx()
{
	return this->dx;
}

float Tank::getW()
{
	return this->w;
}

float Tank::getH()
{
	return this->h;
}

void Tank::setSpeed(float speed)
{
	this->speed = speed;
}

void Tank::setSprite(Sprite sprite)
{
	this->sprite = sprite;
}

Sprite& Tank::getSprite()
{
	return this->sprite;
}

void Tank::update(float time)
{
	switch (dir)
	{
	case 0:
		dx = speed;
		dy = 0;
		break;
	case 1:
		dx = -speed;
		dy = 0;
		break;
	case 2:
		dx = 0;
		dy = speed;
		break;
	case 3:
		dx = 0;
		dy = -speed;
		break;
	}
	x += dx * time;
	y += dy * time;
		

	sprite.setPosition(x, y);
	checkMap();
}

void Tank::checkMap()
{
}

Rect<float>* Tank::getRect()
{
	return rect;
}


