#include "TextureManager.hpp"

class Map {
public:
	Map();
	~Map();
	void load_map(int level[20][25]);
	void draw_map();

private:
	SDL_Rect src, dest;
	SDL_Texture * dirt;
	SDL_Texture * water;
	SDL_Texture * grass;
	int map[20][25];
};