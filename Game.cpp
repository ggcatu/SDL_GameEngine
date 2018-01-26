#include <iostream>
#include <iostream>
#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "Collision.hpp"
#include "ECS/Components.hpp"

using namespace std;


Map * map = NULL;
Manager manager;
Entity& newPlayer = manager.add_entity();
Entity& rock = manager.add_entity();

Game::Game(){};
Game::~Game(){};

SDL_Event Game::event;
SDL_Renderer* Game::renderer = NULL;

void Game::init(const char * title, int x, int y, int width, int height, bool fullscreen){
	int flags = 0 ;
	if ( fullscreen ){
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if ( SDL_Init( SDL_INIT_EVERYTHING ) == 0 ){
		cout << "Correct initialization." << endl;

		window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (window){ cout << "Windows created correctly." << endl;}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer){
			cout << "Renderer created correctly." << endl;
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		}
		is_running = true;

		map = new Map();

		newPlayer.add_component<PositionComponent>(0,0, 32, 32);
		newPlayer.add_component<SpriteComponent>("assets/player.png", 2, 240, 260);
		newPlayer.add_component<InputComponent>();
		newPlayer.add_component<ColliderComponent>(false);

		rock.add_component<PositionComponent>(160,160);
		rock.add_component<ColliderComponent>(40,40,true);

	} else {
		is_running = false;
	}
}

void Game::handle_events(){
	SDL_PollEvent(&event);
	switch(event.type){
		case SDL_QUIT:
			is_running = false;
			break;
		default:
			break;
	}
}

int cnt = 1;
void Game::update(){
	manager.refresh();
	manager.update();

	// cout << newPlayer.get_component<PositionComponent>().x() << " " << newPlayer.get_component<PositionComponent>().y() << endl;

	if ( Collision::AABB(newPlayer.get_component<ColliderComponent>().collider,
						 rock.get_component<ColliderComponent>().collider))
		std::cout << "Colision detectada \n";
}

void Game::render(){
	SDL_RenderClear(renderer);

	map->draw_map();
	manager.draw();

	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
