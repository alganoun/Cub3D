/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 01:16:58 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/30 11:07:24 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_left(t_player **player)
{
	float	prev_dir_x;
	float	prev_plan_x;

	prev_dir_x = (*player)->dir_x;
	(*player)->dir_x = cos(-((*player)->rot_speed)) * (*player)->dir_x -
					sin(-((*player)->rot_speed)) * (*player)->dir_y;
	(*player)->dir_y = sin(-((*player)->rot_speed)) * prev_dir_x +
					cos(-((*player)->rot_speed)) * (*player)->dir_y;
	prev_plan_x = (*player)->plan_x;
	(*player)->plan_x = cos(-((*player)->rot_speed)) * (*player)->plan_x -
					sin(-((*player)->rot_speed)) * (*player)->plan_y;
	(*player)->plan_y = sin(-((*player)->rot_speed)) * prev_plan_x +
					cos(-((*player)->rot_speed)) * (*player)->plan_y;
}

void	rotate_right(t_player **player)
{
	float	prev_dir_x;
	float	prev_plan_x;

	prev_dir_x = (*player)->dir_x;
	(*player)->dir_x = cos((*player)->rot_speed) * (*player)->dir_x -
					sin((*player)->rot_speed) * (*player)->dir_y;
	(*player)->dir_y = sin((*player)->rot_speed) * prev_dir_x +
					cos((*player)->rot_speed) * (*player)->dir_y;
	prev_plan_x = (*player)->plan_x;
	(*player)->plan_x = cos((*player)->rot_speed) * (*player)->plan_x -
					sin((*player)->rot_speed) * (*player)->plan_y;
	(*player)->plan_y = sin((*player)->rot_speed) * prev_plan_x +
					cos((*player)->rot_speed) * (*player)->plan_y;
}
