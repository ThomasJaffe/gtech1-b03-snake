#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "MainSDLWindow.hpp"
#define FPS_LIMIT 250

void SDL_LimitFPS(unsigned int limit);

int main(int argc, char *argv[])
{
    unsigned int frame_limit = 0;
    frame_limit = SDL_GetTicks() + FPS_LIMIT;

    //Objects creation//
    MainSDLWindow snakeWindow;

    //Window Initialization//
    snakeWindow.Init("Snake", 800, 600);

    SDL_bool program_launched = SDL_TRUE;

    while(program_launched){

        const Uint8* keystates = SDL_GetKeyboardState(0);
        SDL_Event event;

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
        
        SDL_SetRenderDrawColor(snakeWindow.GetRenderer(), 255, 0, 0, 255);
        SDL_Rect rect = {400, 300, 20, 20};
        SDL_RenderFillRect(snakeWindow.GetRenderer(), &rect);
        SDL_RenderPresent(snakeWindow.GetRenderer());

        SDL_Delay(20);
        // frame_limit = SDL_GetTicks() + FPS_LIMIT;
        // SDL_LimitFPS(frame_limit); 

    }
}

void SDL_LimitFPS(unsigned int limit){
    unsigned int ticks = SDL_GetTicks();

    if(limit < ticks){
        return;
    }
    else if(limit > ticks + FPS_LIMIT){
        SDL_Delay(FPS_LIMIT);
    }
    else{
        SDL_Delay(limit - ticks);
    }
}

// void Snake::print(){

//     SDL_RenderClear(pgRenderer);

//     SDL_Rect rectangle;
//     rectangle.x = posX;
//     rectangle.y = posY;
//     rectangle.w = HEAD_SIZE;
//     rectangle.h = HEAD_SIZE;

//     if(SDL_RenderFillRect(pgRenderer, &rectangle) != 0){
//         ExitWithError("Impossible de dessiner un rectangle");
//     }

//     if(SDL_SetRenderDrawColor(pgRenderer, 255, 0, 0, 255) != 0){
//         ExitWithError("Impossible de changer la couleur pour le rendu");
//     }

//     SDL_RenderPresent(pgRenderer);
// }