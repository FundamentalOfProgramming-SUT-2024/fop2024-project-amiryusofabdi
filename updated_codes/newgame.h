


void create_rooms(int level){

    int MAX_LENGTH = COLS/3;
    int MAX_WIDTH = LINES/2;

    for ( int i = 0; i < 6; i++ ){

        rooms[level][i].length = rand() % (MAX_LENGTH-12) + 6;
        

        rooms[level][i].TopLeft_x = (COLS/3 * (i%3)) + rand() % ( MAX_LENGTH - rooms[level][i].length );
        do{

            rooms[level][i].width = rand() % (MAX_WIDTH-8) + 6;
            rooms[level][i].TopLeft_y = (LINES/2 * (i/3))  + rand() % ( MAX_WIDTH - rooms[level][i].width ) + 2;

        }while( (rooms[level][i].TopLeft_y+rooms[level][i].width) >= (LINES-4) );

    }


}

/*
void create_doors(){


    for (int i = 0; i < room_count; i++){

        
        int Position = rand()%4;        // 0 -> Top     1 ->  Right     2 ->     Bottom     3 -> Left

        if ( Position == 0 ){
            
            int x = rand() % (rooms[i].length - 2);

            rooms[i].doors[0][0] = rooms[i].TopLeft_x + 1 + x;
            rooms[i].doors[0][1] = rooms[i].TopLeft_y;

        }
        
        else if ( Position == 2 ){
            
            int x = rand() % (rooms[i].length - 2);

            rooms[i].doors[0][0] = rooms[i].TopLeft_x + 1 + x;
            rooms[i].doors[0][1] = rooms[i].TopLeft_y + rooms[i].width;

        }

        else if ( Position == 1 ){
            
            int y = rand() % (rooms[i].width - 2);

            rooms[i].doors[0][0] = rooms[i].TopLeft_x;
            rooms[i].doors[0][1] = rooms[i].TopLeft_y + 1 + y;

        }
        
        else if ( Position == 3 ){
            
            int y = rand() % (rooms[i].width - 2);

            rooms[i].doors[0][0] = rooms[i].TopLeft_x + rooms[i].length;
            rooms[i].doors[0][1] = rooms[i].TopLeft_y + 1 + y;

        }

        int FirstDoorPosition = Position;


        do{

            Position = rand()%4;        // 0 -> Top     1 ->  Right     2 ->     Bottom     3 -> Left

            if ( Position == 0 ){
                
                int x = rand() % (rooms[i].length - 2);

                rooms[i].doors[1][0] = rooms[i].TopLeft_x + 1 + x;
                rooms[i].doors[1][1] = rooms[i].TopLeft_y;

            }
            
            else if ( Position == 2 ){
                
                int x = rand() % (rooms[i].length - 2);

                rooms[i].doors[1][0] = rooms[i].TopLeft_x + 1 + x;
                rooms[i].doors[1][1] = rooms[i].TopLeft_y + rooms[i].width;

            }

            else if ( Position == 1 ){
                
                int y = rand() % (rooms[i].width - 2);

                rooms[i].doors[1][0] = rooms[i].TopLeft_x;
                rooms[i].doors[1][1] = rooms[i].TopLeft_y + 1 + y;

            }
            
            else if ( Position == 3 ){
                
                int y = rand() % (rooms[i].width - 2);

                rooms[i].doors[1][0] = rooms[i].TopLeft_x + rooms[i].length;
                rooms[i].doors[1][1] = rooms[i].TopLeft_y + 1 + y;

            }



        }while( Position == FirstDoorPosition );


    }

}
*/




