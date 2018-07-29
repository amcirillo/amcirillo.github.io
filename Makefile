CC = emcc
SOURCE_FILES = src/main.c src/main_loop/main_loop.c
CFLAGS = --bind -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s ALLOW_MEMORY_GROWTH=1 --preload-file resources --use-preload-plugins

all:
	$(CC) $(CFLAGS) $(SOURCE_FILES) -o bin/index.html

clean:
	rm bin/*