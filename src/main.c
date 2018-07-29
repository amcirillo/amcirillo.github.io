#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main_loop/main_loop.h"

int EMSCRIPTEN_KEEPALIVE main() {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_DisplayMode dm;
    SDL_GetCurrentDisplayMode(0, &dm);
    SDL_CreateWindowAndRenderer(dm.w, dm.h, 0, &window, &renderer);
    emscripten_log(0, "Screen resolution: %dx%d", dm.w, dm.h);
 
    context *ctx = initializeContext(renderer, "resources/resort.jpg", &dm);

    SDL_Surface *surface = IMG_Load("resources/resort.jpg");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Surface *stoneSurface = IMG_Load("resources/stone.jpg");
    SDL_Texture *stoneTexture = SDL_CreateTextureFromSurface(renderer, stoneSurface);
    emscripten_log(0, "Texture created");
    const int simulate_infinite_loop = 1; // call the function repeatedly
    const int fps = -1; // call the function as fast as the browser wants to render (typically 60fps)
    emscripten_log(0, "Entering main loop");
    emscripten_set_main_loop_arg(mainloop, ctx, fps, simulate_infinite_loop);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    free(ctx);
    return EXIT_SUCCESS;
}

context* initializeContext(SDL_Renderer *renderer, char *fileName, SDL_DisplayMode *dm) {
    time_t t;
    srand((unsigned) time(&t));
    SDL_Surface *surface = IMG_Load(fileName);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    context *ctx = (context *) malloc(sizeof(context));
    ctx->renderer = renderer;
    ctx->x = rand() % (dm->w / 2);
    ctx->y = rand() % (dm->h / 2);
    ctx->leftRight = rand() % 2;
    ctx->upDown = rand() % 2;
    ctx->texture = texture;
    return ctx;
}