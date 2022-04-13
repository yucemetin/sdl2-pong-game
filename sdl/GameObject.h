#ifndef GameObject_HEADER
#define GameObject_HEADER

#include<SDL.h>


class GameObject
{
public:
	double x, y, height, width, speed, directionX, directionY;

	GameObject();
	void setPosition(double x, double y);
	void setSize(double width, double height);
	void render(SDL_Surface surface);
	void move(double deltaTime);
	void setDirection(double directionX, double directionY);
	void setSpeed(double speed);
	SDL_Rect getRectangle();
};

#endif