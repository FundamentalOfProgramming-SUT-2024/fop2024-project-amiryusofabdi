
typedef struct 
{

    int TopLeft_x;
    int TopLeft_y;
    int length;
    int width;
    // int door_count=2;
    int doors[2][2];

} Room ;



Room rooms[];

int room_colapse(){                                                 // bug dare !! age zir majmooe

    for (int i = 0; i < room_count; i++){

        for ( int j = 0; j < room_count; j++ ){

            if ( i != j ){

                if  (   (  rooms[j].TopLeft_x <= rooms[i].TopLeft_x && rooms[i].TopLeft_x <= (rooms[j].TopLeft_x + rooms[j].length)  )
                    &&  (  rooms[j].TopLeft_y <= rooms[i].TopLeft_y && rooms[i].TopLeft_y <= (rooms[j].TopLeft_y + rooms[j].width)  )
                    ){
                    return 1;
                } 

                if  (   (  rooms[j].TopLeft_x <= ( rooms[i].TopLeft_x + rooms[i].length) && ( rooms[i].TopLeft_x + rooms[i].length) <= (rooms[j].TopLeft_x + rooms[j].length)  )
                    &&  (  rooms[j].TopLeft_y <= rooms[i].TopLeft_y && rooms[i].TopLeft_y <= (rooms[j].TopLeft_y + rooms[j].width)  )
                    ){
                    return 1;
                }

                if  (   (  rooms[j].TopLeft_x <= rooms[i].TopLeft_x && rooms[i].TopLeft_x <= (rooms[j].TopLeft_x + rooms[j].length)  )
                    &&  (  rooms[j].TopLeft_y <= (rooms[i].TopLeft_y + rooms[i].width) && (rooms[i].TopLeft_y + rooms[i].width) <= (rooms[j].TopLeft_y + rooms[j].width)  )
                    ){
                    return 1;
                }

                if  (   (  rooms[j].TopLeft_x <= ( rooms[i].TopLeft_x + rooms[i].length) && ( rooms[i].TopLeft_x + rooms[i].length) <= (rooms[j].TopLeft_x + rooms[j].length)  )
                    &&  (  rooms[j].TopLeft_y <= (rooms[i].TopLeft_y + rooms[i].width) && (rooms[i].TopLeft_y + rooms[i].width) <= (rooms[j].TopLeft_y + rooms[j].width)  )
                    ){
                    return 1;
                }               

            }


        }

    }

    return 0;

}

void create_rooms(){

    srand(time(NULL));

    do{

        for (int i = 0; i < room_count; i++){


            int length,width;

            do{
                length = rand() % 15;
            }while ( length < 6 );

            do{
                width = rand() % 15;
            }while ( width < 6 );

            rooms[i].length = length;
            rooms[i].width = width;


            int x,y;

            do{
                x = rand() % COLS ;         // y bayad az 5 bozorgtar bashe k massage haye bazi bala chap beshe
            }while ( (x+length) >= COLS ); 
            

            do{
                y = rand() % LINES;         // y bayad az 5 bozorgtar bashe k massage haye bazi bala chap beshe
            }while ( y < 5 || (y + width) >= LINES) ;    

            rooms[i].TopLeft_x = x;
            rooms[i].TopLeft_y = y;

            

        }


    }while ( room_colapse() );


}


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

void create_gameboard(){

    for (int i = 0; i < room_count; i++){
        

        for (int j = 0; j < rooms[i].length; j++){


            board[rooms[i].TopLeft_y][rooms[i].TopLeft_x + j] = '_';
        
            
        }

        for (int j = 0; j <= rooms[i].length; j++){


            board[rooms[i].TopLeft_y+rooms[i].width][rooms[i].TopLeft_x + j] = '_';
            
        }

        for (int j = 0; j < rooms[i].width; j++){

            

            board[rooms[i].TopLeft_y + j+1][rooms[i].TopLeft_x] = '|';
            
        }
        
        for (int j = 0; j < rooms[i].width; j++){

           

            board[rooms[i].TopLeft_y + j+1][rooms[i].TopLeft_x + rooms[i].length] = '|';
            
        }

        for ( int j = 0; j < 2; j++ ){


            // move(rooms[i].doors[j][1],rooms[i].doors[j][0]);
            board[rooms[i].doors[j][1]][rooms[i].doors[j][0]] = '+';
            // printw("+");

        }

        
    }

}

void printboard(){

    for ( int i = 0; i < LINES; i++){

        for (int j = 0; j < COLS; j++){

            move(i,j);
            printw("%c",board[i][j]);

        }

    }


}


void printrooms(){


    for (int i = 0; i < room_count; i++){
        

        

        for (int j = 0; j < rooms[i].length; j++){

            move(rooms[i].TopLeft_y,rooms[i].TopLeft_x + j);

            printw("_");


        }

        for (int j = 0; j <= rooms[i].length; j++){

            move(rooms[i].TopLeft_y+rooms[i].width , rooms[i].TopLeft_x + j);

            printw("_");
            
        }

        for (int j = 0; j < rooms[i].width; j++){

            move(rooms[i].TopLeft_y + j+1 ,rooms[i].TopLeft_x);

            printw("|");
            
        }
        
        for (int j = 0; j < rooms[i].width; j++){

            move(rooms[i].TopLeft_y + j+1 ,rooms[i].TopLeft_x + rooms[i].length);

            printw("|");
            
        }

        for ( int j = 0; j < 2; j++ ){

            move(rooms[i].doors[j][1],rooms[i].doors[j][0]);
            printw("+");

        }

        
    }



}