#pragma once
#include "Head.h"

class Tail : public Head {

public:

	Tail(int w, int h, int x, int y, int r, int g, int b, int a);

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	void move(Head head, int PLAYER_SIZE);
	void move(Tail tail, int PLAYER_SIZE);

};