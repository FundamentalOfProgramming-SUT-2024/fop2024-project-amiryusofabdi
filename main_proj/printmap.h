void printboard(int level){
    
    for ( int i = 0; i < LINES; i++){

        for (int j = 0; j < COLS; j++){
            move(i,j);
            printw("%c",board[level][i][j].type);
        }

    }

}