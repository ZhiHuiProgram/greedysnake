#ifndef __SNAKE_H__
#define __SNAKE_H_
typedef struct csnake{
    int row;
    int column;
    struct csnake *next;
}node,*snake_link;
typedef struct gfood{
    int row;
    int column;
 
}food;
void initcurses();
void gamepic(node *snake);
int snake_pos(snake_link snake, int i,int j);
void snakeinit();
void snake_move();
void *key_scanf();
void *pic_ref();
void foodinit();
void del_snake();
void turn();
int food_pos(int i ,int j);
void add_snake();
#endif
