#include "../main.h"

#ifndef MAIN_LOOP_H
#define MAIN_LOOP_H

void EMSCRIPTEN_KEEPALIVE mainloop(void *arg);
int EMSCRIPTEN_KEEPALIVE getXCoord(shapeState *ctx, SDL_Rect *r, SDL_DisplayMode *dm);
int EMSCRIPTEN_KEEPALIVE getYCoord(shapeState *ctx, SDL_Rect *r, SDL_DisplayMode *dm);
int EMSCRIPTEN_KEEPALIVE getSquareWidth(SDL_DisplayMode *dm);

#endif