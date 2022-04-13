#pragma once

#ifndef Score_HEADER
#define Score_HEADER

#include "SDL.h"

class Score
{
public:

	double x, y, height, width;

	void setPosition(double x, double y);
	void setSize(double width, double height);
	void render(SDL_Surface surface);
	Score();
};

#endif