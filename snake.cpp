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
        if (posY >= PLAYGROUND_HEIGHT - 40)
            posY = PLAYGROUND_HEIGHT - 40;
    }
    if (direction == LEFT){
        posX -= 40;
        if (posX <= 0)
            posX = 0;
    }
    if (direction == RIGHT){
        posX += 40;
        if (posX >= PLAYGROUND_WIDTH - 40)
            posX = PLAYGROUND_WIDTH - 40;
    }
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
