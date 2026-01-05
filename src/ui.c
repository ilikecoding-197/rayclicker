#include "ui.h"
#include "raygui.h"

Vector2 UI_CenterPoint(Rectangle bounds) {
    Vector2 v;
    v.x = bounds.x + bounds.width * 0.5f;
    v.y = bounds.y + bounds.height * 0.5f;
    return v;
}

bool GuiButtonCentered(Vector2 center, int width, int height, const char *text) {
    Rectangle r = {
        center.x - width * 0.5f,
        center.y - height * 0.5f,
        (float)width,
        (float)height
    };
    return GuiButton(r, text);
}

void DrawTextCenteredAt(float cx, int y, const char *text, int fontSize, Color color) {
    int tw = MeasureText(text, fontSize);
    DrawText(text, (int)(cx - tw * 0.5f), y, fontSize, color);
}