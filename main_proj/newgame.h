


void create_rooms(int level){

    int MAX_LENGTH = COLS/3;
    int MAX_WIDTH = LINES/2;

    for ( int i = 0; i < 6; i++ ){


        rooms[level][i].stairs = 0;
        rooms[level][i].length = rand() % (MAX_LENGTH-12) + 6;
    

        rooms[level][i].TopLeft_x = (COLS/3 * (i%3)) + rand() % ( MAX_LENGTH - rooms[level][i].length );
        do{

            rooms[level][i].width = rand() % (MAX_WIDTH-8) + 6;
            rooms[level][i].TopLeft_y = (LINES/2 * (i/3))  + rand() % ( MAX_WIDTH - rooms[level][i].width ) + 2;

        }while( (rooms[level][i].TopLeft_y+rooms[level][i].width) >= (LINES-4) );



        int size = rooms[level][i].length * rooms[level][i].width;

        rooms[level][i].PillarCount = size / ( 15 + rand()%10 );

        for ( int j = 0; j < rooms[level][i].PillarCount; j++ ){

            rooms[level][i].pillar_x = rooms[level][i].TopLeft_x + 1 + rand() % ( rooms[level][i].length -2 );
            rooms[level][i].pillar_y = rooms[level][i].TopLeft_y + 1 + rand() % ( rooms[level][i].width -2 );

        }




    }


}





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
                board[level][j][k].main_type = 0;
                board[level][j][k].room_info = i;
            }


        }

        for (int j = 0; j < rooms[level][i].PillarCount; j++){

            board[level][rooms[level][i].pillar_y][rooms[level][i].pillar_x].type = 'O';

        }

        if ( RoomsWithStairs[level] == i ){

            board[level][rooms[level][i].stairs_y][rooms[level][i].stairs_x].type = 's';
            board[level][rooms[level][i].stairs_y][rooms[level][i].stairs_x].main_type = 3;

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

    int current_tile_x = beginning_tile_x;
    int current_tile_y = beginning_tile_y;
    
    for ( int i = 0; i < (horizontal+vertical); i++ ){

        if ( board[level][current_tile_y][current_tile_x].type == '.' ){
            // NOTHING
        }

        else if ( board[level][current_tile_y][current_tile_x].type == 'O' ){
            // NOTHING
        }

        else if( board[level][current_tile_y][current_tile_x].type == '_' || board[level][current_tile_y][current_tile_x].type == '|' ){
            board[level][current_tile_y][current_tile_x].type = '+';
            board[level][current_tile_y][current_tile_x].main_type = 2;
        }

        else{

            board[level][current_tile_y][current_tile_x].type = '#';
            board[level][current_tile_y][current_tile_x].main_type = 1;
            
        }

        if ( move[i] == 0 ){
            current_tile_y += vertical_move_type;
        }

        else if( move[i] == 1 ){
            current_tile_x += horizontal_move_type;
        }


    }



}

void add_stairs(){

    for ( int i = 0; i < 3; i++ ){

        int RoomNum = RoomsWithStairs[i];
        rooms[i+1][RoomNum].length = rooms[i][RoomNum].length;
        rooms[i+1][RoomNum].width = rooms[i][RoomNum].width;
        rooms[i+1][RoomNum].TopLeft_x = rooms[i][RoomNum].TopLeft_x;
        rooms[i+1][RoomNum].TopLeft_y = rooms[i][RoomNum].TopLeft_y;
        rooms[i][RoomNum].stairs = 1;
        rooms[i+1][RoomNum].stairs = 1;

        rooms[i+1][RoomNum].stairs_x = rooms[i][RoomNum].TopLeft_x + 1 + rand() % ( rooms[i][RoomNum].length - 2 );
        rooms[i+1][RoomNum].stairs_y = rooms[i][RoomNum].TopLeft_y + 1 + rand() % ( rooms[i][RoomNum].width - 2 );

        rooms[i][RoomNum].stairs_x = rooms[i+1][RoomNum].stairs_x;
        rooms[i][RoomNum].stairs_y = rooms[i+1][RoomNum].stairs_y;

        board[i][rooms[i][RoomNum].stairs_y][rooms[i][RoomNum].stairs_x].main_type = 3;
        board[i][rooms[i][RoomNum].stairs_y][rooms[i][RoomNum].stairs_x].type = 's';
        board[i+1][rooms[i+1][RoomNum].stairs_y][rooms[i+1][RoomNum].stairs_x].main_type = 3;
        board[i+1][rooms[i+1][RoomNum].stairs_y][rooms[i+1][RoomNum].stairs_x].type = 's';

    }

}