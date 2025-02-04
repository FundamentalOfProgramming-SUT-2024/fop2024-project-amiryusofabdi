
void create_traps(int level){

    for ( int i = 0; i < 6; i++ ){

        int TrapExists = rand() % 2;
        
        rooms[level][i].trap_count = TrapExists;
        
        if ( TrapExists ){

            rooms[level][i].trap_x = rooms[level][i].TopLeft_x + 1 + (rand() % ( rooms[level][i].length - 2 ));
            rooms[level][i].trap_y = rooms[level][i].TopLeft_y + 1 + (rand() % ( rooms[level][i].width - 2 ));
            board[level][rooms[level][i].trap_y][rooms[level][i].trap_x].type = '.';
            board[level][rooms[level][i].trap_y][rooms[level][i].trap_x].main_type = 7;
        }
    }
}

void create_rooms(int level){

    int MAX_LENGTH = COLS/3;
    int MAX_WIDTH = LINES/2;

    for ( int i = 0; i < 6; i++ ){


        if ( RoomsWithStairs[level] == i && level != 0){

            rooms[level][i].length = rooms[level-1][i].length;
            rooms[level][i].width = rooms[level-1][i].width;
            rooms[level][i].TopLeft_x = rooms[level-1][i].TopLeft_x;
            rooms[level][i].TopLeft_y = rooms[level-1][i].TopLeft_y;
            
        }




        else{
            rooms[level][i].stairs = 0;
            rooms[level][i].length = rand() % (MAX_LENGTH-12) + 6;
        

            rooms[level][i].TopLeft_x = (COLS/3 * (i%3)) + rand() % ( MAX_LENGTH - rooms[level][i].length );
            do{

                rooms[level][i].width = rand() % (MAX_WIDTH-8) + 6;
                rooms[level][i].TopLeft_y = (LINES/2 * (i/3))  + rand() % ( MAX_WIDTH - rooms[level][i].width ) + 2;

            }while( (rooms[level][i].TopLeft_y+rooms[level][i].width) >= (LINES-4) );

            
        }

        int size = rooms[level][i].length * rooms[level][i].width;

        rooms[level][i].PillarCount = size / ( 15 + rand()%10 );

        for ( int j = 0; j < rooms[level][i].PillarCount; j++ ){

            rooms[level][i].pillar_x = rooms[level][i].TopLeft_x + 1 + rand() % ( rooms[level][i].length -2 );
            rooms[level][i].pillar_y = rooms[level][i].TopLeft_y + 1 + rand() % ( rooms[level][i].width -2 );

        }

        if ( RoomsWithStairs[level] == i ){

            rooms[level][i].stairs = 1;
            rooms[level][i].stairs_x = rooms[level][i].TopLeft_x + 1 + ( rand() % (rooms[level][i].length-2) );
            rooms[level][i].stairs_y = rooms[level][i].TopLeft_y + 1 + ( rand() % (rooms[level][i].width-2) );


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

        for ( int k = 0; k < rooms[level][i].potion_count; k++ ){

            if (rooms[level][i].potions[k].type == 0){
                board[level][rooms[level][i].potions[k].y][rooms[level][i].potions[k].x].type = 'p';
                board[level][rooms[level][i].stairs_y][rooms[level][i].stairs_x].main_type = 4;
            }
            else if (rooms[level][i].potions[k].type == 1){
                board[level][rooms[level][i].potions[k].y][rooms[level][i].potions[k].x].type = 'l';
                board[level][rooms[level][i].stairs_y][rooms[level][i].stairs_x].main_type = 5;
            }
            else if (rooms[level][i].potions[k].type == 2){
                board[level][rooms[level][i].potions[k].y][rooms[level][i].potions[k].x].type = 'k';
                board[level][rooms[level][i].stairs_y][rooms[level][i].stairs_x].main_type = 6;
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

void Assign_RoomType(){

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 6; j++){
            rooms[i][j].type = 0;

            for (int y = rooms[i][j].TopLeft_y; y <= (rooms[i][j].TopLeft_y + rooms[i][j].width);y++){
                for (int x = rooms[i][j].TopLeft_x; x <= (rooms[i][j].TopLeft_x + rooms[i][j].length);x++){
                    board[i][y][x].room_info = 0;
                }
            }

        }
    }

    //  Assigning Treasure Room

    int RoomNum = rand() % 6;
    rooms[3][RoomNum].type = 2;

    for (int y = rooms[3][RoomNum].TopLeft_y; y <= (rooms[3][RoomNum].TopLeft_y + rooms[3][RoomNum].width);y++){
        for (int x = rooms[3][RoomNum].TopLeft_x; x <= (rooms[3][RoomNum].TopLeft_x + rooms[3][RoomNum].length);x++){
            board[3][y][x].room_info = 2;
        }
    }

    // Assigning Enchant Room

    rooms[0][RoomsWithStairs[0]].type = 1;
    rooms[1][RoomsWithStairs[1]].type = 1;
    rooms[2][RoomsWithStairs[2]].type = 1;

    for (int k = 0; k < 3; k++){

        for (int y = rooms[k][RoomsWithStairs[k]].TopLeft_y; y <= (rooms[k][RoomsWithStairs[k]].TopLeft_y + rooms[k][RoomsWithStairs[k]].width);y++){
            for (int x = rooms[k][RoomsWithStairs[k]].TopLeft_x; x <= (rooms[k][RoomsWithStairs[k]].TopLeft_x + rooms[k][RoomsWithStairs[k]].length);x++){
                board[k][y][x].room_info = 1;
            }
        }


    }


}