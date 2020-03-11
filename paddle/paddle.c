#include "../snake.h"

void print_paddle(Paddle* paddle) {
	if(!(paddle == NULL))
		printf("Paddle [%d;%d]: %c", paddle->x, paddle->y, paddle->sign);
	else {
		printf("Paddle NULL");
	}
}

Paddle* create_paddle(int x, int y, char sign) {
	Paddle* pad = malloc(sizeof(Paddle));
	pad->x = x;
	pad->y = y;
	pad->sign = sign;
	return pad;
}

int equals_paddle(Paddle* p1, Paddle* p2) {
	return p1->x == p2->x && p1->y == p2->y;
}