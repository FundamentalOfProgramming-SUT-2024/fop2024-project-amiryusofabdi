void spawn_player(int level){


    int RoomNumber = rand() % 6;

    player_status.x = rooms[level][RoomNumber].TopLeft_x + 1 + rand() % ( rooms[level][RoomNumber].length - 2 ); 
    player_status.y = rooms[level][RoomNumber].TopLeft_y + 1 + rand() % ( rooms[level][RoomNumber].width - 2 ); 

    board[level][player_status.y][player_status.x].type = '&';

}

int Allowed2Move(int x, int y){

    char new_tile = board[player_status.level-1][player_status.y + y][player_status.x + x].type;
    
    if ( new_tile == '#' || new_tile == '+' || new_tile == '.'){
        return 1;
    }
    return 0;

}

void update_player(){     

    timeout(0);
    noecho();
    int key = getch();


    if ( key != ERR ){
        clear();
        int x_move,y_move;

        switch (key){

            case 'u':
                x_move = 1;
                y_move = -1;
                break;

            case 'y':
                
                x_move = -1;
                y_move = -1;
                break;
            

            case 'a':

                x_move = -1;
                y_move = 0;
                break;    

            case 'w':
                
                x_move = 0;
                y_move = -1;
                break;

            case 's':
                
                x_move = 0;
                y_move = 1;
                break;

            case 'd':
                
                x_move = 1;
                y_move = 0;
                break;

            case 'b':
                
                x_move = -1;
                y_move = 1;
                break;

            case 'n':
                
                x_move = 1;
                y_move = 1;
                break;

            default:
                x_move = 0;
                y_move = 0;


        }

        if ( Allowed2Move(x_move,y_move) ){
            
            board[player_status.level-1][player_status.y][player_status.x].type = '.';

            player_status.x += x_move;
            player_status.y += y_move;

            board[player_status.level-1][player_status.y][player_status.x].type = '&';
            
        }

    }





}