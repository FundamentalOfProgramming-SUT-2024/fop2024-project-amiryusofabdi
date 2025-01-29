void printboard(int level){
    
    for ( int i = 0; i < LINES; i++){

        for (int j = 0; j < COLS; j++){
            move(i,j);
            if (board[level][i][j].type == 'b'){                       // black gold
                
                player_status.gold += 

                printw(POUND);
            }
            else if ( board[level][i][j].type == 'g' ){               // normal gold
                printw(RIAL);
            }       
            else{
                printw("%c",board[level][i][j].type);
            }
        }

    }

}