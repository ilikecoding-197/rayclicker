#include "game.h"
#include "raylib.h"
#include "raygui.h"
#include "result.h"
#include "ui.h"

#define TITLE "Rayclicker"

Color IntToColor(int value) {
    Color c;
    c.a = (value >> 0) & 0xFF;
    c.r = (value >> 8) & 0xFF;
    c.g = (value >> 16) & 0xFF;
    c.b = (value >> 24) & 0xFF;
    return c;
}

Color GetGuiColor(int guiElement, int colorType) {
    return IntToColor(GuiGetStyle(guiElement, colorType));
}

Result Game_init(Game *game, int width, int height) {
    Result res;

    game->money = 0.0;
    game->width = width;
    game->height = height;
    return RES_OK;
}

#define BTN_WIDTH 100
#define BTN_HEIGHT 100

void center_point(Vector2 *p, Rectangle *bounds) {
    p->x = bounds->x + bounds->width / 2;
    p->y = bounds->y + bounds->height / 2;
}

static void Game_draw(Game *game) {
    const int LABEL_FONT_SIZE = 20;
    int sw = game->width;
    int sh = game->height;

    ClearBackground(GetGuiColor(DEFAULT, BACKGROUND_COLOR));
    DrawFPS(10, 10);

    Vector2 pos = { 0 };
    pos = UI_CenterPoint((Rectangle){ 0, 30, sw, sh - 30 });

    if (GuiButtonCentered(pos, BTN_WIDTH, BTN_HEIGHT, "Click me")) {
        game->money += 1.0;
    }

    char text[64];
    snprintf(text, sizeof(text), "Money: %.2f", game->money);

    DrawTextCenteredAt(pos.x, 10, text, LABEL_FONT_SIZE, GetGuiColor(LABEL, TEXT_COLOR_NORMAL));
}

static void Game_update(Game *game) {
    if (IsWindowResized()) {
        game->width = GetScreenWidth();
        game->height = GetScreenHeight();
    }
}

Result Game_run(Game *game) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE); 
    InitWindow(game->width, game->height, TITLE);
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        Game_update(game);

        BeginDrawing();
        Game_draw(game);
        EndDrawing();
    }

    CloseWindow();

    return RES_OK;
}