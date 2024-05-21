#include"gsnake.h"
#include<stdlib.h>
#include<unistd.h>
#include<curses.h>
extern snake_link snake_h;
extern int score;
extern snake_link snake_t;
void initcurses(){
    initscr();
    keypad(stdscr,1);
}
void *pic_ref(){
    while(1){
       gamepic(snake_h);
       snake_move();
       usleep(200000);
       refresh();
    }

}
void gamepic(node *snake){
    int row,array,ret,x,y;
    node  *p;
    p=snake;
    move(0,0);
    for(row=0;row<=21;row++){
        if(row == 0 || row == 20){
           for(array=0;array<20;array++){
             printw("--");
           }
        }else if(row == 21){
            printw("author:zhang score:%d",score);    
        }else{
           for(array=0;array<=20;array++){
               if(array == 0 || array == 20){
               printw("|");
               }
               else if(snake_pos(p,row,array)){
                   printw("[]");
               }else if(food_pos(row , array)){
                   printw("()");   
               }else{
                   printw("  ");
               }
           }
        }
        printw("\n");
    }
}

