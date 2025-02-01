void printboard(int level){
    
    for ( int i = 0; i < LINES; i++){

        for (int j = 0; j < COLS; j++){
            move(i,j);
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
            else{
                printw("%c",board[level][i][j].type);
            }
        }

    }

}