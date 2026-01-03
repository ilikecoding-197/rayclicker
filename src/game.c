#include "game.h"
#include "raylib.h"
#include "raygui.h"
#include "result.h"

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

static void Game_draw(Game *game) {
    ClearBackground(GetGuiColor(DEFAULT, BACKGROUND_COLOR));
    DrawFPS(10, 10);

    Rectangle r;
    r.x = Game_center_x(game) - 50;
    r.y = Game_center_y(game) - 50;
    r.width = 100;
    r.height = 100;
    if (GuiButton(r, "Click me")) {
        game->money += 1.0;
    }

    char *text = TextFormat("Money: %g", game->money);
    DrawText(text,
        Game_center_x(game) - MeasureText(text, 20) / 2, 10,
        20, GetGuiColor(LABEL, TEXT_COLOR_NORMAL));
}

static void Game_update(Game *game) {}

Result Game_run(Game *game) {
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