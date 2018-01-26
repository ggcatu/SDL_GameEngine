#pragma once
#include "Components.hpp"
#include "TextureManager.hpp"
#include "SDL.h"

class TileComponent : public Component {
public:
    PositionComponent * position;
    SpriteComponent * sprite;
    SDL_Rect tileRec;
    int id;
    char * path;

    TileComponent() = default;

    TileComponent(int x, int y, int h, int w, int id){
        tileRec.x = x;
        tileRec.y = y;
        tileRec.h = h;
        tileRec.w = w;
        this.id = id;

        switch (id){
            case 0:
                path = "assets/dirty.png";
                break;
            case 1:
                path = "assets/water.png";
                break;
            case 2:
                path = "assets/grass.png";
                break;
        }

    }

    ~TileComponent();

    void init() override {
        position = entity->add_component<PositionComponent>(tileRec.x, tileRec.y);
        sprite = entity->add_component<SpriteComponent>(path)
    };

};
