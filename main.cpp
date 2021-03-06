#include "Game.h"

const long FIXED_TIME = 20;
const int FIXED_WIDTH = 800;
const int FIXED_HEIGHT = 600;

int main(int argc, char* args[])
{
	if (Game::Instance()->init("Videjuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, FIXED_WIDTH, FIXED_HEIGHT, false)) {
		while (Game::Instance()->isRunning()) {
			long frameStart = SDL_GetTicks();
			Game::Instance()->render();
			Game::Instance()->update();
			long frameEnd = SDL_GetTicks();
			long frameTime = frameEnd - frameStart;
			if (frameTime < FIXED_TIME)
			{
				SDL_Delay((int)(FIXED_TIME - frameTime));
			}

		}
		Game::Instance()->clean();
	}
	return 0;
}
