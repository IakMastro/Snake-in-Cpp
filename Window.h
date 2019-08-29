#pragma once
#include <string>
#include <SDL.h>
#include <vector>
#include "Tail.h"

class Window {

public:

	Window(const std::string &title, int width, int height);

	inline bool isClosed() const { return closed; }
	void endGame() { closed = true; }

	void pollEvents(SDL_Event &event);
	void clear() const;

	static SDL_Renderer *renderer;

	~Window();

private:

	std::string title;
	int width = 800;
	int height = 600;

	bool closed = false;

	bool init();

	SDL_Window *window = nullptr;

};