#include "TextureManager.hpp"
#include "Game.hpp"

SDL_Texture * TextureManager::load_texture(const char* path){
	SDL_Surface * tmp_surface = IMG_Load(path);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(Game::renderer, tmp_surface);
	SDL_FreeSurface(tmp_surface);
	return texture;
}

void TextureManager::draw(SDL_Texture * texture, SDL_Rect src, SDL_Rect dst){
	SDL_RenderCopy(Game::renderer, texture, &src, &dst);
}