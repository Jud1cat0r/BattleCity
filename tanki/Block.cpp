#include "Block.h"

Block::Block()
{
}

Block::Block(String file, float x, float y, float w, float h, int type)
{
	this->file = file;
	this->status = status;
	this->w = w;
	this->h = h;
	image.loadFromFile("images/" + this->file);
	image.createMaskFromColor(Color(0, 0, 0));
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	this->x = x;
	this->y = y;
	rect = new Rect<float>(x, y, w, h);
	this->type = type;
	sprite.setTextureRect(IntRect(0, 0, w, h));
	//sprite.setPosition(x, y);
}

void Block::setSprite(Sprite sprite)
{
	this->sprite = sprite;
}

void Block::addSprite(float CurrentFrame, float x, float y, float w, float h)
{
	this->sprite.setTextureRect(IntRect(x + 32 * int(CurrentFrame), y, w, h));
}

void Block::setStatus(bool status)
{
	this->status = status;
}

bool Block::getStatus()
{
	return status;
}

int Block::getType()
{
	return this->type;
}

void Block::setFile(String file)
{
	this->file = file;
}

void Block::setType(int type)
{
	this->type = type;
}


Sprite& Block::getSprite()
{
	return this->sprite;
}


Block::Block(Block& block)
{
	this->x = block.x;
	this->y = block.y;
	this->w = block.w;
	this->h = block.h;
	this->status = block.status;
	this->file = block.file;
	this->image = block.image;
	this->texture = block.texture;
	this->sprite = block.sprite;
	this->type = block.type;
	this->rect = block.rect;
}

void Block::setPositionX(float x)
{
	this->x = x;
}

void Block::setPositionY(float y)
{
	this->y = y;
}

float Block::getPositionX()
{
	return this->x;
}

float Block::getPositionY()
{
	return this->y;
}

Block& Block::operator=(Block& block)
{
	this->x = block.x;
	this->y = block.y;
	this->w = block.w;
	this->h = block.h;
	this->status = block.status;
	this->file = block.file;
	this->image = block.image;
	this->texture = block.texture;
	this->sprite = block.sprite; 
	this->type = block.type;
	this->rect = block.rect;
	return *this;
}

void Block::setRect(Rect<float>* rect)
{
	this->rect = rect;
}

Rect<float> Block::getRect()
{
	return *rect;
}

void Block::showBlock()
{
	std::cout << x << " : " << y;
}

//Vector2<float> Block::getVectorBlock()
//{
//	Vector2<float>buf(x, y, w, h);
//	return buf;
//}
