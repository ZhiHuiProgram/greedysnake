HEADERS := gsnake.h
greedy_snake: *.o
	gcc -o $@ $^ -lcurses -lpthread
%.o : %.c ${HEADERS}
	gcc -c *.c 
