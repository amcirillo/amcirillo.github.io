#include "main_loop/main_loop.h"

int EMSCRIPTEN_KEEPALIVE main() {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

    context *ctx = (context *) malloc(sizeof(context));
    ctx->renderer = renderer;
    ctx->x = 0;
    ctx->y = 0;
    ctx->leftRight = 0;
    ctx->upDown = 0;

    SDL_Surface *surface = IMG_Load("resources/resort.jpg");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    ctx->texture = texture;
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