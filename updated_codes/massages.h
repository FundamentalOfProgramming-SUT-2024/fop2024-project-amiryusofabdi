void massage(){

}

void status(){

    move(LINES-1,0);
    printw("Level: %d",player_status.level);

    move(LINES-1,12);
    printw("Hits: %d",player_status.hits);

    move(LINES-1,24);
    printw("Str: %d",player_status.strength);

    move(LINES-1,36);
    printw("Gold: %d",player_status.gold);

    move(LINES-1,48);
    printw("Armor: %d",player_status.armor);

    move(LINES-1,60);
    printw("Exp: %d",player_status.experience);



}