#ifndef TABLE_H
#define TABLE_H

struct table {
	Paddle** tab;
	list* fruit_list;
	list* pad;
};
typedef struct table table;

table* create_table();
void popolaTable(table* table, list* paddle);
void draw_table(table* table);
void draw_paddles(table* table);
void set_paddle(table* table, list* paddle);
void refresh_table(table* table, char move);
void move(table* table, int x_change, int y_change);
void clear_table(table* table);
int handle_limits(nodo* nodo, int x_change, int y_change);

#endif
