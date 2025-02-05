//      qwe
//      a.d
//      zsc

//  x for speed up
//  f for food menu
//  g for gun menu
//  h for potion menu

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <locale.h>
#include <wchar.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#define LEVEL 4
#define cols 119
#define lines 34
#define USD "\u{0024}"
#define POUND "\u{00A3}"
#define STAIR "\u{2934}"
#define TRAP "T"
#define HEART "\u2665"
#define PIZZA "\U0001F355"
#define GREEN_APPLE "\U0001F34F"
#define SUSHI "\U0001F363"
#define GRAPES "\U0001F347"
#define BANANA "\U0001F34C"
#define NormalLoopCounter 40000
#define DicifultyCoefficient 10000
#define POTION_EFFECT 80000

// Phases
int welcome_phase = 0;      
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
char last_massage_type = '!';
int last_gold_found = 0;
int RoomsWithStairs[3];
int potions[3]; // 0 for health 1 for speed 2 for damage
char last_potion_found;
int speed_activate;
char player_username[100];
int Dificulty = 0; //  0 for Normal     1 for Hard 
int loop_counter = 0;
int Hunger_Decrease = 1;
int Health_Decrease = 0;
int food_menu_phase = 0;
int last_hunger_decrease;
int last_health_decrease;
int pickedup_foods[4];      // 0 for nomal      1 for topnotch
                            // 2 for expired    3 for magical
int potion_loop_counter = 0;
int using_potion_phase = -1;    // -1 for NONE      0 for TOP-NOTCH     1 for Magical     

// ITEMS

typedef struct
{
    int x;
    int y;
    int amount;
    int type;               // 0 for normal     1 for black

} GOLD ;

typedef struct 
{
    
    int type;       // 0 for health     1 for speed     2 for Damage
    int x;
    int y;
    int picked_up;


} POTION;

typedef struct 
{

    int type;
    int x;
    int y;
    int picked_up;


} FOOD;

// ROOMS

typedef struct 
{

    int type;       // 0 for normal   1 for enchant     2 for treasure
    int TopLeft_x;
    int TopLeft_y;
    int length;
    int width;
    int PillarCount;
    int pillar_x;
    int pillar_y;
    int gold_count;
    int potion_count;
    int stairs;         
    int stairs_x;
    int stairs_y;
    int normal_gold_density;        // a number between 5 and 10
    int trap_count;
    int trap_x;
    int trap_y;
    int food_count;
    GOLD golds[10];
    POTION potions[10];
    FOOD foods[10];


} Room ;

Room rooms[4][6];

// BOARD

typedef struct{
    
    int visible;
    char type;                  // t for traps
    int main_type;              // 0 for Inside of rooms        1 for Hallways          2 for Doors
                                // 3 for stairs             4 for potions(health)       5 for potions(speed)
                                //  6 for potions(damage)   7 for traps     
                                //  8 for normalfood    9 for top-notch food
                                //  10 for expired food     11 for magical food
    int room_info;              // -1 for outside of rooms      0 for normal
                                // 1 for enchant        2 for treasure


} tile;

tile board[LEVEL][lines][cols];


// Player info

