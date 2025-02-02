void menu_page(){

    timeout(0);
    noecho();
    attron(A_BOLD);
    
    // Border

    move(LINES/3-1,COLS/(2.5));
    printw("*******************************");

    for (int i = LINES/3; i < LINES/3 + 12; i++){
        move(i,COLS/2.5);
        printw("*");
    }

    for (int i = LINES/3; i < LINES/3 + 12; i++){
        move(i,COLS/2.5+30);
        printw("*");
    }

    move(LINES/3 + 11,COLS/(2.5));
    printw("******************************");


    // Options

//   --------------------------------------------------------

    int ch = getch();

    if (ch != ERR ){

        if ( ch == KEY_UP ){
            
            if ( continue_prevgame_hover ){
                continue_prevgame_hover = 0;
                newgame_hover = 1;
            }

            else if ( scoreboard_hover ){
                scoreboard_hover = 0;
                continue_prevgame_hover = 1;
            }

            else if ( profile_hover ){
                profile_hover = 0;
                scoreboard_hover = 1;
            }

            else if ( setting_hover ){
                setting_hover = 0;
                profile_hover = 1;
            }

        }

        else if ( ch == KEY_DOWN ){

            if ( newgame_hover ){
                continue_prevgame_hover = 1;
                newgame_hover = 0;
            }

            else if ( continue_prevgame_hover ){
                scoreboard_hover = 1;
                continue_prevgame_hover = 0;
            }

            else if ( scoreboard_hover ){
                profile_hover = 1;
                scoreboard_hover = 0;
            }

            else if ( profile_hover ){
                setting_hover = 1;
                profile_hover = 0;
            }

        }

        else if ( ch == 10 ){                           // Enter
            clear();
            menu_phase = 0;

            if ( newgame_hover ){
                newgame_phase = 1;
            }
            else if ( continue_prevgame_hover ){
                continue_prevgame_phase = 1;
            }
            else if ( scoreboard_hover ){
                scoreboard_phase = 1;
            }
            else if ( profile_hover ){
                profile_phase = 1;
            }
            else if ( setting_hover ){
                setting_phase = 1;
            }

        }

    }



    if ( newgame_hover && menu_phase){

        attron(A_STANDOUT|A_BLINK);
        move(LINES/3 + 1,COLS/(2.5)+1);
        printw("New Game");
        attroff(A_STANDOUT|A_BLINK);

        move(LINES/3 + 3,COLS/(2.5)+1);
        printw("Continue Previous Game");

        move(LINES/3 + 5,COLS/(2.5)+1);
        printw("Score Board");

        move(LINES/3 + 7,COLS/(2.5)+1);
        printw("Profile");

        move(LINES/3 + 9,COLS/(2.5)+1);
        printw("Settings");

    }

    else if ( continue_prevgame_hover && menu_phase){

        move(LINES/3 + 1,COLS/(2.5)+1);
        printw("New Game");

        attron(A_STANDOUT|A_BLINK);
        move(LINES/3 + 3,COLS/(2.5)+1);
        printw("Continue Previous Game");
        attroff(A_STANDOUT|A_BLINK);

        move(LINES/3 + 5,COLS/(2.5)+1);
        printw("Score Board");

        move(LINES/3 + 7,COLS/(2.5)+1);
        printw("Profile");

        move(LINES/3 + 9,COLS/(2.5)+1);
        printw("Settings");

    }

    else if ( scoreboard_hover && menu_phase){

        move(LINES/3 + 1,COLS/(2.5)+1);
        printw("New Game");

        move(LINES/3 + 3,COLS/(2.5)+1);
        printw("Continue Previous Game");

        attron(A_STANDOUT|A_BLINK);
        move(LINES/3 + 5,COLS/(2.5)+1);
        printw("Score Board");
        attroff(A_STANDOUT|A_BLINK);

        move(LINES/3 + 7,COLS/(2.5)+1);
        printw("Profile");

        move(LINES/3 + 9,COLS/(2.5)+1);
        printw("Settings");

    }

    else if ( profile_hover && menu_phase){

        move(LINES/3 + 1,COLS/(2.5)+1);
        printw("New Game");

        move(LINES/3 + 3,COLS/(2.5)+1);
        printw("Continue Previous Game");

        move(LINES/3 + 5,COLS/(2.5)+1);
        printw("Score Board");

        attron(A_STANDOUT|A_BLINK);
        move(LINES/3 + 7,COLS/(2.5)+1);
        printw("Profile");
        attroff(A_STANDOUT|A_BLINK);

        move(LINES/3 + 9,COLS/(2.5)+1);
        printw("Settings");

    }

    else if ( setting_hover && menu_phase){

        move(LINES/3 + 1,COLS/(2.5)+1);
        printw("New Game");

        move(LINES/3 + 3,COLS/(2.5)+1);
        printw("Continue Previous Game");

        move(LINES/3 + 5,COLS/(2.5)+1);
        printw("Score Board");

        move(LINES/3 + 7,COLS/(2.5)+1);
        printw("Profile");

        attron(A_STANDOUT|A_BLINK);
        move(LINES/3 + 9,COLS/(2.5)+1);
        printw("Settings");
        attroff(A_STANDOUT|A_BLINK);

    }

    else{
        clear();
    }

}