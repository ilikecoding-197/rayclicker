#ifndef GAME_H
#define GAME_H

#include "result.h"

typedef struct {
    double money;
    int width;
    int height;
} Game;

Result Game_init(Game *game, int width, int height);
Result Game_run(Game *game);

static inline float Game_center_x(Game *game) {
    return game->width / 2.0f;
}

static inline float Game_center_y(Game *game) {
    return game->height / 2.0f;
}

#endif // GAME_H