#include "EnemyScore.h"


EnemyScore::EnemyScore()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;

}

void EnemyScore::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;

}
void EnemyScore::setSize(double width, double height)
{
	this->height = height;
	this->width = width;

}
void EnemyScore::render(SDL_Surface surface)
{
	
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	Uint32 color = SDL_MapRGB(surface.format, 255, 255, 255);
	SDL_FillRect(&surface, &rect, color);

}

