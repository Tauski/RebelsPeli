#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


class Animation
{
public:
	Animation();

	void Initialize(int x, int y, int FrameX, int FrameY, sf::Texture tempTexture);
	void Update(sf::RenderWindow &Window);
	void Draw(sf::RenderWindow &Window);
	bool getActive();
	bool setActive(bool active);

	int getCurrentFrame(int axis);
	int setCurrentFrame(int axis, int value);

	int getPosition(int axis);
	int setPosition(int axis, int value);

	sf::Sprite setImage(sf::Texture);
protected:
	int getFrameWidth();
	int getFrameHeight();
	
private:

	sf::Sprite spriteImage;
	sf::Clock clock;


	int currentFrameX, currentFrameY;
	int frameCounter, switchFrame;
	float frameSpeed = 500;
	float x, y;
	int amountOfFramesX, amountOfFramesY;
	bool active;
};

#endif