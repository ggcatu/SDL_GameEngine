#pragma once

#include "SDL.h"
#include "Game.hpp"

class TextureManager {
public:
	TextureManager();
	~TextureManager();
	static SDL_Texture * load_texture(const char* path);
	static void draw(SDL_Texture * texture, SDL_Rect src, SDL_Rect dst);
    static void draw_rectangle(SDL_Rect rect);
};
