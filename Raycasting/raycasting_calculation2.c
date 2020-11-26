/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calculation2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 02:20:50 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/30 01:16:31 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	wall_searching(t_ray **ray)
{
	if ((*ray)->side_x < (*ray)->side_y)
	{
		(*ray)->side_x += (*ray)->delta_x;
		(*ray)->map_x += (*ray)->step_x;
		if ((*ray)->step_x == -1)
			(*ray)->side = 0;
		else
			(*ray)->side = 1;
	}
	else
	{
		(*ray)->side_y += (*ray)->delta_y;
		(*ray)->map_y += (*ray)->step_y;
		if ((*ray)->step_y == -1)
			(*ray)->side = 2;
		else
			(*ray)->side = 3;
	}
}

int		wall_finder(t_game **game, t_ray **ray)
{
	while ((*ray)->hit != 1)
	{
		wall_searching(ray);
		if ((*game)->map[(*ray)->map_y][(*ray)->map_x] == '1')
			(*ray)->hit = 1;
		else if ((*game)->map[(*ray)->map_y][(*ray)->map_x] == '2')
			sprite_process(*game, *ray);
	}
	return (0);
}
