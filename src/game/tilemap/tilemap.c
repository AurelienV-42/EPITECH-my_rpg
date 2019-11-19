/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** Tilemaps
*/

#include "my.h"
#include "rpg.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void init_tilemap(scene_t *game, int nb_tiles, char *tiles_file, char *map_file)
{
	int fd = open(map_file, O_RDONLY);

	get_tiles_from_file(game, nb_tiles, tiles_file);
	alloc_tiles_screen(game);
	get_tilemap(game, nb_tiles, fd);
	fill_tiles_screen(game, nb_tiles);
	get_collision(game, fd);
	close(fd);
}

static void draw_tile(global_t *global, scene_t *game, int x, int y)
{
	if (game->map.tilemap[y][x] != 0)
		sfRenderWindow_drawSprite(
		global->window, game->map.screen[y][x], NULL);
}

void draw_tilemap(global_t *global, scene_t *game)
{
	for (int y = 0; y < 17; y++)
		for (int x = 0; x < 16; x++)
			draw_tile(global, game, x, y);
}

void change_tilemap(
scene_t *game, int nb_tiles, char *tiles_file, char *map_file)
{
	destroy_tilemap(game);
	init_tilemap(game, nb_tiles, tiles_file, map_file);
}

void destroy_tilemap(scene_t *game)
{
	for (int y = 0; y < 17; y++) {
		for (int x = 0; x < 16 && game->map.tilemap[y][x] != 0; x++)
			sfSprite_destroy(game->map.screen[y][x]);
		free(game->map.screen[y]);
	}
	free(game->map.screen);
	for (int i = 1; i < game->map.nb_tiles; i++) {
		sfSprite_destroy(game->map.tiles[i]->spr);
		sfTexture_destroy(game->map.tiles[i]->tex);
		free(game->map.tiles[i]);
	}
	free(game->map.tiles);
	for (int i = 0; i < 17; i++)
		free(game->map.tilemap[i]);
	free(game->map.tilemap);
}