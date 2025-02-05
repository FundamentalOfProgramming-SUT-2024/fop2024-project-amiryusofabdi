void food_menu(){

    noecho();
    // timeout(-1);
    move(LINES/5,COLS/2 - 15);
    printw("Choose either of these foods!");
    move(LINES/3,COLS/2 - 15);
    printw("1) Normal Food (\U0001F34F): %d",pickedup_foods[0]+pickedup_foods[2]);
    move(LINES/3+2,COLS/2 - 15);
    printw("2) Top-Notch Food (\U0001F363): %d",pickedup_foods[1]);
    move(LINES/3+4,COLS/2 - 15);
    printw("3) Magical Food (\U0001F347): %d",pickedup_foods[3]);

    int ch = getch();

    if (ch != ERR ){

        if ( ch == '1' ){

            int food_type = rand() % (pickedup_foods[0]+pickedup_foods[2]);
            // mvprintw(0,10,"salam");
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
                using_potion_phase = 0;
            }


        }
        else if ( ch == '3' ){

            if ( pickedup_foods[3] > 0 ){      // picked up magical
                pickedup_foods[3] --;
                player_status.health = 10;
                player_status.hunger = 6;
                player_status.speed = 2;
                using_potion_phase = 1;
            }

            


        }

    }


}