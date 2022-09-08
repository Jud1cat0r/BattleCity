#include "Field.h"

Field::Field()
	: window(sf::VideoMode(640, 480), L"Tanks")
{
}

Field::~Field()
{
	delete[] bullet;
	delete[] block;
	//delete[] bullet;
}

void Field::game(float time)
{
	while (window.isOpen())
	{
		eventState();
		render(time);
	}
}

void Field::eventState()
{


	float currentFrame = 0;
	Clock clock;

	Tank tank1("tanks.bmp", 3, 133, 26, 26);
	tank1.setPositionX(320);
	tank1.setPositionY(240);
	Tank enemy("tanks.bmp", 3, 488, 26, 30);
	enemy.setSpeed(0.1);
	enemy.setDir(2);
	enemy.setPositionX(320);
	enemy.setPositionY(32);



	addTank(tank1);
	addTank(enemy);


	Bullet bul(150, 150, 0);

	Block bl1("brick2.png", 0, 0, 32, 32, 0);
	Block bl2("ironblock.png", 0, 0, 32, 32, 1);

	Bang boom(200, 200);

	bool flag = false;

	String tileMap1[HEIGHT_MAP] = {
		"00000000000000000000",
		"0                  0",
		"0                  0",
		"0                  0",
		"0  111             0",
		"0  1               0",
		"0                  0",
		"0                  0",
		"0                  0",
		"0                  0",
		"0             11   0",
		"0            11    0",
		"0                  0",
		"0                  0",
		"00000000000000000000",
	};

	for (int i = 0; i < HEIGHT_MAP; i++)
	{
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (tileMap1[i][j] == '1')
			{
				//Block buf("brick2.png", j * 32, i * 32, 32, 32);
				bl1.getSprite().setTextureRect(IntRect(0, 0, 32, 32));
				bl1.getSprite().setPosition(j * 32, i * 32);
				bl1.setPositionX(j * 32);
				bl1.setPositionY(i * 32);
				addBlock(bl1);
			}
			else if ((tileMap1[i][j] == '0'))
			{
				//Block buf("ironblock.png", j * 32, i * 32, 32, 32);
				bl2.getSprite().setTextureRect(IntRect(0, 0, 32, 32));
				bl2.getSprite().setPosition(j * 32, i * 32);
				bl2.setPositionX(j * 32);
				bl2.setPositionY(i * 32);
				bl2.setType(1);
				addBlock(bl2);
			}
		}
	}

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;


		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			tank[0].setDir(1);
			tank[0].setSpeed(0.1);
			currentFrame += 0.005 * time;
			if (currentFrame >= 2) currentFrame = 0;
			else if (currentFrame < 1) tank[0].addSprite(5, 227, 26, 26);
			else tank[0].addSprite(37, 227, 26, 26);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			tank[0].setDir(0);
			tank[0].setSpeed(0.1);
			currentFrame += 0.005 * time;
			if (currentFrame >= 2) currentFrame = 0;
			else if (currentFrame < 1) tank[0].addSprite(1, 163, 26, 26);
			else tank[0].addSprite(33, 163, 26, 26);
		}


		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			tank[0].setDir(3);
			tank[0].setSpeed(0.1);
			currentFrame += 0.005 * time;
			if (currentFrame >= 2) currentFrame = 0;
			else if (currentFrame < 1) tank[0].addSprite(3, 133, 26, 26);
			else tank[0].addSprite(35, 133, 26, 26);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			tank[0].setDir(2);
			tank[0].setSpeed(0.1);
			currentFrame += 0.005 * time;
			if (currentFrame >= 2) currentFrame = 0;
			else if (currentFrame < 1) tank[0].addSprite(3, 193, 26, 26);
			else tank[0].addSprite(35, 193, 26, 26);
		}

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			while(Keyboard::isKeyPressed(Keyboard::Space))
			{ }

			Vector2f v1 = tank[0].getSprite().getPosition();


			if (tank[0].getDir() == 0)//право
			{
				bul.setPositionX(v1.x + 26);
				bul.setPositionY(v1.y + 10);
				bul.setDir(1);
				bul.addSprite(8, 353, 8, 6);
			}
			else if (tank[0].getDir() == 1)//лево
			{
				bul.setPositionX(v1.x);
				bul.setPositionY(v1.y + 10);
				bul.setDir(3);
				bul.addSprite(24, 353, 8, 6);
			}
			else if (tank[0].getDir() == 2)//низ
			{
				bul.setPositionX(v1.x + 10);
				bul.setPositionY(v1.y + 26);
				bul.setDir(2);
				bul.addSprite(17, 352, 6, 8);
			}
			else//вверх
			{
				bul.setPositionX(v1.x + 10);
				bul.setPositionY(v1.y);
				bul.setDir(0);
				bul.addSprite(1, 352, 6, 8);
			}
			addBullet(bul);
			
		}
		



		window.clear();

		window.draw(boom.getSprite());

		checkMap();
		
		render(time);
	}
}

