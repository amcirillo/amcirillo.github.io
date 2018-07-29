#include "events.h"

void checkEvents() {
    SDL_Event *event = (SDL_Event *) malloc(sizeof(SDL_Event));
    while(SDL_PollEvent(event)) {
        switch (event->type) {
            case SDL_MOUSEMOTION:
                emscripten_log(0, "Detected mouse motion event");
                break;
            case SDL_MOUSEBUTTONDOWN:
                emscripten_log(0, "Detected mouse button down event");
                break;
            case SDL_MOUSEBUTTONUP:
                emscripten_log(0, "Detected mouse button up event");
                break;
            case SDL_KEYDOWN:
                emscripten_log(0, "Detected keyboard down event");
                break;
            case SDL_KEYUP:
                emscripten_log(0, "Detected keyboard up event");
                break;
            default:
                emscripten_log(0, "Detected unknown event");
        }
    }
    free(event);
}