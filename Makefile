all:
	emcc --bind -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s ALLOW_MEMORY_GROWTH=1 -o bin/index.html src/main.c --preload-file resources --use-preload-plugins
