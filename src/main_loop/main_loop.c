#include "main_loop.h"

void EMSCRIPTEN_KEEPALIVE mainloop(void *arg) {
    context *ctx = (context *) arg;
    SDL_Renderer *renderer = ctx->renderer;

    // black background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    SDL_Rect *r = (SDL_Rect *) malloc(sizeof(SDL_Rect));
    r->w = 400;
    r->h = 400;
    r->x = getXCoord(ctx, r);
    r->y = getYCoord(ctx, r);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255 );
    SDL_RenderCopy(renderer, ctx->texture, r, r);
    SDL_RenderPresent(renderer);
    free(r);
}

int EMSCRIPTEN_KEEPALIVE getXCoord(context *ctx, SDL_Rect *r) {
    int xCoord = 0;
    if(ctx->x == 0) {
        ctx->leftRight = 0;
        printf("Going right\n");
    }
    if(ctx->x == WIDTH - r->w) {
        ctx->leftRight = 1;
        printf("Going left\n");
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

int EMSCRIPTEN_KEEPALIVE getYCoord(context *ctx, SDL_Rect *r) {
    int yCoord = 0;
    if(ctx->y == 0) {
        ctx->upDown = 0;
        printf("Going down\n");
    }
    if(ctx->y == HEIGHT - r->h) {
        ctx->upDown = 1;
        printf("Going up\n");
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