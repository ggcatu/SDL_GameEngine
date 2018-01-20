#include "Components.hpp"
#include "../TextureManager.hpp"
#include <iostream>

class SpriteComponent : public Component {
private:
	PositionComponent * position;
	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;
public:
	void init(){
		position = &entity->get_component<PositionComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = 240; 
		srcRect.h = 260;
		destRect.h = destRect.w = 64;
	};

	void draw(){
		TextureManager::draw(texture, srcRect, destRect);

	};

	void update(){
		destRect.x = position->x();
		destRect.y = position->y();
	};

	void setTex(const char * path){
		texture = TextureManager::load_texture(path);
	};

	SpriteComponent(const char * path){
		setTex(path);
	};

	~SpriteComponent(){};
};