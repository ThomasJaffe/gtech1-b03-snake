#include "MainSDLWindow.hpp"
#include <SDL2/SDL.h>

int main(void){
    MainSDLWindow sdlwin;
    sdlwin.Init("Snake",800,600);
    SDL_Delay(5000);
}