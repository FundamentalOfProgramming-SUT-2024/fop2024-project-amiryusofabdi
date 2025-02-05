void spawn_player(int level){


    int RoomNumber = rand() % 6;

    player_status.x = rooms[level][RoomNumber].TopLeft_x + 1 + rand() % ( rooms[level][RoomNumber].length - 2 ); 
    player_status.y = rooms[level][RoomNumber].TopLeft_y + 1 + rand() % ( rooms[level][RoomNumber].width - 2 ); 

    board[level][player_status.y][player_status.x].type = '@';

}

int Allowed2Move(int x, int y){

    char new_tile = board[player_status.level-1][player_status.y + y][player_status.x + x].type;
    
    if ( new_tile == '#' || new_tile == '+' || new_tile == '.' || new_tile == 'b' || new_tile == 'g'
        || new_tile == 's' || new_tile == 'p' || new_tile == 'l' || new_tile == 'k' || new_tile == 't'
        || new_tile == 'e' || new_tile == 'r' || new_tile == 'm' || new_tile == 'n'
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

            case 'e':
                x_move = 1;
                y_move = -1;
                break;

            case 'q':
                
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

            case 'z':
                
                x_move = -1;
                y_move = 1;
                break;

            case 'c':
                
                x_move = 1;
                y_move = 1;
                break;

            case 'f':

                clear();
                if ( food_menu_phase == 0 ){
                    food_menu_phase = 1;
                    last_hunger_decrease = Hunger_Decrease;
                    last_health_decrease = Health_Decrease;
                    Hunger_Decrease = 0;
                    Health_Decrease = 0;

                }
                else{
                    food_menu_phase = 0;
                    Health_Decrease = last_health_decrease;
                    Hunger_Decrease = last_hunger_decrease;
                }
                

            case 'x':

                speed_activate = 1;
                

            case '.':

                if ( rooms[player_status.level-1][RoomsWithStairs[player_status.level-1]].stairs_x == player_status.x &&
                   rooms[player_status.level-1][RoomsWithStairs[player_status.level-1]].stairs_y == player_status.y &&
                   player_status.level <= 4
                    ){
                        player_status.level ++;
                        last_massage_type = 'f';
                    }      



            default:
                x_move = 0;
                y_move = 0;


        }

        x_move *= player_status.speed;
        y_move *= player_status.speed;

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
                else if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 7 ){
                    board[player_status.level-1][player_status.y][player_status.x].type = 't';
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
            else if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 7 ){
                board[player_status.level-1][player_status.y][player_status.x].type = 't';
                last_massage_type = 't';
            }
            else if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 8 ){
                board[player_status.level-1][player_status.y][player_status.x].type = '.';
                last_massage_type = 'n';
            }
            else if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 9 ){
                board[player_status.level-1][player_status.y][player_status.x].type = '.';
                last_massage_type = 'r';
            }
            else if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 10 ){
                board[player_status.level-1][player_status.y][player_status.x].type = '.';
                last_massage_type = 'e';
            }
            else if ( board[player_status.level-1][player_status.y][player_status.x].main_type == 11 ){
                board[player_status.level-1][player_status.y][player_status.x].type = '.';
                last_massage_type = 'm'; 
            }   

            player_status.x += x_move;
            player_status.y += y_move;

            board[player_status.level-1][player_status.y][player_status.x].type = '@';
            
        }

    }


    for ( int i = 0; i < 6; i++ ){

        for ( int k = 0; k < rooms[player_status.level-1][i].gold_count ; k++ ){

            // GOLDS
            if ( rooms[player_status.level-1][i].golds[k].x == player_status.x &&
                rooms[player_status.level-1][i].golds[k].y == player_status.y
                 && (rooms[player_status.level-1][i].golds[k].amount != 0)){

                
                last_gold_found = rooms[player_status.level-1][i].golds[k].amount;
                player_status.gold += rooms[player_status.level-1][i].golds[k].amount;
                rooms[player_status.level-1][i].golds[k].amount = 0;
                last_massage_type = 'g';
                

            }
        }
        for ( int k = 0; k < rooms[player_status.level-1][i].food_count ; k++ ){
        
            if ( rooms[player_status.level-1][i].foods[k].x == player_status.x &&
                rooms[player_status.level-1][i].foods[k].y == player_status.y
                 && (rooms[player_status.level-1][i].foods[k].picked_up == 0)){

                switch (board[player_status.level-1][player_status.y][player_status.x].main_type)
                {
                    case 8:
                        last_massage_type = 'n';
                        pickedup_foods[0] ++;
                        break;
                    case 9:
                        last_massage_type = 'r';
                        pickedup_foods[1] ++;
                        break;
                    case 10:
                        last_massage_type = 'e';
                        pickedup_foods[2] ++;
                        break;
                    case 11:
                        last_massage_type = 'm';
                        pickedup_foods[3] ++;
                        break;
                    default:
                        break;
                }

                rooms[player_status.level-1][i].foods[k].picked_up = 1;
                

            }
        }
        for ( int k = 0; k < rooms[player_status.level-1][i].potion_count ; k++ ){
            // POTIONS
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
