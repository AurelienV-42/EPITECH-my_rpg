/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** File which move the mob
*/

#include "rpg.h"

static void move_mob_collision(scene_t *game, int i, int x)
{
	switch (x) {
	case 0:
		game->sprite[i]->pos.y -= 20;
		break;
	case 1:
		game->sprite[i]->pos.x += 20;
		break;
	case 2:
		game->sprite[i]->pos.x -= 20;
		break;
	case 3:
		game->sprite[i]->pos.y += 20;
		break;
	}
}

static char test_collision(scene_t *game, int i, int x)
{
	switch (x) {
	case 0:
		return is_a_collision_mob(game, i, 1);
	case 1:
		return is_a_collision_mob(game, i, 4);
	case 2:
		return is_a_collision_mob(game, i, 3);
	case 3:
		return is_a_collision_mob(game, i, 2);
	default:
		return 0;
	}
}

void move_mob(scene_t *game, int i, int x, global_t *global)
{
	static sfIntRect rect = {0, 0, 60, 60};

	if (test_collision(game, i, x) == 0)
		return;
	do {
		if (sfClock_getElapsedTime(game->charac[2]->clock).microseconds
		> 100) {
			move_mob_collision(game, i, x);
			rect.left = (rect.left >= 60 * 3) ? 0 : rect.left + 60;
			sfClock_restart(game->charac[2]->clock);
		}
		sfSprite_setTextureRect(game->sprite[i]->spr, rect);
		sfSprite_setPosition(
		game->sprite[i]->spr, game->sprite[i]->pos);
		display_game(global, game);
	} while (rect.left != 0);
}