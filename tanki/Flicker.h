#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Flicker
{
	sf::RectangleShape rectangle;
	float x;
	float y;
public:
	Flicker();
	Flicker(float, float);
	void setPosition(float, float);
	sf::RectangleShape& getFlicker();
};

