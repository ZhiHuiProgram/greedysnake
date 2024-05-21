#include"gsnake.h"
#include<stdlib.h>
#include<curses.h>
#define initrow 1
#define initcolumn 1
#define DOWN 1
#define UP 2
#define LEFT 5
#define RIGHT 6
int dir,con,tran,score=0;
food sfood;
snake_link snake_h;
snake_link snake_t;
void turn(){
    if(tran-dir!=1&&tran-dir!=-1){
        tran = dir;
    }
}
void *key_scanf(){
    while(1){
        con = getch();
        switch(con){
            case KEY_DOWN:
                dir = DOWN;
                turn();
                break;
            case KEY_UP:
                dir = UP;
                turn();
                break;
            case KEY_RIGHT:
                dir = RIGHT;
                turn();
                break;
            case KEY_LEFT:
                dir = LEFT;
                turn();
                break;
        }
    }    
}
void add_snake(){
    snake_link q;
    q = (snake_link)malloc(sizeof(node));
    switch(tran){
        case UP:
            q->row = snake_t->row-1;
            q->column = snake_t->column;
            break;
        case DOWN:
            q->row = snake_t->row+1;
            q->column = snake_t->column;
            break;
        case RIGHT:
            q->row = snake_t->row;
            q->column = snake_t->column+1;
            break;
        case LEFT:
            q->row = snake_t->row;
            q->column = snake_t->column-1;
            break;
        default:
            break;
    }   
    q->next = NULL;
    snake_t->next = q;
    snake_t = q;
}
void snake_move(){
    snake_link p;
    add_snake();
    if(snake_t->row == sfood.row && snake_t->column == sfood.column){
        score=score+1;
        sfood.row=((rand()%19)+1);
        sfood.column=((rand()%19)+1);
    }else{
        del_snake();
    }
    if(snake_t->row == 0 || snake_t->row == 20 || snake_t->column ==0 ||snake_t->column == 20){
        snakeinit();
        foodinit();
        score = 0;
    }
    p=snake_h;
    while(p->next!=NULL){
        if(p->row == snake_t->row && p->column == snake_t->column){
           snakeinit();
           foodinit();
           score = 0;
           break;
        }
        p = p->next;
    }
}
void snakeinit(){
    snake_link p ;
    tran = RIGHT;
    while(snake_h != NULL){
        p=snake_h;
        snake_h = snake_h->next;
        free(p);
    }
    snake_h = (snake_link)malloc(sizeof(node));
    snake_h->row = initrow;
    snake_h->column = initcolumn;
    snake_h->next = NULL;
    snake_t = snake_h;
    add_snake();
    add_snake();
}
void del_snake(){
    snake_link p;
    p=snake_h;
    snake_h = snake_h->next;
    free(p);
}
int snake_pos(node *snake,int i,int j){
     node *p;
     p=snake;
     while(p != NULL){
         if(p->row == i && p->column ==j){
             return 1;
         }
         p=p->next;
     }
     return 0;
 }  
