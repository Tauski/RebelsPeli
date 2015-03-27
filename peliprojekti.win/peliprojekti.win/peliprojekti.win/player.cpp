#include "Player.h"
#include "Animation.h"

Player::Player()
{
}


Player::~Player()
{
}

void Player::Initialize()
{
	x = y = 10;
	moveSpeed = 200;
	currentFrameX = currentFrameY = 0;

}


void Player::LoadContent()
{
	if (!pTexture.loadFromFile("Player.png"))
		std::cout << "error couldnt load the pTexture!" << std::endl;
	
}


void Player::Draw(sf::RenderWindow &Window)
{
	Window.draw(playerImage);
}