void create_gameboard(int level){

    create_rooms(level);

    for (int i = 0; i < room_count; i++){
        

        for (int j = 0; j < rooms[level][i].length; j++){


            board[level][rooms[level][i].TopLeft_y][rooms[level][i].TopLeft_x + j].type = '_';
        
            
        }

        for (int j = 0; j <= rooms[level][i].length; j++){


            board[level][rooms[level][i].TopLeft_y+rooms[level][i].width][rooms[level][i].TopLeft_x + j].type = '_';
            
        }

        for (int j = 0; j < rooms[level][i].width; j++){

            

            board[level][rooms[level][i].TopLeft_y + j+1][rooms[level][i].TopLeft_x].type = '|';
            
        }
        
        for (int j = 0; j < rooms[level][i].width; j++){

           

            board[level][rooms[level][i].TopLeft_y + j+1][rooms[level][i].TopLeft_x + rooms[level][i].length].type = '|';
            
        }


        for (int j=rooms[level][i].TopLeft_y+1; j < (rooms[level][i].TopLeft_y+rooms[level][i].width); j++){

            for (int k=rooms[level][i].TopLeft_x+1; k < (rooms[level][i].TopLeft_x+rooms[level][i].length); k++){
                board[level][j][k].type = '.';
            }


        }

        
    }

}


void permutation(int horizontal, int vertical, int* move){

    int total = horizontal + vertical;

    for ( int i = 0; i < total; i++ ){

        if ( horizontal == 0 ){     // vertical faghat mire
            move[i] = 0;
            vertical --;
        }
        else if( vertical == 0 ){
            move[i] = 1;            // horizontal faghat mire
            horizontal --;
        }
        else{
            int random_move = rand() % 2;
            move[i] = random_move;
            if ( random_move == 0 ){
                vertical --;
            }
            else{
                horizontal --;
            }
        }

    }

}

void create_hallway(int room1, int room2,int level){

    int beginning_tile_x = rooms[level][room1].TopLeft_x + rand() % ( rooms[level][room1].length -2 ) + 1;
    int beginning_tile_y = rooms[level][room1].TopLeft_y + rand() % ( rooms[level][room1].width -2 ) + 1;

    int finishing_tile_x = rooms[level][room2].TopLeft_x + rand() % ( rooms[level][room2].length -2 ) + 1;
    int finishing_tile_y = rooms[level][room2].TopLeft_y + rand() % ( rooms[level][room2].width -2 )+ 1;


    int horizontal = abs(beginning_tile_x - finishing_tile_x);
    int vertical = abs(beginning_tile_y - finishing_tile_y);

    int vertical_move_type,horizontal_move_type;

    if (vertical != 0){
        vertical_move_type = (finishing_tile_y - beginning_tile_y) / vertical;
    }
    if ( horizontal != 0 ){
        horizontal_move_type = (finishing_tile_x - beginning_tile_x) / horizontal;
    }
    

    int move[horizontal+vertical];  // 0 for vertical    1 for horizontal

    permutation(horizontal,vertical,move);

    clear();
    move(0,0);
    printw("%d %d %d %d",beginning_tile_x ,beginning_tile_y ,finishing_tile_x ,finishing_tile_y);
    move(1,0);
    for (int i = 0; i < horizontal+vertical; i++ ){
        printw("%d",move[i]);
    }

    int current_tile_x = beginning_tile_x;
    int current_tile_y = beginning_tile_y;
    
    for ( int i = 0; i < (horizontal+vertical); i++ ){

        if ( board[level][current_tile_y][current_tile_x].type == '.' ){
            // NOTHING
        }

        else if( board[level][current_tile_y][current_tile_x].type == '_' || board[level][current_tile_y][current_tile_x].type == '|' ){
            board[level][current_tile_y][current_tile_x].type = '+';
        }

        else{

            board[level][current_tile_y][current_tile_x].type = '#';
            
        }

        if ( move[i] == 0 ){
            current_tile_y += vertical_move_type;
        }

        else if( move[i] == 1 ){
            current_tile_x += horizontal_move_type;
        }


    }

    // board[level][beginning_tile_y][beginning_tile_x].type = '&';
    // board[level][finishing_tile_y][finishing_tile_x].type = '&';
    
    
    

}