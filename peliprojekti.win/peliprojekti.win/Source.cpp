#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>



int main()
{
	enum Direction { Right, Left};

	sf::Vector2i source(0, Right);

	float frameCounter = 0, switchFrame = 100, frameSpeed = 500;


	
	sf::RenderWindow window;
	window.create(sf::VideoMode(400, 400), "SFML works!");
	window.setKeyRepeatEnabled(false);
	sf::Texture pTexture;
	sf::Sprite playerImage;
	

	sf::Texture bgTexture;
	sf::Sprite bgImage;

	if (!pTexture.loadFromFile("Player.png"))
	std::cout << "error couldnt load player image" << std::endl;

	playerImage.setTexture(pTexture);
	playerImage.setPosition(0, 247);

	if (!bgTexture.loadFromFile("background.png"))
	std::cout << "error couldnt load from file!" << std::endl;

	bgImage.setTexture(bgTexture);
	bgImage.setScale(1.0f, 1.0f);

	sf::RectangleShape rect(sf::Vector2f(20, 20));
	rect.setFillColor(sf::Color::Red);

	sf::Clock clock;

	float movespeed = 6000.0f;

	sf::View view;
	view.reset(sf::FloatRect(0, 0, 400, 400));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

	sf::Vector2f position(0, 0);


	while (window.isOpen())
	{
		clock.restart();
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
	
		//liikkeet oikealle ja vasemmalle

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			source.y = Right;
			playerImage.move(0.07, 0);
			rect.move(movespeed * clock.getElapsedTime().asSeconds(), 0);
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			source.y = Left;
			playerImage.move(-0.07, 0);
			rect.move(-movespeed * clock.getElapsedTime().asSeconds() / 1.13, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}


		//selvitet‰‰n tietokoneen kellonopeuden avulla sopiva frameSpeed
		std::cout << clock.getElapsedTime().asSeconds() << std::endl;


		frameCounter += frameSpeed * clock.restart().asSeconds();
		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			source.x++;
			if (source.x * 41 >= pTexture.getSize().x)
				source.x = 0;
		}



		//cropataan sprite sheet niin ett‰ vain yksi frame n‰kyy kerralla
		playerImage.setTextureRect(sf::IntRect(source.x * 40, source.y * 73, 40, 73));

		//piirret‰‰n
		position.x = rect.getPosition().x + 10 + -(400 / 2);
		position.y = rect.getPosition().y + 10 - (400 / 2);

		if (position.x < 0)
			position.x = 0;
		if (position.y < 0)
			position.y = 0;

		view.reset(sf::FloatRect(position.x, position.y, 400, 400));

		window.setView(view);

		window.draw(bgImage);
		window.draw(playerImage);
		window.draw(rect);
		window.display();
		//poistaa vanhat framet, niin ettei n‰y p‰‰llekk‰isi‰ frameja
		window.clear();
	}

	return 0;
}