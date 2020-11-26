/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 02:40:41 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/29 14:14:55 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray_init2(t_ray **ray)
{
	(*ray)->step = 0;
	(*ray)->step_x = 0;
	(*ray)->step_y = 0;
	(*ray)->hit = 0;
	(*ray)->side = 0;
	(*ray)->line_h = 0;
	(*ray)->draw_start = 0;
	(*ray)->draw_end = 0;
	(*ray)->text_x = 0;
	(*ray)->text_y = 0;
	(*ray)->wall_x = 0;
	(*ray)->z_buffer = 0;
}

void	ray_init(t_ray **ray)
{
	if (*ray)
	{
		(*ray)->x = 0;
		(*ray)->y = 0;
		(*ray)->dir_x = 0;
		(*ray)->dir_y = 0;
		(*ray)->side_x = 0;
		(*ray)->side_y = 0;
		(*ray)->delta_x = 0;
		(*ray)->delta_y = 0;
		(*ray)->camera_x = 0;
		(*ray)->walldist_p = 0;
		(*ray)->map_x = 0;
		(*ray)->map_y = 0;
		ray_init2(ray);
	}
}

int		ray_create(t_game **game, t_all **all)
{
	if (!((*game)->ray = malloc(sizeof(t_ray))))
		return ((*all)->errors->ray_malloc = -1);
	ray_init(&((*game)->ray));
	return (0);
}
