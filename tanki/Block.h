#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>


using namespace sf;

class Block
{
private:
	float x, y, w, h;
	String file;
	Image image;
	Texture texture;
	Sprite sprite;
	Rect<float>* rect;

	int type;
	bool status = true;
public:
	Block();
	Block(String file, float x, float y, float w, float h, int type);
	void setSprite(Sprite sprite);
	void addSprite(float CurrentFrame, float x, float y, float w, float h);
	void setStatus(bool status);
	bool getStatus();
	int getType();
	void setType(int type);
	void setFile(String file);
	Sprite& getSprite();
	Block(Block& block);
	void setPositionX(float x);
	void setPositionY(float y);
	float getPositionX();
	float getPositionY();
	Block& operator=(Block& block);
	void setRect(Rect<float>* rect);
	Rect<float> getRect();


	void showBlock();
};

