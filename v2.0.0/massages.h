void massage(char type){

    move (0,0);

    if (type == 'g'){
        printw("You found %d gold pieces!",last_gold_found);
    }

}


void status(){

    move(LINES-1,0);
    printw("Level: %d",player_status.level);

    move(LINES-1,12);
    printw("Health(Max100): %d",player_status.hits);

    move(LINES-1,36);
    printw("Hunger(Max200): %d",player_status.health);

    move(LINES-1,60);
    printw("Gold: %d",player_status.gold);

    move(LINES-1,72);
    printw("Armor: %d",player_status.armor);

    move(LINES-1,84);
    printw("Exp: %d",player_status.experience);



}