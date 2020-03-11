#include "../snake.h"

table* create_table() {
	int i;
	table* table = malloc(sizeof(table));
    Paddle** tab = calloc(X, sizeof(Paddle*));
    for(i=0;i<X;i++) {
        tab[i] = calloc(Y, sizeof(Paddle));
    }
    table->tab = tab;
    table->fruit_list = create_list();
    table->pad = create_list();
    return table;
}

void add_element_table(table* table, Paddle* pad) {

}

void draw_table(table* table) {
	int i,j;
    for(i=0;i<X;i++) {
        for(j=0;j<Y;j++) {
            printf("%c", table->tab[i][j].sign);
            if(j==Y-1)
                printf("\n");
        }
    }
}

void set_paddle(table* table, list* paddle) {
	nodo* it = paddle->head;
    while(it!=NULL) {
        table->pad = add_element(table->pad, it->pad);
        it = it->next;
    }
}

void draw_paddles(table* table) {
    nodo* it = table->pad->head;
    while(it != NULL) {
        table->tab[it->pad->y][it->pad->x].sign = it->pad->sign;
        it = it->next;
    }
}

void popolaTable(table* table, list* paddle) {
    int i,j;
    for(i=0;i<X;i++) {
        for(j=0;j<Y;j++) {
            //bordo superiore ed inferiore
            if((i==0||i==X-1) && (j!=0 && j!=Y-1)) {
                table->tab[i][j].sign = '-';
            }
                //bordi laterali
            else if((i!=0 && i!=X-1) && (j==0 || j==Y-1)) {
                table->tab[i][j].sign = 'I';
            }
                //angolo in basso a sx
            else if(i==X-1 && j==0) {
                table->tab[i][j].sign = 'L';
            }
                //angolo in alto a sx
            else if(i==0 && j==0) {
                table->tab[i][j].sign = '#';
            }
                //angolo in alto a dx
            else if(i == 0) {
                table->tab[i][j].sign = ']';
            }
                //angolo in basso a dx
            else if(i == X - 1) {
                table->tab[i][j].sign = ']';
            }
            
            else
                table->tab[i][j].sign = ' ';
        }
    }
	set_paddle(table, paddle);
    draw_paddles(table);
}

//DA CONTROLLARE BENE
int handle_limits(nodo* nodo, int x_change, int y_change) {
    int x = nodo->pad->x + x_change;
    int y = nodo->pad->y + y_change;
    int onLimit = 0;
    if(x == Y-2) {
        nodo->pad->x = 1;
        onLimit = 1;
    }
    if(x == 0) {
        nodo->pad->x = Y-2;
        onLimit = 1;
    }
    if(y == X-2) {
        nodo->pad->y = 1;
        onLimit = 1;
    }
    if(y == 0) {
        nodo->pad->y = X-2;
        onLimit = 1;
    }
    return onLimit;
}

void move(table* table, int x_change, int y_change) {
    nodo* last = table->pad->last;
    //fino a che non è il primo
    while(!equals_nodes(table->pad->head, last)) {
        if(!handle_limits(table->pad->head, x_change, y_change)) {
            last->pad->x = last->prev->pad->x;
            last->pad->y = last->prev->pad->y;
            last = last->prev;
        }
    }
    //adesso che è l'head
    if(equals_nodes(table->pad->head, last)) {
        if(!handle_limits(table->pad->head, x_change, y_change)) {
            last->pad->x = last->pad->x + x_change;
            last->pad->y = last->pad->y + y_change;
        }
    }
}

void clear_table(table* table) {
    nodo* it = table->pad->head;
    while(it != NULL) {
        table->tab[it->pad->y][it->pad->x].sign = ' ';
        it = it->next;
    }
}

void refresh_table(table* table, char choose) {
    int old_x = table->pad->head->pad->x;
    int old_y = table->pad->head->pad->y;
    clear_table(table);
    if(choose == 'w') {
        move(table, 0, -1);
    }
    if(choose == 'a') {
        move(table, -1, 0);
    }
    if(choose == 's') {
        move(table, 0, 1);
    }
    if(choose == 'd') {
        move(table, 1, 0);
    }
    draw_paddles(table);
}