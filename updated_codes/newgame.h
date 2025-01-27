
typedef struct 
{

    int TopLeft_x;
    int TopLeft_y;
    int length;
    int width;
    int doors[2][2];

} Room ;

Room rooms[6];


void create_rooms(){

    int MAX_LENGTH = COLS/3;
    int MAX_WIDTH = LINES/2;

    for ( int i = 0; i < 6; i++ ){

        rooms[i].length = rand() % (MAX_LENGTH-12) + 6;
        

        rooms[i].TopLeft_x = (COLS/3 * (i%3)) + rand() % ( MAX_LENGTH - rooms[i].length );
        do{

            rooms[i].width = rand() % (MAX_WIDTH-8) + 6;
            rooms[i].TopLeft_y = (LINES/2 * (i/3))  + rand() % ( MAX_WIDTH - rooms[i].width ) + 2;

        }while( (rooms[i].TopLeft_y+rooms[i].width) >= (LINES-4) );

    }


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

// hallway

// 1->2     2->3        3->6        6->5    5->4    4->3    3->2    2->1


//  1:RU    2:RD    3:LU    4:LD

int check_position(int first_room, int second_room){

    

}


void create_gameboard(int level){

    create_rooms();
    create_doors();

    for (int i = 0; i < room_count; i++){
        

        for (int j = 0; j < rooms[i].length; j++){


            board[level][rooms[i].TopLeft_y][rooms[i].TopLeft_x + j].type = '_';
        
            
        }

        for (int j = 0; j <= rooms[i].length; j++){


            board[level][rooms[i].TopLeft_y+rooms[i].width][rooms[i].TopLeft_x + j].type = '_';
            
        }

        for (int j = 0; j < rooms[i].width; j++){

            

            board[level][rooms[i].TopLeft_y + j+1][rooms[i].TopLeft_x].type = '|';
            
        }
        
        for (int j = 0; j < rooms[i].width; j++){

           

            board[level][rooms[i].TopLeft_y + j+1][rooms[i].TopLeft_x + rooms[i].length].type = '|';
            
        }

        for ( int j = 0; j < 2; j++ ){


            board[level][rooms[i].doors[j][1]][rooms[i].doors[j][0]].type = '+';

        }

        for (int j=rooms[i].TopLeft_y+1; j < (rooms[i].TopLeft_y+rooms[i].width); j++){

            for (int k=rooms[i].TopLeft_x+1; k < (rooms[i].TopLeft_x+rooms[i].length); k++){
                board[level][j][k].type = '.';
            }


        }

        
    }

}