#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "snake.hpp"
#include "constants.h"
#include "MainSDLWindow.hpp"

Snake::Snake(){
    
}

Snake::~Snake(){

}

int Snake::move(int direction){

    if (direction == UP){
        posY -= STEP_SIZE;
        if (posY < 0)
            return 0;
    }
    if (direction == DOWN){
        posY += STEP_SIZE;
        if (posY > PLAYGROUND_HEIGHT)
            return 0;
    }
    if (direction == LEFT){
        posX -= STEP_SIZE;
        if (posX < 0)
            return 0;
    }
    if (direction == RIGHT){
        posX += STEP_SIZE;
        if (posX > PLAYGROUND_WIDTH)
            return 0;
    }
    return 1;
}

void Snake::setX(int x){
    this->posX = x;
}

void Snake::setY(int y){
    this->posY = y;
}

int Snake::getX(){
    return this->posX;
}

int Snake::getY(){
    return this->posY;
}
