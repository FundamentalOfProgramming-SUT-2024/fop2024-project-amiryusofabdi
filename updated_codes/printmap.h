void printboard(int level){
    
    for ( int i = 0; i < LINES; i++){

        for (int j = 0; j < COLS; j++){
            move(i,j);

            if ( board[level][i][j].type == '@' ){
                attron(COLOR_PAIR(icon_color));
                printw("@");
                attroff(COLOR_PAIR(icon_color));

                if ( board[level][i][j].room_info == 1 ){
                    if ( first_in_enchant ){
                        first_in_enchant = 0;
                        song_number = 3;
                        song_change = 1;
                    }
                }

                continue;
            }
            if ( board[level][i][j].room_info == 2 ){
                attron(COLOR_PAIR(1));
            }
            else if ( board[level][i][j].room_info == 1 ){
                attron(COLOR_PAIR(4));
            }


            if (board[level][i][j].type == 'b'){                       // black gold
                
                attron(COLOR_PAIR(2));
                printw(USD);
                attroff(COLOR_PAIR(2));

            }
            else if ( board[level][i][j].type == 'g' ){               // normal gold
                
                attron(COLOR_PAIR(1));
                printw(USD);
                attroff(COLOR_PAIR(1));

            }       
            else if ( board[level][i][j].type == 's' ){

                attron(COLOR_PAIR(3));
                printw(STAIR);
                attroff(COLOR_PAIR(3));

            }
            else if ( board[level][i][j].type == 'p' ){

                attron(COLOR_PAIR(2));
                printw("P");
                attroff(COLOR_PAIR(2));

            }else if ( board[level][i][j].type == 'l' ){

                attron(COLOR_PAIR(1));
                printw("P");
                attroff(COLOR_PAIR(1));

            }else if ( board[level][i][j].type == 'k' ){

                attron(COLOR_PAIR(4));
                printw("P");
                attroff(COLOR_PAIR(4));

            }
            else if ( board[level][i][j].type == 't' ){

                attron(COLOR_PAIR(5));
                printw(TRAP);
                attroff(COLOR_PAIR(5));

            }

            //
            //
            //      Divar ha bekhatere in unicode ha ydoone shift mokhoran rast!!!!
            //      fix: replace kardan in unicode ha ba ye char
            //
            //
            //

            else if ( board[level][i][j].type == 'n' ){

                printw("n");

            }
            else if ( board[level][i][j].type == 'r' ){

                printw("r");

            }
            else if ( board[level][i][j].type == 'm' ){

                printw("m");

            }
            else if ( board[level][i][j].type == 'e' ){

                printw("e");

            }
            else if ( board[level][i][j].type == 'd' ){     // dagger
                printw("\U0001F5E1");   
            }
            else if ( board[level][i][j].type == 'w' ){     // magic-wand
                // printw("\U0001FA84");
                printw("W");
            }
            else if ( board[level][i][j].type == 'a' ){     // normal-arrow
                printw("\u27B3");
            }
            else if ( board[level][i][j].type == 'v' ){     // sword
                printw("\u2694");
            }
            
            else if ( board[level][i][j].type == 'D'
                    || board[level][i][j].type == 'F'
                    || board[level][i][j].type == 'G'
                    || board[level][i][j].type == 'S'
                    || board[level][i][j].type == 'U' ){
                        attron(COLOR_PAIR(5));
                        printw("%c",board[level][i][j].type);
                        attroff(COLOR_PAIR(5));
                    }

            else{
                printw("%c",board[level][i][j].type);
            }



            if ( board[level][i][j].room_info == 2 ){
                attroff(COLOR_PAIR(1));
            }
            else if ( board[level][i][j].room_info == 1 ){
                
                attroff(COLOR_PAIR(4));
            }



        }

    }

}