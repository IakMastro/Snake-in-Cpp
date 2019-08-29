#include "Score.h"
#include "Window.h"
#include <iostream>

int Text::score = 0;

Text::Text(SDL_Renderer *renderer, const std::string &fontPath, int fontSize,
	const std::string &messageText, const SDL_Color &color) :
	fontPath(fontPath), fontSize(fontSize), color(color), messageText(messageText)
{

	textTexture = loadFont(renderer, fontPath, fontSize, messageText + std::to_string(score), color);
	SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);

}

void Text::display(int x, int y, SDL_Renderer *renderer) const {

	textRect.x = x;
	textRect.y = y;
	
	textTexture = loadFont(renderer, fontPath, fontSize, messageText + std::to_string(score), color);
	SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
	SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

}

SDL_Texture *Text::loadFont(SDL_Renderer *renderer, const std::string &fontPath, int fontSize,
	const std::string &messageText, const SDL_Color &color) {

	TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (!font) {

		std::cerr << "Failed to load font. SDL_Error: " << SDL_GetError() << std::endl;

	}

	auto textSurface = TTF_RenderText_Solid(font, messageText.c_str(), color);

	if (!textSurface) {

		std::cerr << "Failed to create textSurface. SDL_Error: " << SDL_GetError() << std::endl;

	}

	auto textTexture = SDL_CreateTextureFromSurface(Window::renderer, textSurface);
	if (!textSurface) {

		std::cerr << "Failed to create textSurface. SDL_Error: " << SDL_GetError() << std::endl;

	}

	SDL_FreeSurface(textSurface);
	return textTexture;

}