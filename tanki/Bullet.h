#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace sf;

class Bullet
{
private:
	float x, y, w, h, dx, dy, speed = 0.2;
	int dir = 3;
	String file = "tanks.bmp";
	Image image;
	Texture texture;
	Sprite sprite;
	Rect<float>* rect;
	bool status = true;
	int sizeBang = 0;


public:
	Bullet();
	Bullet(float x, float y, int dir);
	Bullet(Bullet& bullet);
	Bullet& operator=(Bullet& bullet);
	Sprite& getSprite();
	void update(float time);
	bool checkMap(String* tileMap1);
	void setPositionX(float x);
	void setPositionY(float y);
	float getPositionX();
	float getPositionY();
	void setDir(int dir);
	int getDir();
	void setStatus(bool status);
	void addSprite(float x, float y, float w, float h);
	void addSprite(float CurrentFrame, float x, float y, float w, float h);
	void setRect(Rect<float>* rect);
	Rect<float> getRect();
	void showBullet();
};

