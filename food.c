#include"gsnake.h"
#include<stdlib.h>
extern food sfood;
void foodinit(){
    sfood.column=((rand()%19)+1);
    sfood.row=((rand()%19)+1);
}
int food_pos(int i,int j){
 //   food *p;
 //   p=&sfood;
    if(sfood.row == i && sfood.column == j){
        return 1;
    }
    return 0;
}
