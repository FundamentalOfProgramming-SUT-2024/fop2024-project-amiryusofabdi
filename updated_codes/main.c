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
int menu_phase = 0;



// Functions

#include "welcomepage.h"
#include "signupsigninpage.h"

#include "signup.h"
#include "signin.h"


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

        if ( signin_phase ){
            signin_page();
        }

        if ( menu_phase ){
            printw("fesfs");
        }

        refresh();
    }


    endwin();
    return 0;
}