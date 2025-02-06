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


    if ( song_number == 1 ){
        attron(COLOR_PAIR(5));
        mvprintw(LINES/3-2,COLS/2-5,"1) TopG");
        attroff(COLOR_PAIR(5));   
        mvprintw(LINES/3,COLS/2-5,"2) Gole Yakh");
        mvprintw(LINES/3+2,COLS/2-5,"3) Baby-Shark");     
        
    }
    else if ( song_number == 2 ){

        mvprintw(LINES/3-2,COLS/2-5,"1) TopG");
        attron(COLOR_PAIR(5));
        mvprintw(LINES/3,COLS/2-5,"2) Gole Yakh");
        attroff(COLOR_PAIR(5)); 
        mvprintw(LINES/3+2,COLS/2-5,"3) Baby-Shark");

    }
    else if ( song_number == 3 ){ 

        mvprintw(LINES/3-2,COLS/2-5,"1) TopG");
        mvprintw(LINES/3,COLS/2-5,"2) Gole Yakh");
        attron(COLOR_PAIR(5));
        mvprintw(LINES/3+2,COLS/2-5,"3) Baby-Shark");
        attroff(COLOR_PAIR(5)); 

    }



}

void generate_username(){

    for (int i = 0; i < 20; i++){

        int len = 5 + rand()%5;
        for (int j = 0; j < len; j++){
            
            int char_type = rand()%3;   // 0 for nums   1 for upper     2 for lower

            if ( char_type == 0 ){
                usernames[i][j] = '0'+rand()%10;
            }
            else if ( char_type == 1 ){
                usernames[i][j] = 'A'+rand()%26;
            }
            else if ( char_type == 2 ){
                usernames[i][j] = 'a'+rand()%26;
            }

        }

    }

    strcpy(usernames[5],player_username);

}

void generate_finishiedgames(){

    for ( int i = 0; i < 20; i++ ){

        finished_game[i] = rand () % 19 + 1;

    }

}

void bubbleSort() {
    int i, j, temp;
    int swapped;

    for (i = 0; i < 19; i++) {
        swapped = 0; // Optimization to stop if already sorted

        for (j = 0; j < 19 - i; j++) {
            if (gathred_points[j] < gathred_points[j + 1]) {

                temp = gathred_points[j];
                gathred_points[j] = gathred_points[j + 1];
                gathred_points[j + 1] = temp;
                swapped = 1;

                temp = gathred_golds[j];
                gathred_golds[j] = gathred_golds[j + 1];
                gathred_golds[j + 1] = temp;
                swapped = 1;


                temp = finished_game[j];
                finished_game[j] = finished_game[j + 1];
                finished_game[j + 1] = temp;
                swapped = 1;

                
            }
        }

        if (swapped == 0)
            break;
    }
}

void generate_pointsAndgold(){


    for (int i = 0; i < 20  ; i++){

        gathred_golds[i] = rand() % 1000;
        gathred_points[i] = gathred_golds[i] / finished_game[i];

    }

    bubbleSort();

}

void generate_timeplayed(){

    for (int i = 0; i < 20; i++){

        time_played[i] = rand()%200;

    }

}

void scoreboard_page(){

    attron(COLOR_PAIR(2) | A_BOLD);
    mvprintw(2,COLS/2-5,"Scoreboard");
    attroff(COLOR_PAIR(2) | A_BOLD);


    mvprintw(LINES/5-2,COLS/3-30,"Rank");
    mvprintw(LINES/5-2,COLS/3-20,"Username");
    mvprintw(LINES/5-2,COLS/3,"Golds");
    mvprintw(LINES/5-2,COLS/3+10,"Finished Games");
    mvprintw(LINES/5-2,COLS/3+30,"Time Played(Minutes)");
    mvprintw(LINES/5-2,COLS/3+60,"Points");

    for ( int i = 0; i < 10; i++ ){

        if ( i+scroll_count+1 == 6 ){

            attron(COLOR_PAIR(5) | A_BLINK | A_BOLD);
            mvprintw(LINES/5 + 2 * i,COLS/3-30,"%d.",i+scroll_count+1);
            mvprintw(LINES/5 + 2 * i,COLS/3-20,"%s",usernames[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3,"%d",gathred_golds[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+10,"%d",finished_game[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+30,"%d",time_played[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+60,"%d",gathred_points[i+scroll_count]);
            attroff(COLOR_PAIR(5) | A_BLINK | A_BOLD);

        }
        else if ( i+scroll_count+1 == 1 ){

            attron(COLOR_PAIR(1));
            mvprintw(LINES/5 + 2 * i,COLS/3-30,"%d.(\U0001F947)",i+scroll_count+1);
            mvprintw(LINES/5 + 2 * i,COLS/3-20,"%s(Da Goat)",usernames[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3,"%d",gathred_golds[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+10,"%d",finished_game[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+30,"%d",time_played[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+60,"%d",gathred_points[i+scroll_count]);
            attroff(COLOR_PAIR(1));

        }
        else if ( i+scroll_count+1 == 2 ){

            attron(COLOR_PAIR(4));
            mvprintw(LINES/5 + 2 * i,COLS/3-30,"%d.(\U0001F948)",i+scroll_count+1);
            mvprintw(LINES/5 + 2 * i,COLS/3-20,"%s(Legend)",usernames[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3,"%d",gathred_golds[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+10,"%d",finished_game[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+30,"%d",time_played[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+60,"%d",gathred_points[i+scroll_count]);
            attroff(COLOR_PAIR(4));

        }
        else if ( i+scroll_count+1 == 3 ){

            attron(COLOR_PAIR(3));
            mvprintw(LINES/5 + 2 * i,COLS/3-30,"%d.(\U0001F949)",i+scroll_count+1);
            mvprintw(LINES/5 + 2 * i,COLS/3-20,"%s(Hero)",usernames[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3,"%d",gathred_golds[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+10,"%d",finished_game[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+30,"%d",time_played[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+60,"%d",gathred_points[i+scroll_count]);
            attroff(COLOR_PAIR(3));

        }



        else{
            
            mvprintw(LINES/5 + 2 * i,COLS/3-30,"%d.",i+scroll_count+1);
            mvprintw(LINES/5 + 2 * i,COLS/3-20,"%s",usernames[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3,"%d",gathred_golds[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+10,"%d",finished_game[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+30,"%d",time_played[i+scroll_count]);
            mvprintw(LINES/5 + 2 * i,COLS/3+60,"%d",gathred_points[i+scroll_count]);

        }

    }


    timeout(0);
    noecho();

    int ch = getch();

    if ( ch != ERR){

        if ( ch == KEY_UP  && scroll_count > 0){
            clear();
            scroll_count --;
            
        }
        else if ( ch == KEY_DOWN && scroll_count < 10 ){
            clear();
            scroll_count ++;
        }

    }

}
