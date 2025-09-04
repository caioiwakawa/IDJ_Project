#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include <iostream>
#include <cassert>
#include <Game.h>

Game* Game::GetInstance()
{
    if (Game::instance == nullptr)
    {
        new Game();
    }
    return Game::instance;
}

Game::Game(std::string title, int width, int height)
{
    assert(Game::instance == nullptr);

    Game::instance = this;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER))
    {
        std::cout << "Error: " << SDL_GetError();
        std::exit(1);
    }
    if(!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF))
    {
        std::cout << "Error: IMG_Init";
        std::exit(1);
    }
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))
    {
        std::cout << "Error: Mix_OpenAudio";
        std::exit(1);
    }
    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(window == nullptr or renderer == nullptr)
    {
        std::cout << "Error: Window or Renderer";
        std::exit(1);
    }

}