#pragma once
#include <SDL.h>

class EnemyScore
{
public:

	double x, y, height, width;

	void setPosition(double x, double y);
	void setSize(double width, double height);
	void render(SDL_Surface surface);
	EnemyScore();
};

