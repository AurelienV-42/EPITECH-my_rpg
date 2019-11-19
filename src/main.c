/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by $NAME
*/

#include "conf.h"
#include "my.h"
#include "rpg.h"

static int init_game(global_t *global)
{
	sfVideoMode mode = VIDEO_MODE;

	global->window =
	sfRenderWindow_create(mode, WINDOW_NAME, WINDOW_STYLE, NULL);
	if (global->window == NULL)
		return 84;
	sfRenderWindow_setFramerateLimit(global->window, 30);
	global->clock = sfClock_create();
	global->active_scene = MAIN_MENU;
	global->scene_state = LOAD;
	global->next_scene = UNDEFINED;
	return 0;
}

int main(int ac, char **av)
{
	global_t global;

	if (ac >= 2) {
		if (my_strcmp(av[1], "-h") == 0) {
			my_putstr(LEAFLET);
			return 0;
		} else {
			my_putstr_error("Retry with -h\n");
			return 84;
		}
	}
	if (init_game(&global) != 0)
		return 84;
	return my_rpg_loop(&global);
}