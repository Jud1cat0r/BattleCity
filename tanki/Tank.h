#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace sf;

class Tank
{
private:
	float x, y, w, h, dx, dy, speed = 0;
	int dir = 3;
	bool status = true;
	int life = 3;
	String file;
	Image image;
	Texture texture;
	Sprite sprite;
	Rect<float>* rect;
	int cur = 0;
	int count = 0;

public:
	Tank();
	Tank(String file, float x, float y, float w, float h);
	void setPosition(float, float);
	float getPositionX();
	float getPositionY();
	void setPositionX(float x);
	void setPositionY(float y);
	void addSprite(int x, int y, int w, int h);
	int getDir();
	void setDir(int dir);
	float getCur();
	void setCur(float cur);
	void setCount(int count);
	int getCount();
	float getSpeed();
	float getDy();
	float getDx();
	float getW();
	float getH();
	void setSpeed(float speed);
	void setSprite(Sprite sprite);
	Sprite& getSprite();
	void update(float time);
	void checkMap();
	Rect<float>* getRect();
};

