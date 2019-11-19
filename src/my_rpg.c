/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by $NAME
*/

#include "rpg.h"

static void scene_player(global_t *global)
{
	scene_switcher(global);
	switch (global->active_scene) {
	case MAIN_MENU:
		main_menu_main(global);
		break;
	case HOW_TO_PLAY:
		main_htp(global);
		break;
	case GAME:
		game_main(global);
		break;
	case EXIT:
		sfRenderWindow_destroy(global->window);
		global->window = NULL;
		break;
	default:
		global->active_scene = UNDEFINED;
		global->scene_state = UNLOADED;
		break;
	}
}

static void init_global_audio(global_t *global)
{
	global->sounds = malloc(sizeof(sfMusic *) * GLOBAL_MAX_AUDIO);
	global->sounds[0] = sfMusic_createFromFile(GLOBAL_AUDIO_OK);
	global->sounds[1] = sfMusic_createFromFile(GLOBAL_AUDIO_NO);
}

static void destroy_global_audio(global_t *global)
{
	for (int i = 0; i < GLOBAL_MAX_AUDIO; i++) {
		sfMusic_stop(global->sounds[i]);
		sfMusic_destroy(global->sounds[i]);
	}
	free(global->sounds);
}

int my_rpg_loop(global_t *global)
{
	init_global_audio(global);
	while ((global->window && sfRenderWindow_isOpen(global->window))
	|| global->scene_state == UNLOAD)
		scene_player(global);
	destroy_global_audio(global);
	return 0;
}