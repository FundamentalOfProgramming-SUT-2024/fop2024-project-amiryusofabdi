
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

int room_colapse(){

    for (int i = 0; i < 6; i++){

        for ( int j = 0; j < 6; j++ ){

            if ( i != j ){

                

            }


        }

    }


}

void createandwritemap(){

    srand(time(NULL));

    do{



    }while ( room_colapse() );





}