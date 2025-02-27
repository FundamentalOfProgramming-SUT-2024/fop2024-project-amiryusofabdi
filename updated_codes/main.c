//      qwe
//      a.d
//      zsc

//  x for speed up
//  f for item menu


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
#define DicifultyCoefficient 20000
#define ITEM_EFFECT 80000

// Phases
int welcome_phase = 0;      
int signup_or_signin_phase = 1; 
int signup_phase = 0;
int signin_phase = 0;
int guest_phase = 0;
int menu_phase = 0;
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
char player_email[100];
char player_password[100];
int Dificulty = 0; //  0 for Normal     1 for Hard 
int loop_counter = 0;
int Hunger_Decrease = 1;
int Health_Decrease = 0;
int food_menu_phase = 0;
int last_hunger_decrease;
int last_health_decrease;
int pickedup_foods[4];      // 0 for nomal      1 for topnotch
                            // 2 for expired    3 for magical
int food_loop_counter = 0;
int using_food_phase = -1;    // -1 for NONE      0 for TOP-NOTCH     1 for Magical     
int potions_menu_phase = 0;
int pickedup_guns[5];       // 0 for Mace   1 for dagger        2 for Magic-wand
                            // 3 for Normal-Arrow       4 for Sword
int death = 0;
int using_potion_phase = 0; // -1 for NONE   0 for HEAL     1 for Speed   2 for damage
int potion_loop_counter = 0;
int choose_diciculty_phase = 0;
int choose_color_phase = 0;
int choose_song_phase = 0;
int main_setting_phase = 1;
int icon_color = 1;  //  1:Yellow       2:Green       3:Cyan        4:Magenta     5:Red
int song_number = 0;
char songs[5][100];
int back_flag = 0;
int map_generated = 0;
int scroll_count = 0;
int song_change = 1;
int first_flag = 1;
int first_in_enchant = 1;

// Scoreboard Variables
char usernames[20][100];
int gathred_golds[20];
int gathred_points[20];
int finished_game[20];
int time_played[20];

// ITEMS

typedef struct {

    int x;
    int y;
    int type[2];    // 0 for health     1 for strength


} MONSTER;

typedef struct{

    int x;
    int y;
    int type;   // 0 for mace   1 for dagger    2 for Magic-wand    3 for normal arrow 
                // 4 for sword
    int picked_up;
    int damage;

} GUN;

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
    int gun_count;
    int monster_count;
    MONSTER monsters[10];
    GOLD golds[10];
    POTION potions[10];
    FOOD foods[10];
    GUN guns[10];


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
                                //  12 for dagger    13 for magic-wand
                                //  14 for normal-arrow     15 for sword

                                // 16 for deamon    17 for fire-freathing-monster
                                // 18 for giant     19 for snake        20 for undeed
                                

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
    int current_weapon;         // 0 for Mace(Default)
                                    // 1 for dagger         2 for magic-wand
                                    // 3 for normal arrow   4 for sword
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
#include "menupage_options.h"
#include "newgame.h"
#include "printmap.h"
#include "massages.h"
#include "player.h"
#include "items.h"
#include "item_menus.h"
#include "music_player.h"


