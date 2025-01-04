#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>

int username_isok(char username[]){                     

    FILE *fptr;
    fptr = fopen("usernames.txt","r");


    char str[100];
    char newstr[100];

    

    while ( fgets(str,100,fptr) ){
        
        for (int i = 4; i < strlen(str)-1; i++){
            newstr[i-4] = str[i];
        }
        
        newstr[strlen(str)-5] = '\0';

        if ( strcmp(newstr,username) == 0 ){
            return 0;
        }

    }

    return 1;
}

int main(){

    char username[100];
    scanf("%s",username);
    printf("---------\n");
    printf("%d\n",username_isok(username));

    return 0;
}