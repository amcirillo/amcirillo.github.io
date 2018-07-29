#include "events.h"

void checkEvents() {
    SDL_Event *event = (SDL_Event *) malloc(sizeof(SDL_Event));
    while(SDL_PollEvent(event)) {
        switch (event->type) {
            case SDL_MOUSEMOTION:
                emscripten_log(0, "Detected mouse motion event");
                emscripten_log(0, "Mouse position: %d, %d", event->motion.x, event->motion.y);
                break;
            case SDL_MOUSEBUTTONDOWN:
                emscripten_log(0, "Detected mouse button down event");
                break;
            case SDL_MOUSEBUTTONUP:
                emscripten_log(0, "Detected mouse button up event");
                break;
            case SDL_KEYDOWN:
                emscripten_log(0, "Detected keyboard down event for key: %s", SDL_GetScancodeName(event->key.keysym.scancode));
                break;
            case SDL_KEYUP:
                emscripten_log(0, "Detected keyboard up event for key: %s",  SDL_GetScancodeName(event->key.keysym.scancode));
                break;
            default:
                emscripten_log(0, "Detected unknown event: %d", event->type);
                break;
        }
    }
    free(event);
}