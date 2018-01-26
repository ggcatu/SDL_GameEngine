#pragma once

#include "SDL.h"
#include "SDL_image.h"

class Game {
public:
	Game();
	~Game();

	void init(const char * title, int x, int y, int width, int height, bool fullscreen);
	void handle_events();
	void update();
	void render();
	void clean();
	bool running() { return is_running; }
	static SDL_Renderer * renderer;
	static SDL_Event event;

private:
	SDL_Window * window;
	bool is_running;
};