void Field::render(float time)
{


	for (int i = 0; i < sizeBlock; i++)
	{
		window.draw(block[i].getSprite());
	}
	for (int i = 0; i < sizeBullet; i++)
	{
		bullet[i].update(time);
		window.draw(bullet[i].getSprite());
		
	}
	for (int i = 0; i < sizeBang; i++)
	{
		if (bang[i].update() == true)
		{
			window.draw(bang[i].getSprite());
			std::cout << "boom" << " : " << bang[i].getX() << " : " << bang[i].getY() << std::endl;
			//system("pause");
		}
		else
		{
			delBang(i);
			i--;
		}
	}

	for (int i = 0; i < sizeTank; i++)
	{
		tank[i].update(time);
		if (i != 0)
		{
			enemyMove(tank[i]);
			if (random(0, 1000) == 0)
			{
				enemyShooting(tank[i]);
			}
		}
		window.draw(tank[i].getSprite());
	}
	tank[0].setSpeed(0);


	window.display();
}

void Field::addTank(Tank& t)
{
	Tank* buf = new Tank[sizeTank + 1];
	for(int i = 0; i < sizeTank;i++)
	{
		buf[i] = tank[i];
	}
	buf[sizeTank] = t;
	delete[]tank;
	tank = buf;
	sizeTank++;
}

void Field::addBullet(Bullet& bul)
{
	Bullet* buf = new Bullet[sizeBullet+1];
	for (int i = 0; i < sizeBullet; i++)
	{
		buf[i] = bullet[i];
	}
	buf[sizeBullet] = bul;
	delete[] bullet;
	bullet = buf;
	sizeBullet++;
}

void Field::delBullet(int index)
{
	Bullet* buf = new Bullet[sizeBullet - 1];
	for (int i = 0; i < index; i++)
	{
		buf[i] = bullet[i];
	}
	if (index > 0)
	{
		for (int i = index + 1; i < sizeBullet; i++)
		{
			buf[i - 1] = bullet[i];
		}
	}
	delete[]bullet;
	bullet = buf;
	sizeBullet--;

}

void Field::delBlock(int index)
{
	Block* buf = new Block[sizeBlock - 1];
	for (int i = 0; i < index; i++)
	{
		buf[i] = block[i];
	}

	for (int i = index + 1; i < sizeBlock; i++)
	{
		buf[i - 1] = block[i];
	}
	delete[]block;
	block = buf;
	sizeBlock--;
}

void Field::addBlock(Block& bl)
{
	Block* buf = new Block[sizeBlock + 1];
	for (int i = 0; i < sizeBlock; i++)
	{
		buf[i] = block[i];
	}
	buf[sizeBlock] = bl;
	delete[] block;
	block = buf;
	sizeBlock++;
}

void Field::addBang(Bang& boom)
{
	Bang* buf = new Bang[sizeBang + 1];
	for (int i = 0; i < sizeBang; i++)
	{
		buf[i] = bang[i];
	}
	buf[sizeBang] = boom;
	delete[] bang;
	bang = buf;
	sizeBang++;
}

void Field::delBang(int index)
{
	Bang* buf = new Bang[sizeBang - 1];
	for (int i = 0; i < index; i++)
	{
		buf[i] = bang[i];
	}
	if (index > 0)
	{
		for (int i = index + 1; i < sizeBang; i++)
		{
			buf[i - 1] = bang[i];
		}
	}
	delete[]bang;
	bang = buf;
	sizeBang--;
}