// Main
int main(){

    pickedup_foods[0] = 0;
    pickedup_foods[1] = 0;
    pickedup_foods[2] = 0;
    pickedup_foods[3] = 0;

    pickedup_guns[0] = 1;
    pickedup_guns[1] = 0;
    pickedup_guns[2] = 0;
    pickedup_guns[3] = 0;
    pickedup_guns[4] = 0;

    strcpy(songs[0],"welcome_song.mp3");
    strcpy(songs[1],"andrew_tate.mp3");
    strcpy(songs[2],"gole_yakh.mp3");
    strcpy(songs[3],"cars.mp3");
    strcpy(songs[4],"baby_shark.mp3");

    // play_music(songs[song_number]);

    setlocale(LC_ALL, "");
    initscr();
    curs_set(0);
    time_t begin = time(NULL);
    keypad(stdscr,TRUE);
    srand(time(NULL));
    start_color();

    player_status.current_weapon = 0;


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
    player_status.gold = 0;
    player_status.health = 10;
    player_status.strength = 5;
    player_status.level = 1;
    player_status.speed = 1;


    while (1){

        if ( song_change ){
            song_change = 0;
            play_music(songs[song_number]);
        }

        if ( using_food_phase == 0 || using_food_phase == 1 ){
            food_loop_counter ++;
        }

        if ( food_loop_counter == ITEM_EFFECT ){

            food_loop_counter = 0;
            if ( using_food_phase == 0){
                player_status.strength -= 5;
            }
            else{
                player_status.speed -= 1;
            }
            using_food_phase = -1;

        }

        if ( using_potion_phase == 0 || using_potion_phase == 1 || using_potion_phase == 2){
            potion_loop_counter ++;
        }

        if ( potion_loop_counter == ITEM_EFFECT * 10){

            potion_loop_counter = 0;
            if ( using_potion_phase == 0){

            }
            else if (using_potion_phase == 1)  {
                player_status.speed = 1;
            }
            else if (using_potion_phase == 2)  {
                player_status.strength -= 5;
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

        if ( player_status.health <= 0 ){
            death = 1;
            continue_prevgame_phase = 0;
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

            generate_finishiedgames();
            generate_username();
            generate_pointsAndgold();
            generate_timeplayed();
            menu_page();  
            if ( back_flag ){
                back_flag = 0;
            }      
        }

        if (profile_phase){
            
            profile_page();

        }

        if (setting_phase){
            timeout(0);

            if ( main_setting_phase ){

                setting_page();


                int ch = getch();
                if ( ch != ERR ){

                    if ( ch == 'b' ){
                        clear();
                        setting_phase = 0;
                        menu_phase = 1;

                    }

                    if ( ch == '1' ){

                        clear();
                        choose_diciculty_phase = 1;
                        main_setting_phase = 0;        


                    }

                    else if ( ch == '2' ){
                        
                        clear();
                        choose_color_phase = 1;
                        main_setting_phase = 0;

                    }

                    else if ( ch == '3' ){

                        clear();
                        choose_song_phase = 1;
                        main_setting_phase = 0;

                    }

                }
            }

            if ( choose_diciculty_phase ){

                choose_dificulty_page();

                int ch = getch();
                if ( ch != ERR ){

                    if ( ch == 'b' ){
                        clear();
                        main_setting_phase = 1;
                        choose_diciculty_phase = 0;

                    }

                    if ( ch == '1' ){

                        Dificulty = 0;

                    }
                    else if ( ch == '2' ){

                        Dificulty = 1;

                    }

                }

            }

            if ( choose_color_phase ){

                choose_color_page();

                int ch = getch();
                if ( ch != ERR ){

                    if ( ch == 'b' ){
                        clear();
                        main_setting_phase = 1;
                        choose_color_phase = 0;

                    }

                    if ( ch == '1' ){

                        clear();
                        icon_color = 1;

                    }
                    else if ( ch == '2' ){

                        clear();
                        icon_color = 2;

                    }
                    else if ( ch == '3' ){

                        clear();
                        icon_color = 3;

                    }
                    else if ( ch == '4' ){

                        clear();
                        icon_color = 4;

                    }
                    else if ( ch == '5' ){

                        clear();
                        icon_color = 5;

                    }
                }                

            }

            if ( choose_song_phase ){

                choose_song_page();
                int ch = getch();
                if ( ch != ERR ){

                    if ( ch == 'b' ){
                        clear();
                        main_setting_phase = 1;
                        choose_song_phase = 0;
                        

                    }

                    if ( ch == '1' ){

                        if ( song_number != 1 ){
                            song_change = 1;
                        }

                        clear();
                        song_number = 1;

                        

                    }
                    else if ( ch == '2' ){

                        if ( song_number != 2 ){
                            song_change = 1;
                        }

                        clear();
                        song_number = 2;

                    }
                    else if ( ch == '3' ){

                        if ( song_number != 3 ){
                            song_change = 1;
                        }

                        clear();
                        song_number = 3;

                    }
                    
                }                

            }

        }

        if (scoreboard_phase){

            timeout(0);
            noecho();
            scoreboard_page();
            int ch = getch();
            if ( ch != ERR ){

                if ( ch == 'b' ){
                    clear();
                    main_setting_phase = 1;
                    scoreboard_phase = 0;
                    

                }
            

            }
        }

        if ( newgame_phase && !map_generated){
            
            map_generated = 1;
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
                    spawn_guns(i,j);
                    spawn_mosnter(i,j);

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
            
            if ( food_menu_phase == 0 && !back_flag){
                printboard(player_status.level-1);
            }
            else if ( food_menu_phase == 1 && !back_flag){
                
                item_menu();

            }        
            
        }

        if ( food_menu_phase == 0 && !death){
            massage(last_massage_type);
        }

        if ( death ){

            move(LINES/2 - 5, COLS/2-10);
            printw("You died ):  R.I.P.");
            mvprintw(LINES/2+-3, COLS/2-5,"GG's");
            mvprintw(LINES-1,COLS-18,"Press E to exit...");

            timeout(0);
            noecho();
            int ch = getch();
            if ( ch != ERR ){

                if ( ch == 'e' ){
                    break;
                }

            }

        }


        refresh();
        first_flag= 0;
    }

    


    endwin();
    return 0;
}