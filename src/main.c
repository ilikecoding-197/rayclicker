#include <stdio.h>
#include "raylib.h"

#define WIDTH 800
#define HEIGHT 450
#define TITLE "Rayclicker"

int main() {
	InitWindow(WIDTH, HEIGHT, TITLE);
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();

		{
			ClearBackground(RAYWHITE);
			DrawFPS(10, 10);
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
