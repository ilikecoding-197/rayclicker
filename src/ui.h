#pragma once
#include "raylib.h"
#include <stdbool.h>

Vector2 UI_CenterPoint(Rectangle bounds);

/* center-based button: returns true when clicked */
bool GuiButtonCentered(Vector2 center, int width, int height, const char *text);

/* draw text horizontally centered at given x (y is top) */
void DrawTextCenteredAt(float cx, int y, const char *text, int fontSize, Color color);