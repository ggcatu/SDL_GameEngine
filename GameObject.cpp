#include "GameObject.hpp"

GameObject::GameObject(const char * texture, int posx, int posy){
	x = posx;
	y = posy;
	obj_texture = TextureManager::load_texture(texture);

	source_rect.h = 32;
	source_rect.w = 32;
	source_rect.x = source_rect.y = 0;

	dest_rect.h = source_rect.h * 2;
	dest_rect.w = source_rect.w * 2;
}

void GameObject::update(){ 
	dest_rect.x = x++;
	dest_rect.y = y++;
};

void GameObject::render(){
	SDL_RenderCopy(Game::renderer, obj_texture, NULL, &dest_rect);
};