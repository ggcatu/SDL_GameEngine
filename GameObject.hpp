#include "SDL.h"
#include "TextureManager.hpp"
#include "Game.hpp"

class GameObject {
public:
	GameObject(const char * texture, int posx, int posy);
	~GameObject();

	void update();
	void render();

private:
	int x;
	int y;

	SDL_Rect dest_rect, source_rect;
	SDL_Texture * obj_texture;
};