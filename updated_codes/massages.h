void massage(char type){

    move (0,0);

    if (type == 'w'){
        printw("Dear %s, Enjoy the game!",player_username);
    }

    else if (type == 'g'){
        printw("You found %d gold pieces!",last_gold_found);
    }

    else if ( type == 'p'){
        printw("You picked up Health Potion!");
    }

    else if ( type == 'l'){
        printw("You picked up Speed Potion!");
    }

    else if ( type == 'k'){
        printw("You picked up Damage Potion!");
    }
    else if ( type == 't' ){
        printw("You got into a trap!");
    }
}


void status(){

    move(LINES-1,0);
    printw("Level: %d",player_status.level);

    move(LINES-1,12);
    printw("Health: ");
    for(int i = 0; i < player_status.health; i++){
        
        // if ( player_status.health <= 2 ){
        //     printw(HEART);
        // }
        printw(HEART);

    }

    move(LINES-1,36);
    printw("Hunger: ");
    for(int i = 0; i < player_status.hunger; i++){
        printw(FOOD);
    }
    if ( player_status.hunger < 1 ){

        attron(COLOR_PAIR(5) | A_BLINK);
        printw("IM HUNGRYYY");
        attroff(COLOR_PAIR(5) | A_BLINK);

    }               

    move(LINES-1,60);
    printw("Gold: %d",player_status.gold);

    move(LINES-1,72);
    printw("Armor: %d",player_status.armor);

    move(LINES-1,84);
    printw("Exp: %d",player_status.experience);



}