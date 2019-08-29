#include "Window.h"
#include <SDL_ttf.h>
#include <iostream>

SDL_Renderer * Window::renderer = nullptr;

Window::Window(const std::string &title, int width, int height) :

	title(title), width(width), height(height) {

	closed = !init();

}

Window::~Window() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();

}

bool Window::init() {

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {

		std::cerr << "Failed to initiliaze SDL. SDL_Error: " << SDL_GetError() << std::endl;
		return false;

	}

	if (TTF_Init() == -1) {

		std::cerr << "Failed to initiliaze SDL_ttf. SDL_Error: " << SDL_GetError() << std::endl;
		return false;

	}

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height, 0);

	if (window == nullptr) {

		std::cerr << "Failed to create window. SDL_Error: " << SDL_GetError() << std::endl;
		return false;

	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (window == nullptr) {

		std::cerr << "Failed to create renderer. SDL_Error: " << SDL_GetError() << std::endl;
		return false;

	}

	return true;

}

void Window::pollEvents(SDL_Event &event) {

	switch (event.type) {

	case SDL_QUIT:

		closed = true;
		break;

	case SDL_KEYDOWN:

		if (event.key.keysym.sym == SDLK_ESCAPE)
			closed = true;

	default:

		break;

	}

}

void Window::clear() const{

	SDL_RenderPresent(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

}