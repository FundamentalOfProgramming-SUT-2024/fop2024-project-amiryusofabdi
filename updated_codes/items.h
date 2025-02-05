void spawn_gold(int coefi,int level,int room,int normal_gold_density ){  // coefi * size / 50

    int room_size = rooms[level][room].length * rooms[level][room].width;

    rooms[level][room].gold_count = coefi * room_size / 70;
    
    for (int i = 0; i < rooms[level][room].gold_count; i++){

        rooms[level][room].golds[i].x = rooms[level][room].TopLeft_x + 1 + rand() % (rooms[level][room].length-2);
        rooms[level][room].golds[i].y = rooms[level][room].TopLeft_y + 1 + rand() % (rooms[level][room].width-2);
        
        int gold_type = ( rand() % normal_gold_density ); // 0 -> black gold         other -> normal
        
        if ( gold_type == 0 ){          // black gold!
            
            rooms[level][room].golds[i].type = 1;
            rooms[level][room].golds[i].amount = 80 + rand() % 50;

            board[level][rooms[level][room].golds[i].y][rooms[level][room].golds[i].x].type = 'b';  // b for black gold


        }
        else{                           // normal gold!

            rooms[level][room].golds[i].type = 0;
            rooms[level][room].golds[i].amount = 20 + rand() % 30;
            board[level][rooms[level][room].golds[i].y][rooms[level][room].golds[i].x].type = 'g';  // g for normal gold

        }

    }


}


void spawn_potion(int coefi, int level, int room){

    int room_size = rooms[level][room].length * rooms[level][room].width;

    rooms[level][room].potion_count = coefi * room_size / 100;
    
    for (int i = 0; i < rooms[level][room].potion_count; i++){

        rooms[level][room].potions[i].picked_up = 0;
        rooms[level][room].potions[i].x = rooms[level][room].TopLeft_x + 1 + rand() % (rooms[level][room].length-2);
        rooms[level][room].potions[i].y = rooms[level][room].TopLeft_y + 1 + rand() % (rooms[level][room].width-2);
        
        int potion_type = ( rand() % 3 ); // 0 -> Health      1 ->    Speed       2-> Damage
        
        if ( potion_type == 0 ){          // health
            
            rooms[level][room].potions[i].type = 0;
            board[level][rooms[level][room].potions[i].y][rooms[level][room].potions[i].x].type = 'p';  // p for health


        }
        else if ( potion_type == 1 ){                           // speed

            rooms[level][room].potions[i].type = 1;
            board[level][rooms[level][room].potions[i].y][rooms[level][room].potions[i].x].type = 'l';  // l for speed

        }
        else if ( potion_type == 2 ){                           // damage

            rooms[level][room].potions[i].type = 2;
            board[level][rooms[level][room].potions[i].y][rooms[level][room].potions[i].x].type = 'k';  // k for damage

        }

    }

}


void spawn_food(int level, int room){

    int room_size = rooms[level][room].length * rooms[level][room].width;

    rooms[level][room].food_count = room_size / 100;
    
    for (int i = 0; i < rooms[level][room].food_count; i++){

        rooms[level][room].foods[i].picked_up = 0;
        rooms[level][room].foods[i].x = rooms[level][room].TopLeft_x + 1 + rand() % (rooms[level][room].length-2);
        rooms[level][room].foods[i].y = rooms[level][room].TopLeft_y + 1 + rand() % (rooms[level][room].width-2);
        
        int food_type = ( rand() % 4 ); // 0:normal food    1: top-notch food   2: magical food 
                                        // 3 expired food
        
        if ( food_type == 0 ){          // normal food
            
            rooms[level][room].foods[i].type = 0;
            board[level][rooms[level][room].foods[i].y][rooms[level][room].foods[i].x].type = 'n'; // n for normal food
            board[level][rooms[level][room].foods[i].y][rooms[level][room].foods[i].x].main_type = 8;

        }
        else if (food_type == 1){                           // top-notch food

            rooms[level][room].golds[i].type = 1;
            board[level][rooms[level][room].foods[i].y][rooms[level][room].foods[i].x].type = 'r';  // r for top-notch food
            board[level][rooms[level][room].foods[i].y][rooms[level][room].foods[i].x].main_type = 9;

        }
        else if (food_type == 2){                           // magical food

            rooms[level][room].golds[i].type = 2;
            board[level][rooms[level][room].foods[i].y][rooms[level][room].foods[i].x].type = 'm';  // m for magical food
            board[level][rooms[level][room].foods[i].y][rooms[level][room].foods[i].x].main_type = 11;

        }
        else if (food_type == 3){                           // expired food

            rooms[level][room].golds[i].type = 3;
            board[level][rooms[level][room].foods[i].y][rooms[level][room].foods[i].x].type = 'e';  // e for expired food
            board[level][rooms[level][room].foods[i].y][rooms[level][room].foods[i].x].main_type = 10;

        }
        
    }

}

void spawn_gold(int coefi,int level,int room,int normal_gold_density ){  // coefi * size / 50

    int room_size = rooms[level][room].length * rooms[level][room].width;

    rooms[level][room].gold_count = coefi * room_size / 70;
    
    for (int i = 0; i < rooms[level][room].gold_count; i++){

        rooms[level][room].golds[i].x = rooms[level][room].TopLeft_x + 1 + rand() % (rooms[level][room].length-2);
        rooms[level][room].golds[i].y = rooms[level][room].TopLeft_y + 1 + rand() % (rooms[level][room].width-2);
        
        int gold_type = ( rand() % normal_gold_density ); // 0 -> black gold         other -> normal
        
        if ( gold_type == 0 ){          // black gold!
            
            rooms[level][room].golds[i].type = 1;
            rooms[level][room].golds[i].amount = 80 + rand() % 50;

            board[level][rooms[level][room].golds[i].y][rooms[level][room].golds[i].x].type = 'b';  // b for black gold


        }
        else{                           // normal gold!

            rooms[level][room].golds[i].type = 0;
            rooms[level][room].golds[i].amount = 20 + rand() % 30;
            board[level][rooms[level][room].golds[i].y][rooms[level][room].golds[i].x].type = 'g';  // g for normal gold

        }

    }


}