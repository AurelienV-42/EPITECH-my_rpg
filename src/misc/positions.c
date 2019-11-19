/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Position calculations
*/

int get_tile_pos_x(int x)
{
	return (480 + (x * 60));
}

int get_tile_pos_y(int y)
{
	return (30 + (y * 60));
}