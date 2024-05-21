#include"gsnake.h"
#include<pthread.h>
#include"curses.h"
extern snake_link snake_h;
extern snake_link snake_t;
extern int score;
int enter;
int main(){
    initcurses();
    while(enter != 'y'){
        enter = getch();
        move(6,6);
        printw("enter y:start paly");
        refresh();
    }
    snakeinit();
    foodinit();
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t2,NULL,key_scanf,NULL);
    pthread_create(&t1,NULL,pic_ref,NULL);
    while(enter != 'n'){
        enter = getch();
    }
    getch();
    endwin();
    return 0;
}
