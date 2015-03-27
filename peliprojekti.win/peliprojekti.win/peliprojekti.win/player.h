#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "Animation.h"

enum Direction{ Right, Left };
sf::Vector2i source(0, Right);

class Player
{
public:
	enum Direction{ Right, Left };

	Player();
	~Player();

	

	void Initialize();
	void LoadContent();
	void Movement(sf::RenderWindow &Window);
	void Draw(sf::RenderWindow &Window);



protected:
	Animation playerAnimation;
private:
	

	
	sf::Texture pTexture;
	sf::Sprite playerImage;
	float x, y;
	int currentFrameX, currentFrameY;
	float moveSpeed = 6000.0f;
	
};

#endif