#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constants.h"
#include "MainSDLWindow.hpp"
#include "snake.hpp"

void SDL_LimitFPS(unsigned int limit);

int keypress(int direction) {
    const Uint8* keystates = SDL_GetKeyboardState(0);
    if (keystates[SDL_SCANCODE_UP]){
        if (direction != DOWN){
            direction = UP;
        }
    }
    if (keystates[SDL_SCANCODE_DOWN]){
        if (direction != UP){
            direction = DOWN;
        }
    }
    if (keystates[SDL_SCANCODE_LEFT]){
        if (direction != RIGHT){
            direction = LEFT;
        }
    }
    if (keystates[SDL_SCANCODE_RIGHT]){
        if (direction != LEFT){
            direction = RIGHT;
        }
    }
    return direction;
}

int main(int argc, char *argv[]){

    srand(time(NULL));

    unsigned int frame_limit = 0;
    frame_limit = SDL_GetTicks() + FPS_LIMIT;

    //Objects creation
    MainSDLWindow snakeWindow;

    //Window Initialization
    snakeWindow.Init("Snake", PLAYGROUND_WIDTH, PLAYGROUND_HEIGHT);

    Snake snake;
    snake.setcolor();

    int program_launched = 1;
    int direction = UP;
    SDL_Event event;

    while(program_launched){
        while(SDL_PollEvent(&event)){
            switch(event.type){

                case  SDL_KEYDOWN:
                    switch(event.key.keysym.sym){

                        case SDLK_ESCAPE:
                            program_launched = SDL_FALSE;

                            break;

                        default:
                            continue;

                    }
                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                
                    break;

                default:
                    break;
            }
        }

        //Snake movement
        direction = keypress(direction);
        program_launched = snake.move(direction);
        

        //Playground clearing
        SDL_SetRenderDrawColor(snakeWindow.GetRenderer(), GRAPHIC_PLAYGROUND_COLOUR);
        SDL_RenderClear(snakeWindow.GetRenderer());

        //Snake drawing
        SDL_SetRenderDrawColor(snakeWindow.GetRenderer(), snake.getcolorR(), snake.getcolorG(), snake.getcolorB(), 255);
        SDL_Rect rect = {snake.getX(), snake.getY(), HEAD_SIZE};

        SDL_RenderFillRect(snakeWindow.GetRenderer(), &rect);
        SDL_RenderPresent(snakeWindow.GetRenderer());

        SDL_Delay(117);
    }
}