#include "Head.h"
#include "Window.h"

Head::Head(){}

Head::Head(int w, int h, int x, int y, int r, int g, int b, int a) :

	w(w), h(h), x(x), y(y), r(r), g(g), b(b), a(a){}

void Head::draw() const{

	this->rect.w = w;
	this->rect.h = h;
	this->rect.x = x;
	this->rect.y = y;

	SDL_SetRenderDrawColor(Window::renderer, r, g, b, a);
	SDL_RenderFillRect(Window::renderer, &rect);

	SDL_RenderPresent(Window::renderer);

}

void Head::pollEvents(SDL_Event &event) {

	if (event.type == SDL_KEYDOWN) {

		switch (event.key.keysym.sym) {

		case SDLK_LEFT:
		case SDLK_a:

			if (direction != Direction::Right)

				direction = Direction::Left;

			break;

		case SDLK_RIGHT:
		case SDLK_d:

			if (direction != Direction::Left)

				direction = Direction::Right;

			break;

		case SDLK_UP:
		case SDLK_w:

			if (direction != Direction::Down)

				direction = Direction::Up;
				
			break;

		case SDLK_DOWN:
		case SDLK_s:

			if (direction != Direction::Up)

				direction = Direction::Down;

			break;

		default:

			break;

		}

	}

}

void Head::move(int SPEED, int WINDOW_WIDTH, int WINDOW_HEIGHT) {

	switch (direction) {

	case Direction::Down:

		if (y + SPEED == WINDOW_HEIGHT) {

			x -= SPEED;
			direction = Direction::Left;

		}

		else
			y += SPEED;

		break;

	case Direction::Up:

		if (y - SPEED == 0) {

			x += SPEED;
			direction = Direction::Right;

		}

		else
			y -= SPEED;

		break;

	case Direction::Left:

		if (x - SPEED == 0) {

			y += SPEED;
			direction = Direction::Up;

		}

		else
			x -= SPEED;

		break;

	case Direction::Right:

		if (x + SPEED == WINDOW_WIDTH) {

			y -= SPEED;
			direction = Direction::Down;

		}

		else
			x += SPEED;

		break;

	}

}