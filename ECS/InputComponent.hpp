#include "SDL.h"
#include "ECS.hpp"
#include "../Game.hpp"
#include <iostream>

class InputComponent : public Component {
public:
    SDL_Event event;

    const Uint8 *keys;
    PositionComponent *transform;

    InputComponent(){};
    ~InputComponent(){};

    void init() override{
        transform = &entity->get_component<PositionComponent>();
    }
    void update() override{
        if (Game::event.type == SDL_KEYDOWN){
            switch (Game::event.key.keysym.sym){
                case SDLK_w:
                    transform->velocity.y = -1.0f;
                    break;
                case SDLK_s:
                    transform->velocity.y = 1.0f;
                    break;
                case SDLK_a:
                    transform->velocity.x = -1.0f;
                    break;
                case SDLK_d:
                    transform->velocity.x = 1.0f;
                    break;
                default:
                    break;
            }
        }

        if (Game::event.type == SDL_KEYUP){
            switch (Game::event.key.keysym.sym){
                case SDLK_w:
                    transform->velocity.y = 0;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;
                case SDLK_a:
                    transform->velocity.x = 0;
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    break;
                default:
                    break;
            }

        }
    };
};
