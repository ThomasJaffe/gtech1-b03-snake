#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "snake.hpp"


Snake::Snake(){
    
}

Snake::~Snake(){

}

void Snake::move(int direction){

    const Uint8* keystates = SDL_GetKeyboardState(0);


    // Player input.
    if (keystates[SDL_SCANCODE_UP]){
        if (direction == 1){
            direction = 1;
        }
        else{
            direction = 0;
        }
    }

    if (keystates[SDL_SCANCODE_DOWN]){
        if (direction == 0){
            direction = 0;
        }
        else{
            direction = 1;
        }
    }

    if (keystates[SDL_SCANCODE_LEFT]){
        if (direction == 3){
            direction = 3;
        }
        else{
            direction = 2;
        }
    }

    if (keystates[SDL_SCANCODE_RIGHT]){
        if (direction == 2){
            direction = 2;
        }
        else{
            direction = 3;
        }
    }

    // Head Direction.

    if (direction == 0){
        posY -= 40;
        if (posY <= 0)
            posY = 0;
    }
    if (direction == 1){
        posY += 40;
        if (posY >= 600 - 40)
            posY = 600 - 40;
    }
    if (direction == 2){
        posX -= 40;
        if (posX <= 0)
            posX = 0;
    }
    if (direction == 3){
        posX += 40;
        if (posX >= 800 - 40)
            posX = 800 - 40;
    }
}
