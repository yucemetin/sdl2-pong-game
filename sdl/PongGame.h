#ifndef PongGame_HEADER
#define PongGame_HEADER

#include "GameObject.h"
#include "Ball.h"
#include "score.h"
#include "EnemyScore.h"

class PongGame
{
public:
	
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 450;

	int playerScore = 0;
	int enemyScore = 0; 

	GameObject* player;
	GameObject* enemy;
	Ball* ball;
	Score* score;
	EnemyScore* enemyscr;

	void init();
	void render(SDL_Surface);

	void setPlayerDirection(double direction);
	void update(double deltaTime);

	void collisionDetection();

	void checkScore();
	void resetGame();
	void Ai();

};

#endif