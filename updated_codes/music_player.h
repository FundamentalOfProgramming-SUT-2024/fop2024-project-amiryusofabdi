void play_music(char *track_name){

    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    Mix_Music *music = Mix_LoadMUS(track_name);
    Mix_PlayMusic(music, -1);

}