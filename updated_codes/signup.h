void signup_page(){

    echo();

    // STYLE
    move(LINES/5,COLS/(3));
    printw("***************New Account***************");
    
    for (int i = LINES/5 + 1; i < LINES/5 + 11; i++){
        move(i,COLS/3);
        printw("*");
    }

    for (int i = LINES/5 + 1; i < LINES/5 + 11; i++){
        move(i,COLS/3+40);
        printw("*");
    }

    move(LINES/5 + 10,COLS/(3));
    printw("*****************************************");
    
    // GETTING USERNAME
    curs_set(1);
    

    move (LINES/5 + 2,COLS/3+1);
    printw("Username");
    
    move (LINES/5 + 5,COLS/3+1);
    printw("Password");

    move (LINES/5 + 8,COLS/3+1);
    printw("Email");
    

    
    
}