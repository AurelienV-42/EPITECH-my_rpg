/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** File with movement of events
*/

#include "rpg.h"

static void move_charac_axe(sprite_t *sprite, char i, sfIntRect *rect)
{
	switch (i) {
	case 0:
		(*rect).top = 60 * 3;
		sprite->pos.x -= 10;
		break;
	case 1:
		(*rect).top = 61;
		sprite->pos.x += 10;
		break;
	case 2:
		(*rect).top = 0;
		sprite->pos.y -= 10;
		break;
	case 3:
		(*rect).top = 60 * 2;
		sprite->pos.y += 10;
		break;
	}
	(*rect).left += 60;
	if ((*rect).left == 60 * 6)
		(*rect).left = 0;
}

void change_collision(scene_t *game, int i, int x)
{
	static int old_value = 0;

	old_value = game->map.collision[(int)game->sprite[i]->pos.y
	/ 60][(int)(game->sprite[i]->pos.x - 480) / 60];
	game->map.collision[(int)game->sprite[i]->pos.y / 60]
	[(int)(game->sprite[i]->pos.x - 480) / 60] = -1;
	if (x == -2)
		game->map.collision[(int)game->sprite[i]->pos.y
		/ 60][((int)(game->sprite[i]->pos.x - 480) / 60) + 1] =
		old_value;
	if (x == 2)
		game->map.collision[(int)game->sprite[i]->pos.y
		/ 60][((int)(game->sprite[i]->pos.x - 480) / 60) - 1] =
		old_value;
	if (x == -1)
		game->map.collision[((int)game->sprite[i]->pos.y / 60)
		+ 1][(int)(game->sprite[i]->pos.x - 480) / 60] = old_value;
	if (x == 1)
		game->map.collision[((int)game->sprite[i]->pos.y / 60)
		- 1][(int)(game->sprite[i]->pos.x - 480) / 60] = old_value;
}

int is_a_map(scene_t *game, global_t *global, int i)
{
	if (game->map.collision[(int)(game->sprite[i]->pos.y / 60)]
	[(int)(game->sprite[i]->pos.x - 480) / 60] > 0) {
		game->warp = game->map.collision[(int)(game->sprite[i]->pos.y
		/ 60)][(int)(game->sprite[i]->pos.x - 480) / 60];
		map_switcher(game->map.collision[(int)(game->sprite[i]->pos.y
		/ 60)][(int)(game->sprite[i]->pos.x - 480) / 60],
		game, global);
		return (0);
	}
	return (1);
}

void move_charac(scene_t *game, int i, int x, global_t *global)
{
	static sfIntRect rec = {0, 0, 60, 60};

	do {
		if (sfClock_getElapsedTime(global->clock).microseconds
		> 32000) {
			x == -2 ? move_charac_axe(game->sprite[i], 0, &rec) : 0;
			x == 2 ? move_charac_axe(game->sprite[i], 1, &rec) : 0;
			x == -1 ? move_charac_axe(game->sprite[i], 2, &rec) : 0;
			x == 1 ? move_charac_axe(game->sprite[i], 3, &rec) : 0;
			sfClock_restart(global->clock);
		}
		sfSprite_setTextureRect(game->sprite[i]->spr, rec);
		sfSprite_setPosition(
		game->sprite[i]->spr, game->sprite[i]->pos);
		display_game(global, game);
	} while (sfSprite_getTextureRect(game->sprite[i]->spr).left != 0);
	if (is_a_map(game, global, i))
		change_collision(game, i, x);
}
