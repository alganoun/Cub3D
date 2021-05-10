/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 00:11:23 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/30 20:39:24 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	change_player_pos(t_player **player, double pos_x, double pos_y, int i)
{
	if (i == 1)
	{
		(*player)->x += pos_x;
		(*player)->y += pos_y;
	}
	if (i == 2)
	{
		(*player)->x += pos_x;
		(*player)->y += pos_y;
	}
}

void	move_forward(char **map, t_player **player)
{
	if (map[(int)((*player)->y)]
		[(int)((*player)->x + (*player)->dir_x
		* (*player)->mov_speed)] == '0')
		change_player_pos(player, ((*player)->dir_x
		* (*player)->mov_speed), 0.0, 1);
	if (map[(int)((*player)->y + (*player)->dir_y
		* (*player)->mov_speed)]
		[(int)((*player)->x)] == '0')
		change_player_pos(player, 0.0, (*player)->dir_y
		* (*player)->mov_speed, 1);
}

void	move_backward(char **map, t_player **player)
{
	if (map[(int)((*player)->y)]
		[(int)((*player)->x - (*player)->dir_x
		* (*player)->mov_speed)] == '0')
		change_player_pos(player, -((*player)->dir_x
		* (*player)->mov_speed), 0, 2);
	if (map[(int)((*player)->y - (*player)->dir_y
		* (*player)->mov_speed)]
		[(int)((*player)->x)] == '0')
		change_player_pos(player, 0.0, -((*player)->dir_y
		* (*player)->mov_speed), 2);
}

void	move_right(char **map, t_player **player)
{
	if (map[(int)((*player)->y)]
		[(int)((*player)->x + (*player)->plan_x
		* (*player)->mov_speed)] == '0')
		change_player_pos(player, (*player)->plan_x
		* (*player)->mov_speed, 0.0, 1);
	if (map[(int)((*player)->y + (*player)->plan_y * (*player)->mov_speed)]
		[(int)((*player)->x)] == '0')
		change_player_pos(player, 0.0, (*player)->plan_y
		* (*player)->mov_speed, 1);
}

void	move_left(char **map, t_player **player)
{
	if (map[(int)((*player)->y)]
		[(int)((*player)->x - (*player)->plan_x
		* (*player)->mov_speed)] == '0')
		change_player_pos(player, -((*player)->plan_x
		* (*player)->mov_speed), 0, 2);
	if (map[(int)((*player)->y - (*player)->plan_y
		* (*player)->mov_speed)]
		[(int)((*player)->x)] == '0')
		change_player_pos(player, 0, -((*player)->plan_y
		* (*player)->mov_speed), 2);
}
