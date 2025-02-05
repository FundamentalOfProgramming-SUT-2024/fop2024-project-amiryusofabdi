void item_menu(){

    noecho();

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

    }


}

