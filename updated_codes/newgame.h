
typedef struct 
{

    int TopLeft_x;
    int TopLeft_y;
    int length;
    int width;
    int door_count;
    int doors[][2];

} Room ;

Room rooms[6];

int room_colapse(){                                                 // bug dare !! age zir majmooe

    for (int i = 0; i < 6; i++){

        for ( int j = 0; j < 6; j++ ){

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

void createandwritemap(){

    srand(time(NULL));

    do{

        for (int i = 0; i < 6; i++){


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


    for (int i = 0; i < 6; i++){
        

        

        for (int j = 0; j < rooms[i].length; j++){

            move(rooms[i].TopLeft_y,rooms[i].TopLeft_x + j);

            printw("*");

        }

        for (int j = 0; j <= rooms[i].length; j++){

            move(rooms[i].TopLeft_y+rooms[i].width , rooms[i].TopLeft_x + j);

            printw("*");
            
        }

        for (int j = 0; j < rooms[i].width; j++){

            move(rooms[i].TopLeft_y + j ,rooms[i].TopLeft_x);

            printw("*");
            
        }
        
        for (int j = 0; j < rooms[i].width; j++){

            move(rooms[i].TopLeft_y + j ,rooms[i].TopLeft_x + rooms[i].length);

            printw("*");
            
        }

        
    }



}