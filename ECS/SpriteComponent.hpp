#include "Components.hpp"
#include "../TextureManager.hpp"
#include <iostream>

#define DEFAULT_VALUE 32
class SpriteComponent : public Component {
private:
	PositionComponent * position;
	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;

public:
	int height;
	int width;
	int scale;

	void init() override{
		position = &entity->get_component<PositionComponent>();
		width = position->width;
		height = position->height;

		srcRect.x = srcRect.y = 0;

		destRect.h = height * this->scale;
		destRect.w = width * this->scale;
		std::cout << "Sprite initialized \n";
	};

	void draw() override{
		TextureManager::draw(texture, srcRect, destRect);
	};

	void update() override{
		destRect.x = position->x();
		destRect.y = position->y();
	};

	void setTex(const char * path){
		texture = TextureManager::load_texture(path);
	};

	SpriteComponent(const char * path){
		setTex(path);
		this->scale = 1;
		srcRect.w = DEFAULT_VALUE;
		srcRect.h = DEFAULT_VALUE;

	};

	SpriteComponent(const char * path, int s, int w, int h){
		setTex(path);
		this->scale = s;
		srcRect.w = w;
		srcRect.h = h;
	};

	~SpriteComponent(){};
};
