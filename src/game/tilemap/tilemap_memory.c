/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Memory handler for tilemaps
*/

#include "rpg.h"

void get_tiles_from_file(scene_t *game, int nb_tiles, char *tiles_file)
{
	sfIntRect rect = {0, 0, 60, 60};
	sfVector2f pos = {0, 0};

	game->map.nb_tiles = nb_tiles;
	game->map.tiles = malloc(sizeof(sprite_t *) * nb_tiles + 2);
	game->map.tiles[0] = NULL;
	for (int i = 1; i <= nb_tiles; i++) {
		game->map.tiles[i] = malloc(sizeof(sprite_t));
		game->map.tiles[i]->tex =
		sfTexture_createFromFile(tiles_file, NULL);
		game->map.tiles[i]->spr = sfSprite_create();
		sfSprite_setTexture(
		game->map.tiles[i]->spr, game->map.tiles[i]->tex, sfTrue);
		sfSprite_setTextureRect(game->map.tiles[i]->spr, rect);
		rect.left += 60;
		sfSprite_setPosition(game->map.tiles[i]->spr, pos);
	}
	game->map.tiles[nb_tiles + 1] = NULL;
}

void alloc_tiles_screen(scene_t *game)
{
	game->map.screen = malloc(sizeof(sfSprite **) * (17 + 1));
	for (int i = 0; i < 17; i++) {
		game->map.screen[i] = malloc(sizeof(sfSprite *) * (16 + 1));
		game->map.screen[i][16] = NULL;
	}
	game->map.screen[17] = NULL;
}

void get_collision(scene_t *game, int fd)
{
	short temp;

	if (fd == -1)
		return;
	game->map.collision = malloc(sizeof(short *) * (17 + 1));
	for (int i = 0; i < 17; i++)
		game->map.collision[i] = malloc(sizeof(short) * 16);
	game->map.collision[17] = NULL;
	for (int y = 0; y < 17; y++) {
		for (int x = 0; x < 16; x++) {
			read(fd, &temp, sizeof(short));
			game->map.collision[y][x] = temp;
		}
	}
}

void get_tilemap(scene_t *game, int nb_tiles, int fd)
{
	short temp;

	if (fd == -1)
		return;
	game->map.tilemap = malloc(sizeof(short *) * (17 + 1));
	for (int i = 0; i < 17; i++)
		game->map.tilemap[i] = malloc(sizeof(short) * 16);
	game->map.tilemap[17] = NULL;
	for (int y = 0; y < 17; y++) {
		for (int x = 0; x < 16; x++) {
			read(fd, &temp, sizeof(short));
			game->map.tilemap[y][x] = (temp <= nb_tiles) ? temp : 0;
		}
	}
}