void Field::checkMap()
{
	float currentFrame = 0;
	Clock clock;
	float time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time = time / 800;
	bool flag = false;

	for (int i = 0; i < sizeBlock; i++)
	{
		Vector2i blockP1(block[i].getPositionX(), block[i].getPositionY());

		for (int j = 0; j < sizeBullet; j++)
		{
			Vector2i bulletP1(bullet[j].getPositionX(), bullet[j].getPositionY());

			if (bulletP1.x > blockP1.x && bulletP1.x < blockP1.x + 32 &&
				bulletP1.y > blockP1.y && bulletP1.y < blockP1.y + 32 ||

				bulletP1.x + 4 > blockP1.x && bulletP1.x + 4 < blockP1.x + 32 &&
				bulletP1.y > blockP1.y && bulletP1.y < blockP1.y + 32 ||

				bulletP1.x + 4 > blockP1.x && bulletP1.x + 4 < blockP1.x + 32 &&
				bulletP1.y + 8 > blockP1.y && bulletP1.y + 8 < blockP1.y + 32 ||

				bulletP1.x > blockP1.x && bulletP1.x < blockP1.x + 32 &&
				bulletP1.y + 8 > blockP1.y && bulletP1.y + 8 < blockP1.y + 32)
			{


				Bang buf;
				buf.boom(bullet[j]);
				addBang(buf);

				delBullet(j);
				if (j > 0) j--;

				if(block[i].getType() == 0)
				{
					delBlock(i);
					i--;
				}
			}
			else if (bulletP1.x < 0 || bulletP1.x > 640 || bulletP1.y < 0 || bulletP1.y > 480)
			{
				delBullet(j);
				if (j > 0) j--;
			}
			for (int l = 0; l < sizeTank; l++)
			{
				Vector2i tankP1(tank[l].getPositionX(), tank[l].getPositionY());

				if (bulletP1.x > tankP1.x && bulletP1.x < tankP1.x + 30 &&
					bulletP1.y > tankP1.y && bulletP1.y < tankP1.y + 30 ||

					bulletP1.x + 4 > tankP1.x && bulletP1.x + 4 < tankP1.x + 30 &&
					bulletP1.y > tankP1.y && bulletP1.y < tankP1.y + 30 ||

					bulletP1.x + 4 > tankP1.x && bulletP1.x + 4 < tankP1.x + 30 &&
					bulletP1.y + 8 > tankP1.y && bulletP1.y + 8 < tankP1.y + 30 ||

					bulletP1.x > tankP1.x && bulletP1.x < tankP1.x + 30 &&
					bulletP1.y + 8 > tankP1.y && bulletP1.y + 8 < tankP1.y + 30)
				{

					/////////////////////////////////////////////////////////////////

				}
			}
		}
		for (int j = 0; j < sizeTank; j++)
		{
			Vector2i tankP1(tank[j].getPositionX(), tank[j].getPositionY());

			if (tankP1.x > blockP1.x && tankP1.x < blockP1.x + 32 &&
				tankP1.y > blockP1.y && tankP1.y < blockP1.y + 32 ||

				tankP1.x + 26 > blockP1.x && tankP1.x + 26 < blockP1.x + 32 &&
				tankP1.y > blockP1.y && tankP1.y < blockP1.y + 32 ||

				tankP1.x + 26 > blockP1.x && tankP1.x + 26 < blockP1.x + 32 &&
				tankP1.y + 26 > blockP1.y && tankP1.y + 26 < blockP1.y + 32 ||

				tankP1.x > blockP1.x && tankP1.x < blockP1.x + 32 &&
				tankP1.y + 26 > blockP1.y && tankP1.y + 26 < blockP1.y + 32 ||

				tankP1.x > 640 && tankP1.x < 0 &&
				tankP1.y > 480 && tankP1.y < 0
				)
			{
				//if (tank[j].getDy() > 0)             640, 480
				//{
				//	tank[j].setPositionY(blockP1.x * 32 - 30);
				//}
				//if (tank[j].getDy() < 0)
				//{
				//	tank[j].setPositionY(blockP1.x * 32 + 32);
				//}
				//if (tank[j].getDx() > 0)
				//{
				//	tank[j].setPositionX(blockP1.y * 32 - 30);
				//}
				//if (tank[j].getDx() < 0)
				//{
				//	tank[j].setPositionX(blockP1.y * 32 + 32);
				//}

				switch (tank[j].getDir())
				{
				case 0:
					tank[j].setPositionX(blockP1.x - 26);//вправо
					break;
				case 1:
					tank[j].setPositionX(blockP1.x + 32);//влево
					break;
				case 2:
					tank[j].setPositionY(blockP1.y - 26);//вниз
					break;
				case 3:
					tank[j].setPositionY(blockP1.y + 32);//вверх
					break;
				}
				if (j != 0)
				{
					if (tank[j].getDir() <= 2)
					{
						tank[j].setDir(tank[j].getDir() + 1);
						tank[j].setSpeed(0.1);
					}
					else 
					{
						tank[j].setDir(0);
						tank[j].setSpeed(0.1);
					}
				}
			}
		}
	}

	//for (int j = 0; j < sizeBlock; j++)
	//{
	//	std::cout << block[j].getPositionX() << " : " << block[j].getPositionY() << std::endl;

	//}

}

