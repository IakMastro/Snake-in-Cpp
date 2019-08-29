#pragma once
#include <SDL.h>

class Food {

public:

	Food(int w, int h, int x, int y, int r, int g, int b, int a);

	void draw() const;

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	int getX() const { return x; }
	int getY() const { return y; }

	SDL_Rect getRect() const { return rect; }

protected:

	int w, h;
	int x, y;
	int r, g, b, a;

	mutable SDL_Rect rect;

};