#include <iostream>
#include <vector>
#include "Window.h"
#include "Head.h"
#include "Score.h"
#include "Tail.h"
#include "Food.h"
#include <time.h>

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 600
#define PLAYER_SIZE 20
#define R 255
#define G 255
#define B 255
#define A 255
#define FPS 25

const int TICKS_PER_FRAME = 1000 / FPS;
int SPEED = 5;
int tailColor = 0;

void foodCollision(SDL_Rect headRect, SDL_Rect foodRect, Head &head, std::vector<Tail> &tails, Text &score, Food &food) {

	if (SDL_HasIntersection(&headRect, &foodRect)) {

		srand(time(NULL));

		food.setX(rand() % WINDOW_WIDTH - 40);
		food.setY(rand() % WINDOW_HEIGHT - 40);

		score.score += 5;

		if (SPEED <= 15) {

			SPEED += 1;
			std::cout << "Speed is: " << SPEED << std::endl;

		}

		switch (head.getDirection()) {

		case Direction::Up:

			tails.emplace_back(PLAYER_SIZE, PLAYER_SIZE, tails[tails.size() - 1].getX(),
				tails[tails.size() - 1].getY() - 20, R - tailColor, G - tailColor, B - tailColor, A - tailColor);
			break;

		case Direction::Down:

			tails.emplace_back(PLAYER_SIZE, PLAYER_SIZE, tails[tails.size() - 1].getX(),
				tails[tails.size() - 1].getY() - 20, R - tailColor, G - tailColor, B - tailColor, A - tailColor);
			break;

		case Direction::Right:

			tails.emplace_back(PLAYER_SIZE, PLAYER_SIZE, tails[tails.size() - 1].getX() - 20,
				tails[tails.size() - 1].getY(), R - tailColor, G - tailColor, B - tailColor, A - tailColor);
			break;

		case Direction::Left:

			tails.emplace_back(PLAYER_SIZE, PLAYER_SIZE, tails[tails.size() - 1].getX() + 20,
				tails[tails.size() - 1].getY(), R - tailColor, G - tailColor, B - tailColor, A - tailColor);
			break;

		default:

			break;

		}

		tailColor ++;

		std::cout << "Tails sum: " << tails.size() << std::endl;

	}

}

void tailCollision(SDL_Rect headRect, SDL_Rect tailRect, Window &window) {

	if (SDL_HasIntersection(&headRect, &tailRect)) {

		window.endGame();
		std::cout << "You touched the tail!" << std::endl;

	}

}

void renderGame(Window &window, Head &head, std::vector<Tail> &tails, Text &score, Food &food) {

	SDL_Rect tailRect[100];

	for (int i = 0; i < tails.size(); i++)
		tails[i].draw();

	head.draw();
	food.draw();
	score.display(20, 20, Window::renderer);
	window.clear();

}

void pollEvents(Window &window, Head &head, std::vector<Tail> &tails) {

	SDL_Event event;

	if (SDL_PollEvent(&event)) {

		head.pollEvents(event);
		window.pollEvents(event);

	}

}

int main(int argc, char **argv) {

	srand(time(NULL));

	std::cout << "Launching the game please wait...." << std::endl;
	std::cout << "Speed is: " << SPEED << std::endl;

	Window window("Snake Game", WINDOW_WIDTH, WINDOW_HEIGHT);
	Head head(PLAYER_SIZE, PLAYER_SIZE, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, !R, !G, B, A);
	std::vector<Tail>tails;
	Text score(Window::renderer, "res/arial.ttf", 30, "Score: ", { R, !G, !B, A });
	Food food(PLAYER_SIZE / 2, PLAYER_SIZE / 2, rand() % 10 + WINDOW_WIDTH - 40, 
		rand() % WINDOW_HEIGHT - 40, R, !G, B, A);

	tails.emplace_back(PLAYER_SIZE, PLAYER_SIZE, WINDOW_WIDTH / 2 - 20, WINDOW_HEIGHT / 2, 
		R - tailColor, G - tailColor, B - tailColor, A - tailColor);
	tailColor ++;

	Uint32 startingTick;

	while (!window.isClosed()) {

		startingTick = SDL_GetTicks();

		pollEvents(window, head, tails);

		renderGame(window, head, tails, score, food);

		foodCollision(head.getRect(), food.getRect(), head, tails, score, food);

		for(int i = 5; i < tails.size(); i++)
			tailCollision(head.getRect(), tails[i].getRect(), window);

		head.move(SPEED, WINDOW_WIDTH - 20, WINDOW_HEIGHT - 20);

		for (int i = tails.size() - 1; i > 0; i--)
			tails[i].move(tails[i - 1], PLAYER_SIZE);
		tails[0].move(head, PLAYER_SIZE);

		if (TICKS_PER_FRAME > SDL_GetTicks() - startingTick) {

			SDL_Delay(TICKS_PER_FRAME - (SDL_GetTicks() - startingTick));

		}
			
	}

	std::cout << "Game Over! Thanks for playing! Your score was: " << score.score << std::endl;

	return 1;
		
}