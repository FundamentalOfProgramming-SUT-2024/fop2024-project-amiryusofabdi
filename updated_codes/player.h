void spawn_player(int level){


    int RoomNumber = rand() % 6;

    player_status.x = rooms[level][RoomNumber].TopLeft_x + 1 + rand() % ( rooms[level][RoomNumber].length - 2 ); 
    player_status.y = rooms[level][RoomNumber].TopLeft_y + 1 + rand() % ( rooms[level][RoomNumber].width - 2 ); 

    board[level][player_status.y][player_status.x].type = '@';

}

int Allowed2Move(int x, int y){

    char new_tile = board[player_status.level-1][player_status.y + y][player_status.x + x].type;
    
    if ( new_tile == '#' || new_tile == '+' || new_tile == '.' || new_tile == 'b' || new_tile == 'g'
        || new_tile == 's' || new_tile == 'p' || new_tile == 'l' || new_tile == 'k'
    ){
        
        return 1;
    }
    return 0;

}

void update_player(){     

    timeout(0);
    noecho();
    int key = getch();
    int t;

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

            case 'f':

                speed_activate = 1;
            

            case '.':

                if ( rooms[player_status.level-1][RoomsWithStairs[player_status.level-1]].stairs_x == player_status.x &&
                   rooms[player_status.level-1][RoomsWithStairs[player_status.level-1]].stairs_y == player_status.y &&
                   player_status.level <= 4
                    ){
                        player_status.level ++;
                    }      



            default:
                x_move = 0;
                y_move = 0;


        }

        if ( speed_activate && !(x_move == 0 && y_move == 0)){

            while ( Allowed2Move(x_move,y_move) ){
            
            
                if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 0){
                    board[player_status.level-1][player_status.y][player_status.x].type = '.';
                }
                else if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 1){
                    board[player_status.level-1][player_status.y][player_status.x].type = '#';
                }
                else if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 2){
                    board[player_status.level-1][player_status.y][player_status.x].type = '+';
                }
                else if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 3){
                    board[player_status.level-1][player_status.y][player_status.x].type = 's';
                }
                

                player_status.x += x_move;
                player_status.y += y_move;

                board[player_status.level-1][player_status.y][player_status.x].type = '@';
                
            }
            speed_activate = 0;

        }

        if ( Allowed2Move(x_move,y_move) ){
            
            
            if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 0){
                board[player_status.level-1][player_status.y][player_status.x].type = '.';
            }
            else if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 1){
                board[player_status.level-1][player_status.y][player_status.x].type = '#';
            }
            else if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 2){
                board[player_status.level-1][player_status.y][player_status.x].type = '+';
            }
            else if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 3){
                board[player_status.level-1][player_status.y][player_status.x].type = 's';
            }
            

            player_status.x += x_move;
            player_status.y += y_move;

            board[player_status.level-1][player_status.y][player_status.x].type = '@';
            
        }

    }


    for ( int i = 0; i < 6; i++ ){

        for ( int k = 0; k < rooms[player_status.level-1]->gold_count ; k++ ){

            if ( rooms[player_status.level-1][i].golds[k].x == player_status.x &&
                rooms[player_status.level-1][i].golds[k].y == player_status.y
                 && (rooms[player_status.level-1][i].golds[k].amount != 0)){

                
                last_gold_found = rooms[player_status.level-1][i].golds[k].amount;
                player_status.gold += rooms[player_status.level-1][i].golds[k].amount;
                rooms[player_status.level-1][i].golds[k].amount = 0;
                last_massage_type = 'g';
                

            }

            if ( rooms[player_status.level-1][i].potions[k].x == player_status.x &&
                rooms[player_status.level-1][i].potions[k].y == player_status.y
                 && (rooms[player_status.level-1][i].potions[k].picked_up == 0) &&
                rooms[player_status.level-1][i].potions[k].type == 0
                 ){

                
            
                potions[0] ++;
                rooms[player_status.level-1][i].potions[k].picked_up = 1;
                last_massage_type = 'p';
                

            }
            else if ( rooms[player_status.level-1][i].potions[k].x == player_status.x &&
                rooms[player_status.level-1][i].potions[k].y == player_status.y
                 && (rooms[player_status.level-1][i].potions[k].picked_up == 0) &&
                rooms[player_status.level-1][i].potions[k].type == 1
                 ){

                
                potions[1] ++;
                rooms[player_status.level-1][i].potions[k].picked_up = 1;
                last_massage_type = 'l';
                

            }
            else if ( rooms[player_status.level-1][i].potions[k].x == player_status.x &&
                rooms[player_status.level-1][i].potions[k].y == player_status.y
                 && (rooms[player_status.level-1][i].potions[k].picked_up == 0) &&
                rooms[player_status.level-1][i].potions[k].type == 2
                 ){

                
                potions[2] ++;
                rooms[player_status.level-1][i].potions[k].picked_up = 1;
                last_massage_type = 'k';
                

            }

        }

    }


}