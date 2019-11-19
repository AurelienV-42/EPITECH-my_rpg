/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Headers
*/

#ifndef RPG_H_
#define RPG_H_

#include "conf.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum { EXIT, UNDEFINED, MAIN_MENU, HOW_TO_PLAY, GAME } scene_e;

typedef enum {
	LOAD,
	LOADING,
	LOADED,
	UNLOAD,
	UNLOADING,
	UNLOADED,
	ERROR
} scene_state_e;

typedef struct {
	sfRenderWindow *window;
	sfClock *clock;
	scene_e active_scene;
	scene_e next_scene;
	scene_state_e scene_state;
	sfMusic **sounds;
} global_t;

typedef enum { PLAYER, BG, FREE } obj_type_e;

typedef struct {
	obj_type_e type;
	sfSprite *spr;
	sfTexture *tex;
	sfVector2f pos;
} sprite_t;

typedef struct {
	sfRectangleShape *rect;
	sfSprite *spr;
	sfTexture *tex;
	sfVector2f pos;
	sfVector2f size;
	void (*action)();
} button_t;

typedef struct {
	int nb_tiles;
	sprite_t **tiles;
	short **tilemap;
	sfSprite ***screen;
	short **collision;
} map_t;


typedef struct {
	char ***dialog;
	int quest;
	int n_dialog;
	int n_dialog2;
	int n_dialog3;
	char chat;
} pnj_t;

typedef struct {
	sfClock *clock;
	char finish;
	int life;
	int damage;
	int magic;
	char level;
	pnj_t *pnj;
} charac_t;

typedef struct {
	short warp;
	int pause;
	sprite_t **sprite;
	button_t **button;
	charac_t **charac;
	map_t map;
	sfMusic **sounds;
	sfFont *font;
	sfText *text;
	sfText *text_hud;
} scene_t;

typedef struct {
	int warp;
	void (*warp_function)();
} warp_switch_t;


int my_rpg_loop(global_t *global);

void scene_switcher(global_t *global);

int get_tile_pos_x(int x);
int get_tile_pos_y(int y);

sprite_t *create_sprite(char *file, obj_type_e type, int x, int y);
button_t *create_button(char *file, int size_x, int size_y, void *action);
int button_is_clicked(button_t *but, sfVector2i clickPosition);
void move_button(button_t *button, int x, int y);
void move_charac(scene_t *game, int x, int y, global_t *global);
void do_nothing(void);
void init_sprite(scene_t *game);
void init_sounds(scene_t *game);
void init_texts(scene_t *game);
void start_pnj(scene_t *game, int);

void main_menu_main(global_t *global);
void main_menu_events(global_t *global, scene_t *menu);
void exit_button(global_t *global);
void htp_button(global_t *global);
void play_button(global_t *global);

void main_htp(global_t *global);
void htp_events(global_t *global, scene_t *htp, int *page);
void htp_next_button(global_t *global, scene_t *htp, int *page);
void htp_prev_button(global_t *global, scene_t *htp, int *page);
void htp_exit_button(global_t *global, scene_t *htp, int *page);

void game_main(global_t *global);
void display_game(global_t *global, scene_t *game);
void game_click_handler(global_t *global, scene_t *game);
void game_events(global_t *global, scene_t *game);
void leave_the_game(global_t *global, scene_t *game);

void init_tilemap(scene_t *game, int nb_tiles, char *tiles_file,
char *map_file);
void change_tilemap(scene_t *game, int nb_tiles, char *tiles_file,
char *map_file);
void destroy_tilemap(scene_t *game);
void draw_tilemap(global_t *global, scene_t *game);

void map_switcher(short warp, scene_t *game, global_t *global);
void warp_overworld_house(scene_t *game, global_t *global);
void warp_overworld_up(scene_t *game, global_t *global);
void warp_overworld_two(scene_t *game, global_t *global);
void warp_overworld_left(scene_t *game, global_t *global);

void get_tiles_from_file(scene_t *game, int nb_tiles, char *tiles_file);
void alloc_tiles_screen(scene_t *game);
void get_collision(scene_t *game, int fd);
void get_tilemap(scene_t *game, int nb_tiles, int fd);
void fill_tiles_screen(scene_t *game, int nb_tiles);

void init_character(scene_t *game, int);
void init_pnj(scene_t *game, int);
void init_mob(scene_t *game);
void move_mob(scene_t *game, int i, int x, global_t *global);
int is_a_collision(scene_t *game, int i, char axe);
int is_a_collision_mob(scene_t *game, int i, char axe);
void destroy_character(scene_t *game);
void quest(scene_t *game);
void destroy_pnj(scene_t *game);
void destroy_mob(scene_t *game);

char **init_quests(void);
char **init_quests_home(void);
char **init_quests_overworld2(void);
void change_quests(sfEvent event, scene_t *game);

#endif /* !RPG_H_ */
