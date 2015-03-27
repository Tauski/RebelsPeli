#include <iostream>
#include <SFML/Graphics.hpp>



int main()
{
	sf::RenderWindow Window(sf::VideoMode(400, 400), "sfml works!" );
	return 0;
	while (Window.isOpen())
	{
	
		sf::Event Event;
		while (Window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;
			}
		}
}