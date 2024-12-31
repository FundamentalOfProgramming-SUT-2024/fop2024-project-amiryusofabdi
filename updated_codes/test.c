#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>

char str[4] = "000-";

char* Int2String(int num){
    
    
    int index = 2;

    while (num > 0){
        str[index] = (char) ('0'+ num%10);
        index --;
        num /= 10;
    }

    return str;

}


int main(){
    srand(time(NULL));
    int num = rand()%1000;

    char* st = Int2String(num);

    printf("%d    %s\n",num,st);


    return 0;
}