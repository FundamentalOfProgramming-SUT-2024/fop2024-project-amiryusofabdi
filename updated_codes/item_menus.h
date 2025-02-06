void item_menu(){

    noecho();
    timeout(0);
    move(LINES/3-10,COLS/2 - 15);
    printw("Choose either of these foods!");
    move(LINES/3-8,COLS/2 - 15);
    printw("1) Normal Food (\U0001F34F): %d",pickedup_foods[0]+pickedup_foods[2]);
    move(LINES/3-6,COLS/2 - 15);
    printw("2) Top-Notch Food (\U0001F363): %d",pickedup_foods[1]);
    move(LINES/3-4,COLS/2 - 15);
    printw("3) Magical Food (\U0001F347): %d",pickedup_foods[3]);

    move(LINES/3,COLS/2 - 15);
    printw("Choose either of these potions!");
    move(LINES/3+2,COLS/2 - 15);
    printw("4) Health Potions (\u2695): %d",potions[0]);
    move(LINES/3+4,COLS/2 - 15);
    printw("5) Speed Potions (\u26A1): %d",potions[1]);
    move(LINES/3+6,COLS/2 - 15);
    printw("6) Damage Potions (\U0001F4AA): %d",potions[2]);

    move(LINES/3+10,COLS/2 - 15);
    printw("Choose either of these weapons!");
    move(LINES/3+12,COLS/2 - 15);
    printw("7) Mace (\u2692): \u221E");
    move(LINES/3+14,COLS/2 - 15);
    printw("8) Dagger (\U0001F5E1): %d",pickedup_guns[1]);
    move(LINES/3+16,COLS/2 - 15);
    printw("9) Magic-Wand (\U0001FA84): %d",pickedup_guns[2]);
    move(LINES/3+18,COLS/2 - 15);
    printw("0) Normal-Arrow (\u27B3): %d",pickedup_guns[3]);
    move(LINES/3+20,COLS/2 - 15);
    if ( pickedup_guns[4] == 0 ){
        printw("-) Sword(\u2694): 0");
    }
    else{
        printw("-) Sword(\u2694): \u221E");
    }

    int ch = getch();

    if (ch != ERR ){

        if ( ch == '1' ){

            int food_type = rand() % (pickedup_foods[0]+pickedup_foods[2]);
            if ( food_type < pickedup_foods[2] && pickedup_foods[2] > 0){      // picked up expired
                pickedup_foods[2] --;
                player_status.health -= 2;
            }
            else if (pickedup_foods[2] > 0){                                   // picked up normal
                pickedup_foods[0] --;
                player_status.health = 10;
                player_status.hunger = 6;
            }



        }
        else if ( ch == '2' ){

            if ( pickedup_foods[1] > 0 ){      // picked up top-notch
                pickedup_foods[1] --;
                player_status.health = 10;
                player_status.hunger = 6;
                player_status.strength += 5;
                using_food_phase = 0;
            }


        }
        else if ( ch == '3' ){

            if ( pickedup_foods[3] > 0 ){      // picked up magical
                pickedup_foods[3] --;
                player_status.health = 10;
                player_status.hunger = 6;
                player_status.speed = 2;
                using_food_phase = 1;
            }

            


        }
        else if ( ch == '4' && potions[0] > 0){
            player_status.health = 10;
            player_status.hunger = 6;
            potions[0] --;
            using_potion_phase = 0;
        }
        else if ( ch == '5' && potions[1] > 0){
            player_status.speed = 2;
            potions[1] --;
            using_potion_phase = 1;
            
        }
        else if ( ch == '6' && potions[2] > 0){
            player_status.strength += 5;
            potions[2] --; 
            using_potion_phase = 2;
        }
        else if ( ch == '7' ){
            player_status.current_weapon = 0;
        }
        else if ( ch == '8' && pickedup_guns[1] > 0){
            player_status.current_weapon = 1;
            pickedup_guns[1] --;
        }
        else if ( ch == '9' && pickedup_guns[2] > 0){
            player_status.current_weapon = 2;
            pickedup_guns[2] --;
        }
        else if ( ch == '0' && pickedup_guns[3] > 0){
            player_status.current_weapon = 3;
            pickedup_guns[3] --;
        }
        else if ( ch == '-' && pickedup_guns[4] > 0){
            player_status.current_weapon = 4;
            pickedup_guns[4] --;
        }
    }


}

