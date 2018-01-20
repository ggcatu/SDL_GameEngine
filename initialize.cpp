#include "Game.hpp"
#include <iostream>

using namespace std;

Game * game = NULL;

int main(int argc, char * argv[]){

	game = new Game();

	const int FPS = 60;
	const int frame_delay = 1000 / 60;
	Uint32 frame_start, frame_time = 0;

	game->init("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while( game->running() ){
		frame_start = SDL_GetTicks();

		game->handle_events();
		game->update();
		game->render();

		frame_time = SDL_GetTicks() - frame_start;
		if (frame_time < frame_delay){
			SDL_Delay( frame_delay - frame_time );
		}
	}

	return 0;
}