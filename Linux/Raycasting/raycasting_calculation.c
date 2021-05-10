/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calculation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:37:18 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/30 11:59:44 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	step_sidedist(t_ray **ray, t_player *player)
{
	if ((*ray)->dir_x < 0)
	{
		(*ray)->step_x = -1;
		(*ray)->side_x = (player->x - (*ray)->map_x) * (*ray)->delta_x;
	}
	else
	{
		(*ray)->step_x = 1;
		(*ray)->side_x = ((*ray)->map_x - player->x + 1.0) * (*ray)->delta_x;
	}
	if ((*ray)->dir_y < 0)
	{
		(*ray)->step_y = -1;
		(*ray)->side_y = (player->y - (*ray)->map_y) * (*ray)->delta_y;
	}
	else
	{
		(*ray)->step_y = 1;
		(*ray)->side_y = ((*ray)->map_y - player->y + 1.0) * (*ray)->delta_y;
	}
}

void	delta_dist(t_ray **ray)
{
	if ((*ray)->dir_y == 0)
		(*ray)->delta_x = 0;
	else if ((*ray)->dir_x == 0)
		(*ray)->delta_x = 1;
	else
		(*ray)->delta_x = fabs(1 / (*ray)->dir_x);
	if ((*ray)->dir_x == 0)
		(*ray)->delta_y = 0;
	else if ((*ray)->dir_y == 0)
		(*ray)->delta_y = 1;
	else
		(*ray)->delta_y = fabs(1 / (*ray)->dir_y);
}

void	perp_height(t_ray **ray, t_player *player, t_window *window)
{
	if ((*ray)->side == 0 || (*ray)->side == 1)
		(*ray)->walldist_p = ((*ray)->map_x - player->x + (1 - (*ray)->step_x)
		/ 2) / (*ray)->dir_x;
	else if ((*ray)->side == 2 || (*ray)->side == 3)
	{
		(*ray)->walldist_p = ((*ray)->map_y - player->y + (1 - (*ray)->step_y)
		/ 2) / (*ray)->dir_y;
	}
	(*ray)->line_h = (int)(window->height / (*ray)->walldist_p);
	(*ray)->z_buffer[(*ray)->x] = (*ray)->walldist_p;
}

void	ray_calculations(t_ray **ray, t_player *player, t_window *window)
{
	(*ray)->camera_x = 2 * (*ray)->x / (double)window->width - 1;
	(*ray)->dir_x = player->dir_x + player->plan_x * (*ray)->camera_x;
	(*ray)->dir_y = player->dir_y + player->plan_y * (*ray)->camera_x;
	delta_dist(ray);
	(*ray)->hit = 0;
	(*ray)->map_x = (int)player->x;
	(*ray)->map_y = (int)player->y;
	step_sidedist(ray, player);
}
