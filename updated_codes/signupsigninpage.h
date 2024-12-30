
int signup_hover = 1;
int signin_hover = 0;
int guest_hover = 0;


void signup_or_signin_page(){

    timeout(0);

    attron(A_BOLD);
    move (LINES/5,COLS/(3.5));
    printw("If you have an account, Sign in otherwise, Sign up!");

    noecho();
    int ch = getch();

    if (ch != ERR ){

        if ( ch == KEY_UP ){
            
            if ( guest_hover ){
                guest_hover = 0;
                signin_hover = 1;
            }

            else if ( signin_hover ){
                signin_hover = 0;
                signup_hover = 1;
            }

        }

        else if ( ch == KEY_DOWN ){

            if ( signup_hover ){
                signup_hover = 0;
                signin_hover = 1;
            }

            else if ( signin_hover ){
                signin_hover = 0;
                guest_hover = 1;
            }

        }

        else if ( ch == 10 ){                           // Enter
            clear();
            signup_or_signin_phase = 0;

            if ( signup_hover ){
                signup_phase = 1;
            }
            else if ( signup_hover ){
                signin_phase = 1;
            }
            else if ( signup_hover ){
                guest_phase = 1;
            }

        }

    }

    if ( signup_hover && signup_or_signin_phase){

        attron(A_STANDOUT|A_BLINK);
        move(2*LINES/5,COLS/(2.2));
        printw("SIGN UP");
        attroff(A_STANDOUT|A_BLINK);       

        move(2*LINES/5 + 3, COLS/(2.2));
        printw("SIGN IN");

        move(2*LINES/5 + 6, COLS/(2.2) + 1);
        printw("GUEST");

    }

    else if ( signin_hover ){

        move(2*LINES/5,COLS/(2.2));
        printw("SIGN UP");        

        attron(A_STANDOUT|A_BLINK);
        move(2*LINES/5 + 3, COLS/(2.2));
        printw("SIGN IN");
        attroff(A_STANDOUT|A_BLINK);

        move(2*LINES/5 + 6, COLS/(2.2) + 1);
        printw("GUEST");

    }

    else if ( guest_hover ){

        move(2*LINES/5,COLS/(2.2));
        printw("SIGN UP");      

        move(2*LINES/5 + 3, COLS/(2.2));
        printw("SIGN IN");

        attron(A_STANDOUT|A_BLINK);
        move(2*LINES/5 + 6, COLS/(2.2) + 1);
        printw("GUEST");
        attroff(A_STANDOUT|A_BLINK);

    }

    
}