void Field::enemyMove(Tank& t)
{
	float currentFrame = t.getCur();
	Clock clock;
	float time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time = time / 800;
	int count = t.getCount();




	if (t.getDir() == 1)//l
	{
		currentFrame += 0.005 * time;
		if (currentFrame >= 3) t.setCur(0);
		if (currentFrame < 1) t.addSprite(2, 523, 30, 26);
		else if (currentFrame < 2 && currentFrame >= 1) t.addSprite(34, 523, 30, 26);
		else t.addSprite(66, 523, 30, 26);
		t.setCount(t.getCount() + 1);
		if (count > 3000)
		{
			t.setDir(random(0, 3));
			t.setCount(0);
		}
	}

	if (t.getDir() == 0)//r
	{
		currentFrame += 0.005 * time;
		if (currentFrame >= 2) t.setCur(0);
		if (currentFrame < 1) t.addSprite(0, 459, 30, 26);
		else if (currentFrame < 2 && currentFrame >= 1) t.addSprite(32, 459, 30, 26);
		else t.addSprite(64, 459, 30, 26);
		t.setCount(t.getCount() + 1);
		if (count > 3000)
		{
			t.setDir(random(0, 3));
			t.setCount(0);
		}
	}


	if (t.getDir() == 3)//u
	{
		currentFrame += 0.005 * time;
		if (currentFrame >= 2) t.setCur(0);
		if (currentFrame < 1) t.addSprite(3, 426, 26, 30);
		else if (currentFrame < 2 && currentFrame >= 1) t.addSprite(35, 426, 26, 30);
		else t.addSprite(67, 426, 26, 30);
		t.setCount(t.getCount() + 1);
		if (count > 3000)
		{
			t.setDir(random(0, 3));
			t.setCount(0);
		}
	}

	if (t.getDir() == 2)//d
	{
		currentFrame += 0.005 * time;
		if (currentFrame >= 2) t.setCur(0);
		if (currentFrame < 1) t.addSprite(3, 488, 26, 30);
		else if (currentFrame < 2 && currentFrame >= 1) t.addSprite(35, 488, 26, 26);
		else t.addSprite(67, 488, 26, 30);
		t.setCount(t.getCount() + 1);
		if (count > 3000)
		{
			t.setDir(random(0, 3));
			t.setCount(0);
		}
	}
}

void Field::enemyShooting(Tank& t)
{
	Bullet bul(1, 1, 0);
	Vector2f v1 = t.getSprite().getPosition();

	if (t.getDir() == 0)//право
	{
		bul.setPositionX(v1.x + t.getW());
		bul.setPositionY(v1.y + (t.getH() / 2) - 5);
		bul.setDir(1);
		bul.addSprite(8, 353, 8, 6);
	}
	else if (t.getDir() == 1)//лево
	{
		bul.setPositionX(v1.x - 2);
		bul.setPositionY(v1.y + (t.getH() / 2) - 5);
		bul.setDir(3);
		bul.addSprite(24, 353, 8, 6);
	}
	else if (t.getDir() == 2)//низ
	{
		bul.setPositionX(v1.x + (t.getH() / 2) - 5);
		bul.setPositionY(v1.y + t.getW());
		bul.setDir(2);
		bul.addSprite(17, 352, 6, 8);
	}
	else//вверх
	{
		bul.setPositionX(v1.x + (t.getH() / 2) - 5);
		bul.setPositionY(v1.y - 6);
		bul.setDir(0);
		bul.addSprite(1, 352, 6, 8);
	}
	addBullet(bul);
}
