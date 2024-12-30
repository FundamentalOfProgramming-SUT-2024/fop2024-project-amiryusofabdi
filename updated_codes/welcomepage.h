void welcome_page(time_t begin, time_t now){
    //timeout(0);
    move(LINES/2,COLS/4);
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