#include "Bang.h"

Bang::Bang()
{
	image.loadFromFile("images/Bang.bmp");
	image.createMaskFromColor(Color(0, 0, 0));
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	//sprite.setPosition(x, y);
}

Bang::Bang(float x, float y)
{
	this->x = x;
	this->y = y;
	this->file = "Bang.bmp";
	image.loadFromFile("images/" + file);
	image.createMaskFromColor(Color(0, 0, 0));
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	sprite.setPosition(x, y);
	//std::cout << x << " : " << y;
}

void Bang::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

Bang::Bang(Bang& boom)
{
	this->x = boom.x;
	this->y = boom.y;
	this->file = boom.file;
	this->image = boom.image;
	this->texture = boom.texture;
	this->sprite = boom.sprite;
	this->status = boom.status;
}

void Bang::addSprite(float x, float y, float w, float h)
{
	this->sprite.setTextureRect(IntRect(x + (32 * status), y, w, h));
}

Bang& Bang::operator=(Bang& boom)
{
	this->x = boom.x;
	this->y = boom.y;
	this->file = boom.file;
	this->image = boom.image;
	this->texture = boom.texture;
	this->sprite = boom.sprite;
	this->status = boom.status;
	return *this;
}

void Bang::setX(float x)
{
	this->x = x;
}

void Bang::setY(float y)
{
	this->y = y;
}

float Bang::getX()
{
	return this->x;
}

float Bang::getY()
{
	return this->y;
}

void Bang::setSpritePosition(float x, float y)
{
	this->sprite.setPosition(x, y);
}

Sprite& Bang::getSprite()
{
	return sprite;
}

bool Bang::update()
{
	if (status < 3)
	{
		addSprite(0, 0, 32, 32);
		status++;
		return true;
	}
	else return false;
}

void Bang::boom(Bullet& bullet)
{
	if (bullet.getDir() == 0)//право
	{
		this->x = bullet.getPositionX() - 12;
		this->y = bullet.getPositionY() - 13;
		addSprite(0, 0, 32, 32);
		sprite.setPosition(x, y);
	}
	else if (bullet.getDir() == 1)//лево
	{
		this->x = bullet.getPositionX() - 12;
		this->y = bullet.getPositionY() - 13;
		addSprite(0, 0, 32, 32);
		sprite.setPosition(x, y);
	}
	else if (bullet.getDir() == 2)//низ
	{
		this->x = bullet.getPositionX() - 13;
		this->y = bullet.getPositionY() - 12;
		addSprite(0, 0, 32, 32);
		sprite.setPosition(x, y);
	}
	else//вверх
	{
		this->x = bullet.getPositionX() - 13;
		this->y = bullet.getPositionY() - 12;
		addSprite(0, 0, 32, 32);
		sprite.setPosition(x, y);
	}
}
