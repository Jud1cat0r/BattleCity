#include "Bullet.h"

Bullet::Bullet()
{
	image.loadFromFile("images/" + file);
	image.createMaskFromColor(Color(0, 0, 0));
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}

Bullet::Bullet(float x = -50, float y = -50, int dir = 0)
{
	this->x = x;
	this->y = y;
	this->dir = dir;
	image.loadFromFile("images/" + file);
	image.createMaskFromColor(Color(0, 0, 0));
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	rect = new Rect<float>(x, y, w, h);
}

Bullet::Bullet(Bullet& bullet)
{
	this->x = bullet.x;
	this->y = bullet.y;
	this->w = bullet.w;
	this->h = bullet.h;
	this->dx = bullet.dx;
	this->dy = bullet.dy;
	this->speed = bullet.speed;
	this->dir = bullet.dir;
	this->status = bullet.status;
	this->image = bullet.image;
	this->texture = bullet.texture;
	this->sprite = bullet.sprite;
	this->rect = bullet.rect;
}

Bullet& Bullet::operator=(Bullet& bullet)
{
	this->x = bullet.x;
	this->y = bullet.y;
	this->w = bullet.w;
	this->h = bullet.h;
	this->dx = bullet.dx;
	this->dy = bullet.dy;
	this->speed = bullet.speed;
	this->dir = bullet.dir;
	this->status = bullet.status;
	this->image = bullet.image;
	this->texture = bullet.texture;
	this->sprite = bullet.sprite;
	this->rect = bullet.rect;
	return *this;
}

Sprite& Bullet::getSprite()
{
	return this->sprite;
}

void Bullet::setPositionX(float x)
{
	this->x = x;
}

void Bullet::setPositionY(float y)
{
	this->y = y;
}

void Bullet::setDir(int dir)
{
	this->dir = dir;
}

int Bullet::getDir()
{
	return this->dir;
}

void Bullet::setStatus(bool status)
{
	this->status = status;
}

float Bullet::getPositionX()
{
	return this->x;
}

Rect<float> Bullet::getRect()
{
	return *rect;
}

void Bullet::showBullet()
{
	std::cout << x << " : " << y<<"\n";
}

void Bullet::addSprite(float CurrentFrame, float x, float y, float w, float h)
{
	this->sprite.setTextureRect(IntRect(x + 32 * int(CurrentFrame), y, w, h));
}

void Bullet::setRect(Rect<float>* rect)
{
	this->rect = rect;
}

float Bullet::getPositionY()
{
	return this->y;
}

void Bullet::addSprite( float x, float y, float w, float h)
{
	this->sprite.setTextureRect(IntRect(x, y, w, h));
}


void Bullet::update(float time)
{
	switch (dir)
	{
	case 0:
		dx = 0;
		dy = -speed;
		break;
	case 1:
		dy = 0;
		dx = speed;
		break;
	case 2: 
		dx = 0;
		dy = speed;
		break;
	case 3: 
		dy = 0;
		dx = -speed;
		break;
	}

	x += dx * time;
	y += dy * time;
	/*if (this->status == false) speed = 0;
	else */speed = 0.2;
	sprite.setPosition(x, y);

}

//bool Bullet::checkMap(String* tileMap1)
//{
//	////bool flag = false;
//	////for (int i = y / 32; i < (y + h) / 32; i++)
//	////{
//	////	for (int j = x / 32; j < (x + w) / 32; j++)
//	////	{
//	////		if (tileMap1[i][j] == '0' || tileMap1[i][j] == '1')
//	////		{
//	////			if (dy > 0)
//	////			{
//	////				y = i * 32 - 8;
//	////			}
//	////			if (dy < 0)
//	////			{
//	////				y = i * 32 + 32;
//	////			}
//	////			if (dx > 0)
//	////			{
//	////				x = j * 32 - 8;
//	////			}
//	////			if (dx < 0)
//	////			{
//	////				x = j * 32 + 32;
//	////			}
//
//	////			return true;
//
//	////		}
//	//		//if (tileMap1[i][j] == 's') 
//	//		// {
//	//		//	x = 300; y = 300;
//	//		//	tileMap1[i][j] = ' ';
//	//		// }
//	////	}
//	////}
//	////return false;
//}