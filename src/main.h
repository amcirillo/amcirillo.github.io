#include <SDL.h>
#include <SDL_image.h>
#include <emscripten.h>

#ifndef MAIN_H
#define MAIN_H

#define NUM_SHAPES 10

typedef struct context {
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    int leftRight;
    int upDown;
    int x;
    int y;
} context;

typedef struct shapeStates {
    context *states[NUM_SHAPES];
} shapeStates;

context* initializeContext(SDL_Renderer *renderer, SDL_DisplayMode *dm, char *fileName);

#endif