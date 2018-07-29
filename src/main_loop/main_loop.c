#include "main_loop.h"
#include "../events/events.h"

void EMSCRIPTEN_KEEPALIVE mainloop(void *arg) {
    // check for events
    checkEvents();

    context *ctx = (context *) arg;
    SDL_Renderer *renderer = ctx->renderer;

    SDL_DisplayMode *dm = (SDL_DisplayMode *) malloc(sizeof(SDL_DisplayMode));
    SDL_GetCurrentDisplayMode(0, dm);

    // black background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect *r = (SDL_Rect *) malloc(sizeof(SDL_Rect));
    for(int i = 0; i < NUM_SHAPES; i++) {
        r->w = dm->w * 20 / 100;
        r->h = r->w;
        r->x = getXCoord(ctx->shapeState[i], r, dm);
        r->y = getYCoord(ctx->shapeState[i], r, dm);
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255 );
        SDL_RenderCopy(renderer, ctx->shapeState[i]->texture, r, r);
        SDL_RenderPresent(renderer);
    }
    free(r);
    free(dm);

}

int EMSCRIPTEN_KEEPALIVE getXCoord(shapeState *ctx, SDL_Rect *r, SDL_DisplayMode *dm) {
    int xCoord = 0;
    if(ctx->x == 0) {
        ctx->leftRight = 0;
        emscripten_log(0, "Going right");
    }
    if(ctx->x == dm->w - r->w) {
        ctx->leftRight = 1;
        emscripten_log(0, "Going left");
    }
    if(!ctx->leftRight) {
        xCoord = ctx->x + 2;
        ctx->x++;
    } else {
        xCoord = ctx->x - 2;
        ctx->x--;
    }
    return xCoord;
}

int EMSCRIPTEN_KEEPALIVE getYCoord(shapeState *ctx, SDL_Rect *r, SDL_DisplayMode *dm) {
    int yCoord = 0;
    if(ctx->y == 0) {
        ctx->upDown = 0;
        emscripten_log(0, "Going down");
    }
    if(ctx->y == dm->h - r->h) {
        ctx->upDown = 1;
        emscripten_log(0, "Going up");
    }
    if(!ctx->upDown) {
        yCoord = ctx->y + 2;
        ctx->y++;
    } else {
        yCoord = ctx->y - 2;
        ctx->y--;
    }
    return yCoord;
}