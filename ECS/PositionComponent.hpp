#pragma once
#include "ECS.hpp"

class PositionComponent: public Component
{
public:
	void init() override { _x = 0; _y = 0;}
	void set_pos(int xpos, int ypos){ _x = xpos; _y = ypos; };
	int x() const { return _x; };
	int y() const { return _y; };
	void update() override {_x++; _y++;};
private:
	int _x;
	int _y;
};