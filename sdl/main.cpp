#include<iostream>
#include<SDL.h>
#include"GameObject.h"
#include"PongGame.h"
#include<time.h>

using namespace std;

SDL_Window* window;
SDL_Surface* surface;
PongGame* pongGame;

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("TOP ATMACA", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, PongGame::SCREEN_WIDTH, PongGame::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	surface = SDL_GetWindowSurface(window);

	pongGame = new PongGame();
	pongGame->init();

	bool quit = false;
	SDL_Event event;

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTtime = 0;

	srand(time(NULL));

	float r = 0;
	float g = 125;
	float b = 200;
	float random;

	while (!quit)	
	{


		while (SDL_PollEvent(&event)!=0)
		{
			if (event.type==SDL_QUIT)
			{	
				quit = true;
			}

			const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
			if (keyboardState[SDL_SCANCODE_ESCAPE])
			{
				quit = true;
			}

			

			if (keyboardState[SDL_SCANCODE_UP])
			{
				pongGame->setPlayerDirection(-1);
			}

			else if (keyboardState[SDL_SCANCODE_DOWN])
			{
				pongGame->setPlayerDirection(1);
			}

			else
			{
				pongGame->setPlayerDirection(0);
			}

		}

		

		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTtime = (NOW - LAST) / (double)SDL_GetPerformanceFrequency();
		

		Uint32 backgroundColor = SDL_MapRGB(surface->format, r,g,b);
		SDL_FillRect(surface, NULL, backgroundColor);

		if (pongGame->playerScore<5)
		{
			pongGame->update(deltaTtime);
			
		}
		else {
			Uint32 backgroundColor = SDL_MapRGB(surface->format, 0, 255, 0);
			SDL_FillRect(surface, NULL, backgroundColor);
		}
		
		pongGame->render(*surface);
		
		r++;
		g++;
		b++;
		

		SDL_UpdateWindowSurface(window);


		
	}

	SDL_DestroyWindow(window);
	SDL_FreeSurface(surface);


	window = NULL;
	surface = NULL;

	return 0;

}