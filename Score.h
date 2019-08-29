#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include <string>

class Text {

public:

	Text(SDL_Renderer *renderer, const std::string &fontPath, int fontSize, const std::string &messageText, const SDL_Color &color);

	void display(int x, int y, SDL_Renderer *renderer) const;

	static SDL_Texture *loadFont(SDL_Renderer *renderer, const std::string &fontPath, int fontSize,
		const std::string &messageText, const SDL_Color &color);

	static int score;

private:

	mutable SDL_Texture *textTexture = nullptr;

	const std::string fontPath;
	int fontSize;
	std::string messageText;
	const SDL_Color color;

	mutable SDL_Rect textRect;

};