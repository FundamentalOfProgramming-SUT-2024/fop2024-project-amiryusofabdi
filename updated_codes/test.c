#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>


int main(){

    for (int i = 0; i <= 255; i++) {
        printf("ASCII value of character %c = %d\n", i, i);
    }
    return 0;
    
}