/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Creation of sprites
*/

#include "rpg.h"
#include <stdio.h>

sprite_t *create_sprite(char *file, obj_type_e type, int x, int y)
{
	sprite_t *sprite = malloc(sizeof(sprite_t));

	sprite->type = type;
	sprite->tex = sfTexture_createFromFile(file, NULL);
	sprite->spr = sfSprite_create();
	sfSprite_setTexture(sprite->spr, sprite->tex, sfTrue);
	sprite->pos.x = x;
	sprite->pos.y = y;
	sfSprite_setPosition(sprite->spr, sprite->pos);
	return sprite;
}

button_t *create_button(char *file, int size_x, int size_y, void *action)
{
	button_t *button = malloc(sizeof(button_t));

	button->tex = sfTexture_createFromFile(file, NULL);
	button->spr = sfSprite_create();
	sfSprite_setTexture(button->spr, button->tex, sfTrue);
	button->pos.x = 0;
	button->pos.y = 0;
	sfSprite_setPosition(button->spr, button->pos);
	button->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(button->rect, button->pos);
	button->size.x = size_x;
	button->size.y = size_y;
	sfRectangleShape_setSize(button->rect, button->size);
	button->action = action;
	return button;
}

void move_button(button_t *button, int x, int y)
{
	button->pos.x = x;
	button->pos.y = y;
	sfSprite_setPosition(button->spr, button->pos);
	sfRectangleShape_setPosition(button->rect, button->pos);
}