#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"


using namespace sf;


class Bang
{
	float x, y;
	String file;
	Image image;
	Texture texture;
	Sprite sprite;
	int status = 0;
public:
	Bang();
	Bang(float, float);
	Bang(Bang& boom);
	Bang& operator =(Bang& boom);
	void setPosition(float, float);
	void addSprite(float x, float y, float w, float h);
	void setX(float x);
	void setY(float y);
	float getX();
	float getY();
	void setSpritePosition(float x, float y);
	Sprite& getSprite();
	void boom(Bullet& bullet);
	bool update();
};

