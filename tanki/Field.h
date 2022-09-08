#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Tank.h"
#include "Bullet.h"
#include "Bang.h"
#include "Flicker.h"
#include "Map1.h"

#define random(a,b) a + rand() % (b + 1 - a)

using namespace sf;

const int HEIGHT_MAP = 15;//высота
const int WIDTH_MAP = 20;//ширина

class Field
{
	RenderWindow window;
	Font font;
	Text text;
	Block* block = nullptr;
	Tank* tank = nullptr;
	Bullet* bullet = nullptr;
	Bang* bang = nullptr;
	int sizeBullet = 0;
	int sizeBlock = 0;
	int sizeTank = 0;
	int sizeBang = 0;


public:
	Field();
	~Field();
	void game(float time);
private:
	void eventState();
	void render(float time);
	void addTank(Tank& t);
	void addBullet(Bullet& bul);
	void delBullet(int index);
	void delBlock(int index);
	void addBlock(Block& bl);
	void addBang(Bang& boom);
	void delBang(int index);
	void checkMap();
	void enemyMove(Tank& t);
	void enemyShooting(Tank& t);
};

