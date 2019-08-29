#pragma once
#include <SDL.h>

enum class Direction { Up, Down, Left, Right };

class Head {

public:

	Head();
	Head(int w, int h, int x, int y, int r, int g, int b, int a);

	void draw() const;

	int getX() const { return x; };
	int getY() const { return y; };

	void changeX(int speed) { this->x += speed; }
	void changeY(int speed) { this->y += speed; }

	void pollEvents(SDL_Event &event);
	void move(int SPEED, int WINDOW_WIDTH, int WINDOW_HEIGHT);

	Direction getDirection() const { return direction; };
	SDL_Rect getRect() const { return rect; }

protected:

	int w, h;
	int x, y;
	int r, g, b, a;

	Direction direction;

	mutable SDL_Rect rect;

};
