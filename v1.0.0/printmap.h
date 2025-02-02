void printboard(int level){
    
    for ( int i = 0; i < LINES; i++){

        for (int j = 0; j < COLS; j++){
            move(i,j);

            if ( board[level][i][j].type == '@' ){
                printw("@");
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