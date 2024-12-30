#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>

// Phases
int welcome_phase = 0;      // !!!!!!!!!!!
int signup_or_signin_phase = 1;  //!!!!!!!!!!
int signup_phase = 0;
int signin_phase = 0;
int guest_phase = 0;



// Functions

#include "welcomepage.h"
#include "signupsigninpage.h"



int username_dne(char username[]){

    FILE* fptr;
    fptr = fopen("data.txt","r");

    char dataToBeRead[1000];

    while (fgets(dataToBeRead, 1000, fptr) != NULL){

        if ( !strcmp(dataToBeRead,username) ){
            return 0;
        }
        
    }

    return 1;   

}

int valid_username( char username[] ){

    int len = strlen(username);
    int uppercase = 0, lowercase = 0, digit = 0;

    if (len < 7){
        return 0;
    }

    if ( !username_dne(username) ){
        return 0;
    }

    for (int i=0; i < len; i++){

        if ( 'a' <= username[i] && username[i] <= 'z' ){
            lowercase = 1;
        }
        
        if ( 'A' <= username[i] && username[i] <= 'Z' ){
            uppercase = 1;
        }

        if ( '0' <= username[i] && username[i] <= '9' ){
            digit = 1;
        }

    }

    if ( ! (digit && uppercase && lowercase) ){
        return 0;
    }


    return 1;

}

void new_acc(char username[],char password[],char email[]){

    FILE* fptr;
    fptr = fopen("data.txt","a");

    fprintf(fptr,"%s\n%s\n%s\n",username,password,email);


}

#include "signup.h"

// Main
int main(){

    initscr();
    curs_set(0);
    time_t begin = time(NULL);
    keypad(stdscr,TRUE);

    while (1){

        time_t now = time(NULL);

        // if ( welcome_phase ){
        //     welcome_page(begin,now);
        // }

        if ( signup_or_signin_phase ){
            signup_or_signin_page();
        }

        if ( signup_phase ){
            signup_page();
        }

        refresh();
    }


    endwin();
    return 0;
}