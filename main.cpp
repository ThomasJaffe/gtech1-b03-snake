#include <SDL2/SDL.h>

void keyboard() {
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP]) {
     if ()
  }
  if (keystates[SDL_SCANCODE_DOWN]) {
    ...
  }
  if (keystates[SDL_SCANCODE_LEFT]) {
    ...
  }
  if (keystates[SDL_SCANCODE_RIGHT]) {
    ...
  }
}