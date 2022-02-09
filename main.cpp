#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
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
    printf("%d", direction);
    return direction;
}


int main(int argc, char *argv[])
{
    unsigned int frame_limit = 0;
    frame_limit = SDL_GetTicks() + FPS_LIMIT;

    //Objects creation//
    MainSDLWindow snakeWindow;

    //Window Initialization//
    snakeWindow.Init("Snake", PLAYGROUND_WIDTH, PLAYGROUND_HEIGHT);

    printf("Initialisation programme\n");

    Snake snake;

    SDL_bool program_launched = SDL_TRUE;
    int direction = UP;
    SDL_Event event;

    while(program_launched){
        while(SDL_PollEvent(&event)){
            switch(event.type){

                case  SDL_KEYDOWN:
                    switch(event.key.keysym.sym){

                        case SDLK_ESCAPE:
                            program_launched = SDL_FALSE;
                            printf("\nFermeture programme\n");
                            break;

                        default:
                            continue;

                    }
                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                    printf("\nFermeture programme\n");
                    break;

                default:
                    break;
            }
        }

        direction = keypress(direction);
        snake.move(direction);
        
        SDL_SetRenderDrawColor(snakeWindow.GetRenderer(), GRAPHIC_PLAYGROUND_COLOUR);
        SDL_RenderClear(snakeWindow.GetRenderer());
        SDL_SetRenderDrawColor(snakeWindow.GetRenderer(), GRAPHIC_SNAKE_COLOUR_HEAD);
        SDL_Rect rect = {snake.getX(), snake.getY(), HEAD_SIZE};
        SDL_RenderFillRect(snakeWindow.GetRenderer(), &rect);
        SDL_RenderPresent(snakeWindow.GetRenderer());

        SDL_Delay(117);
        // frame_limit = SDL_GetTicks() + FPS_LIMIT;
        // SDL_LimitFPS(frame_limit); 
    }
}
 
// void SDL_LimitFPS(unsigned int limit){
//    unsigned int ticks = SDL_GetTicks();

//    if(limit < ticks){
//        return;
//    }
//    else if(limit > ticks + FPS_LIMIT){
//        SDL_Delay(FPS_LIMIT);
//    }
//    else{
//        SDL_Delay(limit - ticks);
//    }
// }