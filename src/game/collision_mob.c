/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** File to know if it's a collision
*/

#include "rpg.h"

static int is_a_collision_right(scene_t *game, int i, char axe)
{
	switch (axe) {
	case 4:
		if (game->sprite[i]->pos.x < GXO(15) &&
		game->map.collision[(int)game->sprite[i]->pos.y / 60][
		(int)((game->sprite[i]->pos.x - 480) / 60) + 1] != -1 &&
		game->map.collision[(int)game->sprite[i]->pos.y / 60][
		(int)((game->sprite[i]->pos.x - 480) / 60) + 1] != -2)
			return (1);
	}
	return (0);
}

static int is_a_collision_left(scene_t *game, int i, char axe)
{
	switch (axe) {
	case 3:
		if (game->sprite[i]->pos.x > GXO(0) &&
		game->map.collision[(int)game->sprite[i]->pos.y / 60][
		(int)((game->sprite[i]->pos.x - 480) / 60) - 1] != -1 &&
		game->map.collision[(int)game->sprite[i]->pos.y / 60][
		(int)((game->sprite[i]->pos.x - 480) / 60) - 1] != -2)
			return (1);
		break;
	default:
		if (is_a_collision_right(game, i, axe) == 1)
			return (1);
	}
	return (0);
}

static int is_a_collision_switch(scene_t *game, int i, char axe)
{
	switch (axe) {
	case 2:
		if (game->sprite[i]->pos.y < GYO(16) &&
		game->map.collision[(int)(game->sprite[i]->pos.y / 60) + 1]
		[(int)(game->sprite[i]->pos.x - 480) / 60] != -1 &&
		game->map.collision[(int)(game->sprite[i]->pos.y / 60) + 1]
		[(int)(game->sprite[i]->pos.x - 480) / 60] != -2)
			return (1);
		break;
	default:
		if (is_a_collision_left(game, i, axe) == 1)
			return (1);
	}
	return (0);
}

int is_a_collision_mob(scene_t *game, int i, char axe)
{
	switch (axe) {
	case 1:
		if (game->sprite[i]->pos.y > GYO(0) &&
		game->map.collision[(int)(game->sprite[i]->pos.y / 60) - 1]
		[(int)(game->sprite[i]->pos.x - 480) / 60] != -1 &&
		game->map.collision[(int)(game->sprite[i]->pos.y / 60) - 1]
		[(int)(game->sprite[i]->pos.x - 480) / 60] != -2)
			return (1);
		break;
	default:
		if (is_a_collision_switch(game, i, axe) == 1)
			return (1);
	}
	return (0);
}