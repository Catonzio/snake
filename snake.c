#include "snake.h"

/*char getch() {
    char buf = 0;
    struct termios old = { 0 };
    fflush(stdout);
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    old.c_lflag    &= ~ICANON;   // local modes = Non Canonical mode
    old.c_lflag    &= ~ECHO;     // local modes = Disable echo. 
    old.c_cc[VMIN]  = 1;         // control chars (MIN value) = 1
    old.c_cc[VTIME] = 0;         // control chars (TIME value) = 0 (No time)
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0) perror("read()");
    old.c_lflag    |= ICANON;    // local modes = Canonical mode
    old.c_lflag    |= ECHO;      // local modes = Enable echo. 
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror ("tcsetattr ~ICANON");
    return buf;
 }*/

void cls() {
    int x;
    for ( x = 0; x < 5; x++ ) {
        printf("\n\n\n\n\n\n\n");
    }
}

int generate_random_number(int max) {
    int r;
    r = rand() % max;
    return r;
}

void handle_fruit(char** table, Paddle *paddle, list* fruit_list) {
    int rX, rY;
    rX = generate_random_number(X-2);
    rY = generate_random_number(Y-2);

    Paddle* fruit = malloc(sizeof(Paddle));
    fruit->x = rX;
    fruit->y = rY;

    /*
        inserire anche la cosa che il frutto non può stare dove stanno altri frutti
        capire perché ogni volta aggiunge due frutti
    */

    if(paddle->x != rX || paddle->y != rY) {
        table[rX][rY] = 'O';
        add_element(fruit_list, fruit);
    }
}



void sistema() {
    system("clear");
    srand(time(NULL));
    printf("Usage: move with WASD and exit pressing 0. Have fun!\n");
    table* table = create_table();
    list* fruit_list = create_list();
    list* paddle = create_list();
    Paddle* pad = create_paddle(INIT_X, INIT_Y, 'p');
    Paddle* pad2 = create_paddle(INIT_X+1, INIT_Y, 'p');
    Paddle* pad3 = create_paddle(INIT_X+2, INIT_Y, 'p');
    add_element(paddle, pad);
    add_element(paddle, pad2);
    add_element(paddle, pad3);
    popolaTable(table, paddle);
    char exit;
    do {
        char move;
        draw_table(table);
        scanf("%c", &move);
        if(move == '0') {
            exit = move;
            break;
        }
        refresh_table(table, move);
        printf("Length fruits: %d", list_length(fruit_list));
        system("clear");
    } while(exit != '0');
}

void prova() {
    table* table = create_table();
	list* paddle = create_list();
    

    Paddle* pad1 = create_paddle(INIT_X, INIT_Y, 'o');
    Paddle* pad2 = create_paddle(INIT_X, INIT_Y+1, 'p');
    Paddle* pad3 = create_paddle(INIT_X, INIT_Y+2, 'p');
    Paddle* pad4 = create_paddle(INIT_X, INIT_Y+3, 'p');
    Paddle* pad5 = create_paddle(INIT_X, INIT_Y+4, 'p');
    Paddle* pad6 = create_paddle(INIT_X, INIT_Y+5, 'p');


    add_element(paddle, pad1);
    add_element(paddle, pad2);
    add_element(paddle, pad3);
    add_element(paddle, pad4);
    add_element(paddle, pad5);
    add_element(paddle, pad6);
	    
	popolaTable(table, paddle);

	char exit;
    while(exit != '0') {
        draw_table(table);
        print_paddle(table->pad->head->pad);
        printf("\nMove: ");
        //scanf(" %c", &exit);
        exit = getchar();
        system("clear");
        refresh_table(table, exit);
    }
}	

void prova2() {
    char exit;
    while(exit != '0') {
        printf("Move: ");
        scanf("%c", &exit);
    }
}

void change_terminal(struct termios org_opts, struct termios new_opts) {
    int res = 0;
          //-----  store old settings -----------
    res = tcgetattr(STDIN_FILENO, &org_opts);
    assert(res==0);
          //---- set new terminal parms --------
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
}

void restore_settings(struct termios org_opts, struct termios new_opts) {
    int res;
    res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    assert(res==0);
}

int main() {
    //sistema();
    struct termios org_opts, new_opts;

    //serve per prendere gli input di continuo, senza dover premere enter
    change_terminal(org_opts, new_opts);

    prova();

    restore_settings(org_opts, new_opts);
    //prova2();
}

