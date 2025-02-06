void profile_page(){


        move(LINES/5,COLS/2-10);
        printw("Player Info:");

        move(LINES/5, COLS/2-20);
        if ( strcmp(player_username,"Guest") == 0){
            printw("Profile id: You are a lazy guest habibi!");
        }
        else{
            printw("Profile id: %s",player_username);
            move(LINES/5+2, COLS/2-20);
            printw("Your email: %s",player_email);
            move(LINES/5+4, COLS/2-20);
            printw("Your password: %s",player_password);
        }

}

void setting_page(){

    timeout(0);
    noecho();

    mvprintw(LINES/3-4,COLS/3,"1) Dificulty Settings");
    mvprintw(LINES/3-2,COLS/3,"2) Icon Settings");
    mvprintw(LINES/3,COLS/3,"3) Songs Settings");

   

}

void choose_dificulty_page(){

    if (Dificulty == 0){

        attron(COLOR_PAIR(4));
        mvprintw(LINES/3,COLS/3,"1) Normal");
        attroff(COLOR_PAIR(4));
        mvprintw(LINES/3+4,COLS/3,"2) Hard");

    }

    else {


        mvprintw(LINES/3,COLS/3,"1) Normal");
        attron(COLOR_PAIR(4));
        mvprintw(LINES/3+4,COLS/3,"2) Hard");
        attroff(COLOR_PAIR(4));

    }

}



void choose_color_page(){

    attron(COLOR_PAIR(1));
    mvprintw(LINES/3-4,COLS/2-5,"1) Yellow");
    attroff(COLOR_PAIR(1));



    attron(COLOR_PAIR(2));
    mvprintw(LINES/3-2,COLS/2-5,"2) Green");
    attroff(COLOR_PAIR(2));



    attron(COLOR_PAIR(3));
    mvprintw(LINES/3,COLS/2-5,"3) Cyan");
    attroff(COLOR_PAIR(3));



    attron(COLOR_PAIR(4));
    mvprintw(LINES/3+2,COLS/2-5,"4) Magenta");
    attroff(COLOR_PAIR(4));



    attron(COLOR_PAIR(5));
    mvprintw(LINES/3+4,COLS/2-5,"5) Red");
    attroff(COLOR_PAIR(5));
    
    mvprintw(LINES/3+ (2 * icon_color - 6), COLS/2 + 5, "\u2190" );

}

void choose_song_page(){

    mvprintw(LINES/3-2,COLS/2-5,"1) TopG");
    mvprintw(LINES/3,COLS/2-5,"2) Gole Yakh");
    


}