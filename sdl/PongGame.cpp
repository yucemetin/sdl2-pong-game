#include "PongGame.h"
#include<iostream>


void PongGame::init()
{
	player = new GameObject();
	enemy = new GameObject();
	ball = new Ball();
	score = new Score();
	enemyscr = new EnemyScore();

	resetGame();

}


void PongGame::render(SDL_Surface surface)
{

	player->render(surface);
	enemy->render(surface);
	ball->render(surface);
	score->render(surface);
	enemyscr->render(surface);
	
}

void PongGame::setPlayerDirection(double direction)
{

	player->setDirection(0, direction);
	enemy->setDirection(0, direction);
}

void PongGame::update(double deltaTime)
{
	player->move(deltaTime);
	enemy->move(deltaTime);
	ball->move(deltaTime);
	collisionDetection();
	checkScore();
	Ai();

}

void PongGame::collisionDetection()
{

	SDL_Rect playerRect=player->getRectangle();
	SDL_Rect ballRect = ball->getRectangle();


	if (SDL_HasIntersection(&playerRect, &ballRect)) {
		if (ball->directionX < 0) {
			ball->directionX *= -1;
			ball->speed += 20;
			return;
		}
	}

	SDL_Rect enemyRect = enemy->getRectangle();

	if (SDL_HasIntersection(&enemyRect, &ballRect)) {
		if (ball->directionX > 0) {
			ball->directionX *= -1;
			ball->speed += 20;
			return;
		}
	}

}

void PongGame::checkScore()
{
	if (ball->x <= 0) {

		enemyScore++;
		resetGame();
		return;
	}

	if (ball->x >= SCREEN_WIDTH)
	{
		playerScore++;
		resetGame();
		return;
		
	}

}
void PongGame::resetGame()
{
	double paddleSizeX = 15;
	double paddleSizeY = 100;
	double paddlePosY = (SCREEN_HEIGHT - paddleSizeY) / 2.0f;

	player->setPosition(0, paddlePosY);
	player->setSize(paddleSizeX, paddleSizeY);
	player->setSpeed(1000);

	enemy->setPosition(SCREEN_WIDTH - paddleSizeX, paddlePosY);
	enemy->setSize(paddleSizeX, paddleSizeY);
	enemy->setSpeed(1000);

	ball->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	ball->setSize(10, 10);
	ball->setSpeed(200);
	ball->setDirection(1, 1);

	if (playerScore==5)
	{
		score->setPosition((SCREEN_WIDTH / 2), 175);
		score->setSize(200, 200);

	}
	

	system("cls");
	std::cout << playerScore << " - " << enemyScore;
}

void PongGame::Ai()
{

	double enemyMiddlePoint = enemy->y + (enemy->height / 2.0);

	if (ball->y < enemyMiddlePoint)
	{
		enemy->setDirection(0, -1);
	}
	else
	{
		enemy->setDirection(0, 1);
	}


}
