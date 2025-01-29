#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#define LEVEL 4
#define cols 119
#define lines 34


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
int room_count = 6;


// ROOMS


typedef struct 
{

    int TopLeft_x;
    int TopLeft_y;
    int length;
    int width;
    int PillarCount;
    int pillar_x;
    int pillar_y;


} Room ;

Room rooms[4][6];

// BOARD

typedef struct{
    
    int visible;
    char type;


} tile;

tile board[LEVEL][lines][cols];


// Player info

typedef struct
{

    int gold;
    int strength;
    int armor;
    int hits;
    int level;
    int experience;

    int x;
    int y;

}PLAYER ;

PLAYER player_status;

// Functions

#include "welcomepage.h"
#include "signupsigninpage.h"
#include "signup.h"
#include "signin.h"
#include "menu.h"
#include "newgame.h"
#include "printmap.h"
#include "massages.h"
#include "player.h"

// Main
int main(){


    initscr();
    curs_set(0);
    time_t begin = time(NULL);
    keypad(stdscr,TRUE);
    srand(time(NULL));

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

            for (int i = 0; i < 4; i++){
                create_gameboard(i);
                create_hallway(0,1,i);
                create_hallway(1,2,i);
                create_hallway(2,3,i);
                create_hallway(3,5,i);
                create_hallway(5,4,i);
                create_hallway(4,3,i);
                create_hallway(3,1,i);
                // create_hallway(0,1,i);
                // create_hallway(0,1,i);
            }         

            newgame_phase = 0;
            continue_prevgame_phase = 1;
            player_status.gold = 0;
            player_status.hits = 12;
            player_status.armor = 5;
            player_status.level = 1;
            player_status.strength = 16;
            player_status.experience = 1;
            spawn_player(player_status.level-1);

        }

        if ( continue_prevgame_phase ){
            
            status();
            update_player();
            printboard(player_status.level-1);
            
            
        }


        refresh();
    }


    endwin();
    return 0;
}