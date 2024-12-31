int username_exists(char username[]){
    
    FILE *fptr;
    fptr = fopen("usernames.txt","r");

    int len = strlen(username);
    username[len] = '\n';    
    username[len+1] = '\0';

    char str[100];
    int flag = 0;

    while ( fgets(str,100,fptr) ){
        
        if ( strcmp(str,username) == 0 ){
            flag = 1;
        }

    }

    return flag;

}

void signin_page(){


    echo();
    timeout(-1);


    // STYLE
    move(LINES/5,COLS/(3)-6);
    printw("***************Login to your account***************");
    
    for (int i = LINES/5 + 1; i < LINES/5 + 8; i++){
        move(i,COLS/3 - 6);
        printw("*");
    }

    for (int i = LINES/5 + 1; i < LINES/5 + 8; i++){
        move(i,COLS/3+44);
        printw("*");
    }

    move(LINES/5 + 7,COLS/(3)-6);
    printw("***************************************************");
    
    // GETTING USERNAME
    curs_set(1);
    

    move (LINES/5 + 2,COLS/3-4);
    printw("Username: ");
    
    move (LINES/5 + 5,COLS/3-4);
    printw("Password: ");


    char username[1000];
    char password[1000];


    move(LINES/5 + 2, COLS/3 + 6);
    scanw("%s",username);


    while ( !username_exists(username) ){

        move(LINES/5 + 2, COLS/3 + 6);
        printw("Invalid Username! Try again.");
        refresh();
        usleep(1000000);
        move(LINES/5 + 2, COLS/3 + 6);
        printw("                            ");
        move(LINES/5 + 2, COLS/3 + 6);
        scanw("%s",username);
        
    }
    

    move(LINES/5 + 5, COLS/3 + 6);
    scanw("%s",password);

    while ( !password_isok(password) ){
        
        move(LINES/5 + 5, COLS/3 + 6);
        printw("Invalid Password! Try again.");
        refresh();
        usleep(1000000);
        move(LINES/5 + 5, COLS/3 + 6);
        printw("                            ");
        move(LINES/5 + 5, COLS/3 + 6);
        scanw("%s",password);

    }


}