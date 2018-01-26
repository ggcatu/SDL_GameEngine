#pragma once
#include "ECS.hpp"
#include "../Vector2D.hpp"

#define DEFAULT_VALUE 32

class PositionComponent: public Component {
public:
    PositionComponent(){
        position.x = 0;
        position.y = 0;
        this->width = DEFAULT_VALUE;
        this->height = DEFAULT_VALUE;
    };

    PositionComponent(int x, int y){
        position.x = x;
        position.y = y;
        this->width = DEFAULT_VALUE;
        this->height = DEFAULT_VALUE;
    };

    PositionComponent(int x, int y, int width, int height){
        position.x = x;
        position.y = y;
        this->width = width;
        this->height = height;
    };
	void init() override {}
    void set_pos(int xpos, int ypos){ position.x = xpos, position.y = ypos; };
	void set_vel(int xpos, int ypos){ velocity.x = xpos, velocity.y = ypos; };
	int x() const { return position.x; };
	int y() const { return position.y; };
	void update() override {position += velocity;};
    Vector2D velocity;
    int width;
    int height;
private:
    Vector2D position;
};
