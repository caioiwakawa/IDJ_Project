#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <string>
#include <State.h>

class Game {
    private:

        static Game* instance;
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;

        Game() {}
        Game(std::string title, int width, int height) {}
    
    public:

        ~Game() {}
        void Run() {}

        SDL_Renderer* GetRenderer() {return renderer;}
        State* GetState() {return state;}
        static Game* GetInstance() {return instance;}

};

#endif