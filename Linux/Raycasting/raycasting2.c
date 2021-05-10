/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:38:12 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/26 16:03:44 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		raycasting_process(t_game **game)
{
	while ((*game)->ray->x < (*game)->window->width)
	{
		ray_calculations(&((*game)->ray), (*game)->player, (*game)->window);
		if (wall_finder(game, &((*game)->ray)) == -1)
			return (-1);
		perp_height(&((*game)->ray), (*game)->player, (*game)->window);
		if (draw_walls(game, &((*game)->ray)) == -1)
			return (-1);
		(*game)->ray->x++;
	}
	return (0);
}

int		raycasting(t_game **game)
{
	(*game)->ray->x = 0;
	if (!((*game)->ray->z_buffer =
		(double *)malloc(sizeof(double) * (*game)->window->width)))
		return (-1);
	ft_bzero((*game)->ray->z_buffer, sizeof(double) * (*game)->window->width);
	if (raycasting_process(game) == -1)
		return (-1);
	if ((*game)->sprites_begin != NULL)
		if (draw_sprites(game, (*game)->window, (*game)->ray) == -1)
			return (-1);
	safe_free((char **)&((*game)->ray->z_buffer));
	mlx_do_sync((*game)->window->mlx_ptr);
	if ((*game)->save == 1)
	{
		if (create_bitmap(*game) == -1)
			return (-1);
		return (0);
	}
	else
	{
		mlx_put_image_to_window((*game)->window->mlx_ptr,
			(*game)->window->win_ptr, (*game)->image->img_ptr, 0, 0);
	}
	return (0);
}
