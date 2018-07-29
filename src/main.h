#include <SDL.h>
#include <SDL_image.h>
#include <emscripten.h>

#ifndef MAIN_H
#define MAIN_H

#define WIDTH 1920
#define HEIGHT 1080

typedef struct context {
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    int leftRight;
    int upDown;
    int x;
    int y;
} context;

#endif