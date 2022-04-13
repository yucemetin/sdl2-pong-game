#include "Ball.h"
#include "PongGame.h"

void Ball::move(double deltaTime)
{

	GameObject::move(deltaTime);

	if (y <= 0 && directionY < 0)
	{
		directionY *= -1;
	}


	if (y +height >= PongGame::SCREEN_HEIGHT && directionY > 0) {
		directionY *= -1;
	}

	

}
