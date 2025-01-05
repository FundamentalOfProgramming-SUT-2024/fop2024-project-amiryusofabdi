#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>

// Phases
int welcome_phase = 1;      
int signup_or_signin_phase = 0; 
int signup_phase = 0;
int signin_phase = 0;
int guest_phase = 0;
int menu_phase = 1;
int newgame_hover = 1;
int continue_prevgame_hover = 0;
int scoreboard_hover = 0;
int profile_hover = 0;
int setting_hover = 0;
int newgame_phase = 0;
int continue_prevgame_phase = 0;
int scoreboard_phase = 0;
int profile_phase = 0;
int setting_phase = 0;
int room_count;


// BOARD

char** board;

// Functions

#include "welcomepage.h"
#include "signupsigninpage.h"

#include "signup.h"
#include "signin.h"
#include "menu.h"
#include "newgame.h"


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

        // if ( signup_or_signin_phase ){
        //     signup_or_signin_page();
        // }

        // if ( signup_phase ){
        //     signup_page();
        // }

        // if ( signin_phase ){
        //     signin_page();
        // }

        if ( menu_phase ){
            menu_page();
        }

        if ( newgame_phase ){

            srand(time(NULL));
            room_count = 6 + rand() % 4;
            create_rooms();
            //create_doors();
            //create_gameboard();
            // printrooms();
            //printboard();
            newgame_phase = 0;
            continue_prevgame_phase = 1;
        }

        refresh();
    }


    endwin();
    return 0;
}