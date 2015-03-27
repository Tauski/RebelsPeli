#include "Animation.h"
#include "player.h"

Animation::Animation()
{
}


Animation::~Animation()
{
}

int Animation::getFrameWidth()
{
	return spriteImage.getScale().x / amountOfFramesX;
}

int Animation::getFrameHeight()
{
	return spriteImage.getScale().y / amountOfFramesY;
}

bool Animation::getActive()
{
	return active;
}

bool Animation::setActive(bool value)
{
	active = value;
}

int Animation::getCurrentFrame(int axis)
{
	if (axis == 1)
		return currentFrameX;
	else
		return currentFrameY;
}

int Animation::setCurrentFrame(int axis, int value)
{
	if (axis == 1)
		currentFrameX = value;
	else
		currentFrameY = value;
}

int Animation::getPosition(int axis)
{
	if (axis == 1)
		return x;
	else
		return y;
}

int Animation::setPosition(int axis, int value)
{
	if (axis == 1)
		x = value;
	else
		y = value;
}

void Animation::Initialize(int x, int y, int FrameX, int FrameY, sf::Texture tempTexture)
{
	frameCounter = 0;
	switchFrame = 100;
	this->x = x;
	this->y = y;
	this->amountOfFramesX = FrameX;
	this->amountOfFramesY = FrameY;
	this->spriteImage.setTexture(tempTexture);
	active = false;
}

void Animation::Update(sf::RenderWindow &Window)
{
	if (active)
		frameCounter += frameSpeed * clock.restart().asSeconds();
	else
		frameCounter = 0;
	if (frameCounter >= switchFrame)
	{
		frameCounter = 0;
		currentFrameX += getFrameWidth();
		if (currentFrameX >= spriteImage.getScale().x)
		currentFrameX = 0;
	}
	spriteImage.setTextureRect(sf::IntRect(currentFrameX, currentFrameY * getFrameHeight(), currentFrameX + getFrameWidth(), currentFrameY + getFrameHeight()));
	spriteImage.setPosition(x, y);



}

void Animation::Draw(sf::RenderWindow &Window)
{
	Window.draw(spriteImage);
}
