/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Sprite screen filler
*/

#include "rpg.h"

static void fill_tile(scene_t *game, int nb_tiles, int x, int y)
{
	sfVector2f pos = {0, 0};

	if (game->map.tilemap[y][x] <= nb_tiles &&
	game->map.tilemap[y][x] != 0) {
		game->map.screen[y][x] =
		sfSprite_copy(game->map.tiles[game->map.tilemap[y][x]]->spr);
		pos.x = GXO(x);
		pos.y = GYO(y);
		sfSprite_setPosition(game->map.screen[y][x], pos);
	}
}

void fill_tiles_screen(scene_t *game, int nb_tiles)
{
	for (int y = 0; y < 17; y++)
		for (int x = 0; x < 16; x++)
			fill_tile(game, nb_tiles, x, y);
}