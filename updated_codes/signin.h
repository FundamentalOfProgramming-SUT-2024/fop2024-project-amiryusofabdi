int username_exists(char username[]){
    
    FILE *fptr;
    fptr = fopen("usernames.txt","r");

    int flag = 0;

    char str[100];
    char newstr[100];


    while ( fgets(str,100,fptr) ){
        
        for (int i = 4; i < strlen(str)-1; i++){
            newstr[i-4] = str[i];
        }
        
        newstr[strlen(str)-5] = '\0';

        if ( strcmp(newstr,username) == 0 ){
            flag = 1;
        }

    }

    return flag;

}

int check_password(char username[],char password[]){

    char id[3];
    FILE *fptr;
    fptr = fopen("usernames.txt","r");


    char str[100];
    char newstr[100];


    while ( fgets(str,100,fptr) ){
        
        for (int i = 0; i < 4; i++){
            id[i] = str[i];
        }

        for (int i = 4; i < strlen(str)-1; i++){
            newstr[i-4] = str[i];
        }
        
        newstr[strlen(str)-5] = '\0';

        if ( strcmp(newstr,username) == 0 ){
            
            break;

        }

    }

    // 5wp\7(aB
    // Zx,(h9y

    id[3] = '\0';
    

    FILE *fptr2;
    fptr2 = fopen("passwords.txt","r");

    

    while ( fgets(str,100,fptr2) ){
        
        int flag = 1;

        for (int i = 0; i < 3; i++){
            
            if ( id[i] != str[i] ){
                flag = 0;
            }
            
        }

        if (flag){
            
            for (int i = 4; i < strlen(str)-1; i++){
                newstr[i-4] = str[i];
            }
            
            newstr[strlen(str)-5] = '\0';


            if ( strcmp(newstr,password) == 0 ){
                
                return 1;

            }

            return 0;

        }
        
        
    }


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

    while ( !check_password(username,password) ){
        
        move(LINES/5 + 5, COLS/3 + 6);
        printw("Wrong Password! Try again.");
        refresh();
        usleep(1000000);
        move(LINES/5 + 5, COLS/3 + 6);
        printw("                            ");
        move(LINES/5 + 5, COLS/3 + 6);
        scanw("%s",password);

    }

    clear();

    signin_phase = 0;
    menu_phase = 1;

}