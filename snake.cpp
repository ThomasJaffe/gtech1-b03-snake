#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "snake.hpp"


Snake::Snake(){
    
}

Snake::~Snake(){

}

void Snake::move(int direction){
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
