#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "snake.hpp"
#include "constants.h"

Snake::Snake(){
    
}

Snake::~Snake(){

}

void Snake::move(int direction){

    if (direction == UP){
        posY -= 40;
        if (posY <= 0)
            posY = 0;
    }
    if (direction == DOWN){
        posY += 40;
        if (posY >= 600 - 40)
            posY = 600 - 40;
    }
    if (direction == LEFT){
        posX -= 40;
        if (posX <= 0)
            posX = 0;
    }
    if (direction == RIGHT){
        posX += 40;
        if (posX >= 800 - 40)
            posX = 800 - 40;
    }
}
