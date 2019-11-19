/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Buttons misc functions
*/

#include "rpg.h"

void do_nothing(void)
{
}

int button_is_clicked(button_t *but, sfVector2i clickPosition)
{
	return (clickPosition.x < sfRectangleShape_getPosition(but->rect).x
	+ sfRectangleShape_getSize(but->rect).x
	&& clickPosition.x > sfRectangleShape_getPosition(but->rect).x
	&& clickPosition.y < sfRectangleShape_getPosition(but->rect).y
	+ sfRectangleShape_getSize(but->rect).y
	&& clickPosition.y > sfRectangleShape_getPosition(but->rect).y);
}