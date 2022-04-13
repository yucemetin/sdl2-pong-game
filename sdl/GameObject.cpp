#include "GameObject.h"
#include "PongGame.h"

int r = 150;
int g = 75;
int b = 0;

GameObject::GameObject()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	directionX = 0;
	directionY = 0;
	speed = 0;
}

void GameObject::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;
}

void GameObject::setSize(double width, double height)
{
	this->height = height;
	this->width = width;
}

void GameObject::render(SDL_Surface surface)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	Uint32 color = SDL_MapRGB(surface.format, r, g, b);
	SDL_FillRect(&surface, &rect, color);

	r++;
	g++;
	b++;
}

void GameObject::move(double deltaTime)
{
	x += directionX * speed * deltaTime;
	y += directionY * speed * deltaTime;

	if (y < 0) {
		y = 0;
	}

	if (y+height > PongGame::SCREEN_HEIGHT) {
		y = PongGame::SCREEN_HEIGHT - height;
	}

}

void GameObject::setDirection(double directionX, double directionY)
{
	this->directionX = directionX;
	this->directionY = directionY;
}
void GameObject::setSpeed(double speed)
{
	this->speed = speed;
}

SDL_Rect GameObject::getRectangle()
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	return rect;

}