#include <SDL.h>
#include <SDL_image.h>
#include <emscripten.h>

#ifndef MAIN_H
#define MAIN_H

#define NUM_SHAPES 3

typedef struct context {
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    int leftRight;
    int upDown;
    int x;
    int y;
} context;

context* initializeContext(SDL_Renderer *renderer, char *fileName, SDL_DisplayMode *dm);

#endif