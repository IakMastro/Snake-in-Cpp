#include "Food.h"
#include "Window.h"

Food::Food(int w, int h, int x, int y, int r, int g, int b, int a) :

	w(w), h(h), x(x), y(y), r(r), g(g), b(b), a(a) {}

void Food::draw() const {

	this->rect.w = w;
	this->rect.h = h;
	this->rect.x = x;
	this->rect.y = y;

	SDL_SetRenderDrawColor(Window::renderer, r, g, b, a);
	SDL_RenderFillRect(Window::renderer, &rect);

	SDL_RenderPresent(Window::renderer);

}