typedef struct
{

    int gold;
    int health;
    int strength;
    int hunger;
    int level;
    int speed;

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
#include "items.h"
#include "inputs.h"
#include "item_menus.h"
#include "music_player.h"


// Main
int main(){

    pickedup_foods[0] = 0;
    pickedup_foods[1] = 0;
    pickedup_foods[2] = 0;
    pickedup_foods[3] = 0;
    // play_music("andrew_tate.mp3");

    setlocale(LC_ALL, "");
    initscr();
    curs_set(0);
    time_t begin = time(NULL);
    keypad(stdscr,TRUE);
    srand(time(NULL));
    start_color();



    // COLORS
    init_color(COLOR_YELLOW,1000,800,0);
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1,COLOR_YELLOW,COLOR_BLACK);
    init_pair(2,COLOR_GREEN,COLOR_BLACK);
    init_pair(3,COLOR_CYAN,COLOR_BLACK);
    init_pair(4,COLOR_MAGENTA,COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);

    bkgd(COLOR_PAIR(0));


    for (int i = 0; i < LEVEL; i++){

        for (int j = 0; j < LINES; j++){

            for (int k = 0; k < COLS; k++){

                board[i][j][k].room_info = -1;

            }

        }

    }


    player_status.hunger = 6;


    while (1){

        if ( using_potion_phase == 0 || using_potion_phase == 1 ){
            potion_loop_counter ++;
        }

        if ( potion_loop_counter == POTION_EFFECT ){

            potion_loop_counter = 0;
            if ( using_potion_phase == 0){
                player_status.strength -= 5;
            }
            else{
                player_status.speed -= 1;
            }
            using_potion_phase = -1;

        }

        if ((continue_prevgame_phase) && (Hunger_Decrease) &&  (loop_counter ++) == (NormalLoopCounter - Dificulty * DicifultyCoefficient)){

            loop_counter = 0;
            player_status.hunger --;
            clear();

        }

        if ( player_status.hunger <= 0 && Hunger_Decrease){

            player_status.hunger = 0;
            Hunger_Decrease = 0;
            Health_Decrease = 1;
            

        }

        if (Health_Decrease &&  (loop_counter++) == (NormalLoopCounter - Dificulty * DicifultyCoefficient)){

            loop_counter = 0;
            player_status.health --;
            clear();

        }

        time_t now = time(NULL);

        if ( welcome_phase ){
            welcome_page(begin,now);
        }

        if ( signup_or_signin_phase ){
            signup_or_signin_page();
        }

        if ( signup_phase ){
            signup_page();
        }

        if ( signin_phase ){
            signin_page();
        }

        if ( guest_phase ){
            strcpy(player_username,"Guest");
            guest_phase = 0;
            menu_phase = 1;
        }

        if ( menu_phase ){
            menu_page();        
        }

        if ( newgame_phase ){

            RoomsWithStairs[0] = rand()%6;
            do{
                RoomsWithStairs[1] = rand()%6;
            }while( RoomsWithStairs[1] == RoomsWithStairs[0] );

            do{
                RoomsWithStairs[2] = rand()%6;
            }while ( (RoomsWithStairs[2] == RoomsWithStairs[0]) || (RoomsWithStairs[2] == RoomsWithStairs[1]) );
            
        
            for (int i = 0; i < 4; i++){
                
                create_gameboard(i);
                create_hallway(0,1,i);
                create_hallway(1,2,i);
                create_hallway(2,3,i);
                create_hallway(3,5,i);
                create_hallway(5,4,i);
                create_hallway(4,3,i);
                create_hallway(3,1,i);
                create_traps(i);

            }         

            newgame_phase = 0;
            continue_prevgame_phase = 1;
            player_status.gold = 0;
            player_status.health = 10;
            player_status.strength = 5;
            player_status.level = 1;
            player_status.speed = 1;

            spawn_player(player_status.level-1);
            
            Assign_RoomType();

            // Spawn Golds

            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 6; j++){

                    if ( rooms[i][j].type == 0){
                        spawn_gold(1,i,j,3);
                    }
                    else if ( rooms[i][j].type == 1){
                        spawn_gold(1,i,j,3);
                    }
                    else if ( rooms[i][j].type == 2){
                        spawn_gold(1,i,j,3);
                    }
                    spawn_food(i,j);

                }
            }

            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 6; j++){

                    if ( rooms[i][j].type == 0){
                        spawn_potion(1,i,j);
                    }
                    else if ( rooms[i][j].type == 1){
                        spawn_potion(2,i,j);
                    }
                    else if ( rooms[i][j].type == 2){
                        spawn_potion(1,i,j);
                    }

                }
            }

            last_massage_type = 'w';
        }

        if ( continue_prevgame_phase ){
            
            status();
            update_player();
            
            if ( food_menu_phase == 0 ){
                printboard(player_status.level-1);
            }
            else if ( food_menu_phase == 1 ){
                
                food_menu();

            }


            // printboard(player_status.level-1);
            check_up();
            
            
        }

        if ( food_menu_phase == 0){
            massage(last_massage_type);
        }
        // massage(last_massage_type);

        refresh();
    }

    


    endwin();
    return 0;
}