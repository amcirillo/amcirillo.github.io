#include "main_loop.h"
#include "../events/events.h"

void EMSCRIPTEN_KEEPALIVE mainloop(void *arg) {
    shapeStates *states = (shapeStates *) arg;
    SDL_Renderer *renderer;
    SDL_Rect *r;
    SDL_DisplayMode *dm = (SDL_DisplayMode *) malloc(sizeof(SDL_DisplayMode));
    SDL_RenderClear(renderer);
    for(int i = 0; i < NUM_SHAPES; i++) {
        renderer = states->states[i]->renderer;
        SDL_GetCurrentDisplayMode(0, dm);

        // check for events
        checkEvents();

        // black background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        
        r = (SDL_Rect *) malloc(sizeof(SDL_Rect));
        r->w = dm->w * 20 / 100;
        r->h = r->w;
        r->x = getXCoord(states->states[i], r, dm);
        r->y = getYCoord(states->states[i], r, dm);
        SDL_RenderCopy(renderer, states->states[i]->texture, r, r);
        free(r);
        SDL_RenderPresent(renderer);
    }
    free(dm);
}

int EMSCRIPTEN_KEEPALIVE getXCoord(context *ctx, SDL_Rect *r, SDL_DisplayMode *dm) {
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

int EMSCRIPTEN_KEEPALIVE getYCoord(context *ctx, SDL_Rect *r, SDL_DisplayMode *dm) {
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