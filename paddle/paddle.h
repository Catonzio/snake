#ifndef PADDLE_H
#define PADDLE_H

struct paddle {
	int x;
	int y;
	char sign;
};
typedef struct paddle Paddle;

/*struct paddle_list {
	list* paddles;
	int count;
};
typedef struct paddle_list paddle_list;*/

void print_paddle(Paddle* paddle);
Paddle* create_paddle(int x, int y, char sign);
int equals_paddle(Paddle* p1, Paddle* p2);

#endif