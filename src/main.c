#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "game.h"

// why
static inline float TextToFloat(const char *text) {
    return atof(text);
}

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define WIDTH 800
#define HEIGHT 450

int main() {
	Game game;
	Result res;

	res = Game_init(&game, WIDTH, HEIGHT);
	if (res != RES_OK) {
		return 1;
	}

	res = Game_run(&game);
	if (res != RES_OK) {
		return 1;
	}

	return 0;
}
