/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:42:13 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/30 20:17:57 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_pressed(int key_code, t_game *game)
{
	if (key_code == KEY_W)
		game->keys->w = 1;
	if (key_code == KEY_SHIFT)
		game->keys->shift = 1;
	else if (key_code == KEY_A)
		game->keys->a = 1;
	else if (key_code == KEY_S)
		game->keys->s = 1;
	else if (key_code == KEY_D)
		game->keys->d = 1;
	else if (key_code == KEY_ESC)
		game->keys->esc = 1;
	else if (key_code == LEFT_ARR)
		game->keys->left = 1;
	else if (key_code == RIGHT_ARR)
		game->keys->right = 1;
	return (0);
}

int		key_released(int key_code, t_game *game)
{
	if (key_code == KEY_SHIFT)
		game->keys->shift = 0;
	if (key_code == KEY_W)
		game->keys->w = 0;
	else if (key_code == KEY_A)
		game->keys->a = 0;
	else if (key_code == KEY_S)
		game->keys->s = 0;
	else if (key_code == KEY_D)
		game->keys->d = 0;
	else if (key_code == KEY_ESC)
		game->keys->esc = 0;
	else if (key_code == LEFT_ARR)
		game->keys->left = 0;
	else if (key_code == RIGHT_ARR)
		game->keys->right = 0;
	return (0);
}

void	key_manager(t_game *game)
{
	if (game->keys->shift == 1)
		game->player->mov_speed = 0.14;
	else if (game->keys->shift == 0)
		game->player->mov_speed = 0.08;
	if (game->keys->w == 1)
		move_forward(game->map, &game->player);
	else if (game->keys->s == 1)
		move_backward(game->map, &game->player);
	else if (game->keys->a == 1)
		move_left(game->map, &game->player);
	else if (game->keys->d == 1)
		move_right(game->map, &game->player);
	else if (game->keys->left == 1)
		rotate_left(&game->player);
	else if (game->keys->right == 1)
		rotate_right(&game->player);
	else if (game->keys->esc == 1)
		game_exit(&game, &(game->all));
}
