#include "score.h"


Score::Score()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

void Score::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Score::setSize(double width, double height)
{
	this->height = height;
	this->width = width;
}

void Score::render(SDL_Surface surface)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	Uint32 color = SDL_MapRGB(surface.format, 0, 0, 0);
	SDL_FillRect(&surface, &rect, color);
}

