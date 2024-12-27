#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <ncurses.h>


// Phases
int welcome_phase = 1;
int signup_or_signin_phase = 0;

// Global Variables
int hover_singup = 1;


// Functions
void welcome_page(time_t begin, time_t now){

    move(25,20);
    attron(A_BOLD);
    long int time_elapsed = now - begin;
    

    if ( time_elapsed > 7){
        welcome_phase = 0;
        signup_or_signin_phase = 1;
        attroff(A_BOLD | A_BLINK);
        clear();
    }
    else if ( time_elapsed > 4.75 ){
        attron(A_BLINK);
        printw("Welcome To Rouge...");
    }
    else if ( time_elapsed > 4.5 ){
        printw("Welcome To Rouge..");
    }
    else if ( time_elapsed > 4.25 ){
        printw("Welcome To Rouge.");
    }
    else if ( time_elapsed > 4 ){
        printw("Welcome To Rouge");
    }
    else if ( time_elapsed > 3.75 ){
        printw("Welcome To Roug");
    }
    else if ( time_elapsed > 3.5 ){
        printw("Welcome To Rou");
    }
    else if ( time_elapsed > 3.25 ){
        printw("welcome To Ro");
    }
    else if ( time_elapsed > 3 ){
        printw("Welcome To R");
    }
    else if ( time_elapsed > 2.75 ){
        printw("Welcome To ");
    }
    else if ( time_elapsed > 2.5 ){
        printw("Welcome To");
    }
    else if ( time_elapsed > 2.25 ){
        printw("Welcome T");
    }
    else if ( time_elapsed > 2 ){
        printw("Welcome ");
    }
    else if ( time_elapsed > 1.75 ){
        printw("Welcome");
    }
    else if ( time_elapsed > 1.5 ){
        printw("Welcom");
    }
    else if ( time_elapsed > 1.25 ){
        printw("Welco");
    }
    else if ( time_elapsed > 1 ){
        printw("Welc");
    }
    else if ( time_elapsed > 0.75 ){
        printw("Wel");
    }
    else if ( time_elapsed > 0.5 ){
        printw("We");
    }
    else if ( time_elapsed > 0.25 ){
        printw("W");
    }

}

void signup_or_signin_page(){


    attron(A_BOLD);
    move (10,80);
    printw("If you have an account, Sign in otherwise, Sign up!");

    noecho();
    int ch = getch();

    if (ch != -1 ){
        if ( ch == 68 ){
            hover_singup = 1;
        }
        else if ( ch == 67 ){
            hover_singup = 0;
        }
    }


    if (hover_singup){
        attron(A_STANDOUT|A_BLINK);
        move (30,50);
        printw("Sign up");
        attroff(A_STANDOUT|A_BLINK);
        move (30,150);
        printw("Sign in");
    }
    else {
        attron(A_STANDOUT|A_BLINK);
        move (30,150);
        printw("Sign in");
        attroff(A_STANDOUT|A_BLINK);
        move (30,50);
        printw("Sign up");
    }
}

// Main
int main(){

    initscr();
    curs_set(0);
    time_t begin = time(NULL);
    timeout(0);

    while (1){

        time_t now = time(NULL);

        if (welcome_phase){
            welcome_page(begin,now);
        }

        else if (signup_or_signin_phase){
            signup_or_signin_page();
        }

        refresh();
    }


    endwin();
    return 0;
}