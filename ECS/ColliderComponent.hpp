#pragma once
#include "Components.hpp"
#include "SDL.h"
#include "../TextureManager.hpp"
#include <iostream>

class ColliderComponent : public Component {
public:
    SDL_Rect collider;
    Vector2D offset;
    Vector2D dim;
    SpriteComponent * sprite;
    bool color;

    ColliderComponent(int h, int w, bool color){
        this->color = color;
        collider.h = h;
        collider.w = w;
    };

    ColliderComponent(bool color){
        collider.h = 0;
        collider.w = 0;
        this->color = color;
    }

    ~ColliderComponent(){};

    void init() override {
        if (! entity->has_component<SpriteComponent>() )
            std::cout << "Collider cannot find sprite \n";

        sprite = &entity->get_component<SpriteComponent>();

        if (collider.h == 0)
        collider.h = sprite->height * sprite->scale;

        if (collider.w == 0)
        collider.w = sprite->width * sprite->scale;
    }

    void update() override {
        collider.x = entity->get_component<PositionComponent>().x() + offset.x;
        collider.y = entity->get_component<PositionComponent>().y() + offset.y;
    }

    void draw() override {
        if(color)
        TextureManager::draw_rectangle(collider);
    }
};
