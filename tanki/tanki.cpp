#include <iostream>
#include <SFML/Graphics.hpp>
#include "Field.h"



int main()
{
	Clock clock;
	float time = clock.getElapsedTime().asMicroseconds();

	Field field;
	field.game(time);
}