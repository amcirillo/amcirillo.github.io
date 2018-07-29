all:
	emcc --bind -s USE_SDL=2 -s USE_SDL_IMAGE=2 -o index.html main.c --preload-file resources --use-preload-plugins
