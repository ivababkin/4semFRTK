#include "pch.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <windows.h>

using namespace std;

void draw33angle(sf::RenderWindow& window, int topPointX, int topPointY, int length)
{
	if (length <= 10)
		return;
	sf::ConvexShape shape;
	shape.setPointCount(3);
	shape.setPoint(0, sf::Vector2f(topPointX, topPointY));
	shape.setPoint(1, sf::Vector2f(topPointX + length / 2, topPointY + length));
	shape.setPoint(2, sf::Vector2f(topPointX - length / 2, topPointY + length));

	shape.setOutlineThickness(-2);
	shape.setFillColor(sf::Color::Transparent);
	window.draw(shape);

	
	draw33angle(window, topPointX - length / 4, topPointY + length / 2, length / 2);
	draw33angle(window, topPointX + length / 4, topPointY + length / 2, length / 2);
	draw33angle(window, topPointX, topPointY, length / 2);
}


int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);//more chetko

	window.setFramerateLimit(1); //speed of discretisation 
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();			
		}

		
		draw33angle(window, 128, 128, 256);
		window.display();

		
	}
	cout << "Hello world" << endl;
	return 0;
}