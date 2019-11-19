/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Scene switcher
*/

#include "rpg.h"
#include "my.h"

static void scene_error(global_t *global)
{
	sfEvent event;

	global->scene_state = ERROR;
	write(2, "Trying to change scene to UNDEFINED\n", 36);
	sfRenderWindow_clear(global->window, sfRed);
	sfRenderWindow_display(global->window);
	while (sfRenderWindow_waitEvent(global->window, &event))
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(global->window);
}

void scene_switcher(global_t *global)
{
	if (global->scene_state == UNLOADED) {
		if (global->next_scene != UNDEFINED
		&& global->active_scene != UNDEFINED) {
			my_printf("Switching from scene %i to scene %i\n",
			global->active_scene, global->next_scene);
			global->active_scene = global->next_scene;
			global->next_scene = UNDEFINED;
			global->scene_state = LOAD;
		} else
			scene_error(global);
	}
}