#include <SDL.h>
#include <SDL_image.h>
#include <emscripten.h>

#ifndef MAIN_H
#define MAIN_H

#define NUM_SHAPES 2

typedef struct shapeState {
    SDL_Texture *texture;
    int leftRight;
    int upDown;
    int x;
    int y;
} shapeState;

typedef struct context {
    SDL_Renderer *renderer;
    shapeState *shapeState[NUM_SHAPES];
} context;

shapeState* initializeShape(SDL_Renderer *renderer, char *fileName, SDL_DisplayMode *dm);

#endif