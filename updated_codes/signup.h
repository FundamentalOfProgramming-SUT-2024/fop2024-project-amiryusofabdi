#include "newaccount.h"

int username_isok(char username[]){                     

    FILE *fptr;
    fptr = fopen("usernames.txt","r");


    char str[100];
    char newstr[100];

    

    while ( fgets(str,100,fptr) ){
        
        for (int i = 4; i < strlen(str)-1; i++){
            newstr[i-4] = str[i];
        }
        
        newstr[strlen(str)-5] = '\0';

        if ( strcmp(newstr,username) == 0 ){
            return 0;
        }

    }

    return 1;
}


int password_isok(char password[]){

    int len = strlen(password);
    int digit_exist = 0, upper_exist = 0, lower_exist = 0;

    if (len < 7){
        return 0;
    }

    for (int i = 0; i < len; i++){

        if ( 'a' <= password[i] && password[i] <= 'z' ){
            lower_exist = 1;
        }

        else if ( 'A' <= password[i] &&  password[i] <= 'Z'){
            upper_exist = 1;
        }

        else if ( '0' <= password[i] && password[i] <= '9' ){
            digit_exist = 1;
        }

        else if (  password[i] == ' '){
            return 0;
        }


    }

    if ( ! (digit_exist && upper_exist && lower_exist) ){
        return 0;
    }

    return 1;

}


int email_isok(char email[]){

    char *str = email ;
    char *result = strchr(str,'@');

    long int index = result - str;

    for (int i = 0; i < index; i ++){

        if ( !(('a' <= email[i] && email[i] <= 'z') || ('A' <= email[i] && email[i] <= 'Z') ||
        (email[i] == '_') || (email[i] == '.') || ('0' <= email[i] && email[i] <= '9')) ){
            return 0;
        }

    }

    int dot_count = 0;

    for (int i = index+1 ; i < strlen(email); i++){

        if (  !(('a' <= email[i] && email[i] <= 'z') || email[i] == '.') ){
            return 0;
        }

        if ( email[i] == '.' ){
            dot_count ++;
        }

    }

    if ( dot_count != 1 ){
        return 0;
    }

    return 1;

}


void signup_page(){

    echo();
    timeout(-1);

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
    printw("Username: ");
    
    move (LINES/5 + 5,COLS/3+1);
    printw("Password: ");

    move (LINES/5 + 8,COLS/3+1);
    printw("Email: ");

    char username[1000];
    char password[1000];
    char email[1000];

    move(LINES/5 + 2, COLS/3 + 10);
    scanw("%s",username);


    while ( !username_isok(username) ){

        move(LINES/5 + 2, COLS/3 + 10);
        printw("Invalid Username! Try again.");
        refresh();
        usleep(1000000);
        move(LINES/5 + 2, COLS/3 + 10);
        printw("                            ");
        move(LINES/5 + 2, COLS/3 + 10);
        scanw("%s",username);
        
    }

    move(LINES/5 + 5, COLS/3 + 10);
    scanw("%s",password);
    
    while ( !password_isok(password) ){
        

        if ( strcmp(password,"random") == 0 ){
        
            srand(time(NULL));
            int length;

            do{
                length = rand()%15;
            }while( length < 7 );
            
            password[length] = '\0';

            for (int i = 0; i < length; i++){

                int ascii;
                do{
                    ascii = rand()%126;
                }while (ascii < 33);

                password[i] = (char)ascii;

            }
            move(LINES/5 + 5, COLS/3 + 10);
            printw("%s",password);
            break;

        }

        else{
            
            move(LINES/5 + 5, COLS/3 + 10);
            printw("Invalid Password! Try again.");
            refresh();
            usleep(1000000);
            move(LINES/5 + 5, COLS/3 + 10);
            printw("                            ");
            move(LINES/5 + 5, COLS/3 + 10);
            scanw("%s",password);


        }
    }


    move(LINES/5 + 8, COLS/3 + 8);
    scanw("%s",email);

    while ( !email_isok(email) ){
        
        move(LINES/5 + 8, COLS/3 + 8);
        printw("Invalid Email! Try again.");
        refresh();
        usleep(1000000);
        move(LINES/5 + 8, COLS/3 + 8);
        printw("                         ");
        move(LINES/5 + 8, COLS/3 + 8);
        scanw("%s",email);

    }
    
    newaccount(username,email,password);

    clear();
    signup_phase = 0;
    menu_phase = 1;
    strcpy(player_username,username);
    strcpy(player_email,email);
    strcpy(player_password,password);
    


}