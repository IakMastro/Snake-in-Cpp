#include "Tail.h"

Tail::Tail(int w, int h, int x, int y, int r, int g, int b, int a){

	Head();
	this->w = w;
	this->h = h;
	this->x = x;
	this->y = y;
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;

}

void Tail::move(Head head, int PLAYER_SIZE) {

	switch (head.getDirection()) {

	case Direction::Up:
		
		if (this->direction == Direction::Up) {

			this->y = head.getY() + PLAYER_SIZE;
			this->direction = head.getDirection();

		}
		else {

			this->x = head.getX();
			this->direction = head.getDirection();

		}
		
		break;

	case Direction::Down:

		if (this->direction == Direction::Down) {

			this->y = head.getY() - PLAYER_SIZE;
			this->direction = head.getDirection();

		}
		else {

			this->x = head.getX();
			this->direction = head.getDirection();

		}

		break;

	case Direction::Right:

		
		if (this->direction == Direction::Right) {

			this->x = head.getX() - PLAYER_SIZE;
			this->direction = head.getDirection();

		}
		else {

			this->y = head.getY();
			this->direction = head.getDirection();

		}

		break;

	case Direction::Left:

		if (this->direction == Direction::Left) {

			this->x = head.getX() + PLAYER_SIZE;
			this->direction = head.getDirection();

		}
		else {

			this->y = head.getY();
			this->direction = head.getDirection();

		}

		break;

	default:

		break;

	}


}

void Tail::move(Tail tail, int PLAYER_SIZE) {

	switch (tail.getDirection()) {

	case Direction::Up:

		if (this->direction == Direction::Up) {

			this->y = tail.getY();
			this->direction = tail.getDirection();

		}
		else {

			this->x = tail.getX();
			this->direction = tail.getDirection();

		}

		break;

	case Direction::Down:

		if (this->direction == Direction::Down) {

			this->y = tail.getY();
			this->direction = tail.getDirection();

		}
		else {

			this->x = tail.getX();
			this->direction = tail.getDirection();

		}

		break;

	case Direction::Right:


		if (this->direction == Direction::Right) {

			this->x = tail.getX();
			this->direction = tail.getDirection();

		}
		else {

			this->y = tail.getY();
			this->direction = tail.getDirection();

		}

		break;

	case Direction::Left:

		if (this->direction == Direction::Left) {

			this->x = tail.getX();
			this->direction = tail.getDirection();

		}
		else {

			this->y = tail.getY();
			this->direction = tail.getDirection();

		}

		break;

	default:

		break;

	}

}
