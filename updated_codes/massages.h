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
    else if ( type == 'n' ){
        printw("You picked up Normal food!");
    }
    else if ( type == 'e' ){
        attron(COLOR_PAIR(5));
        printw("You picked up Expired food!");
        attroff(COLOR_PAIR(5));
    }
    else if ( type == 'r' ){
        printw("You picked up Top-Notch food!");
    }
    else if ( type == 'm' ){
        printw("You picked up Magical food!");
    }
    else if ( type == 'f' ){
        printw("You are now on %d floor!",player_status.level);
    }
    else if ( type == 'd' ){
        printw("You picked up Dagger!");
    }
    else if ( type == 'w' ){
        printw("You picked up Magic-Wand!");
    }
    else if ( type == 'a' ){
        printw("You picked up Normal-Arrow!");
    }
    else if ( type == 'v' ){
        printw("You picked up Sword!");
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
        printw(PIZZA);
    }
    if ( player_status.hunger < 1 ){

        attron(COLOR_PAIR(5) | A_BLINK);
        printw("IM HUNGRYYY");
        attroff(COLOR_PAIR(5) | A_BLINK);

    }               

    move(LINES-1,60);
    printw("Gold: %d",player_status.gold);

    move(LINES-1,72);
    printw("Strength: %d",player_status.strength);

    move(LINES-1,84);
    printw("Speed: %d",player_status.speed);



}