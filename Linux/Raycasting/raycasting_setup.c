/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 11:55:00 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/26 11:26:49 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	floor_color_converter(t_game **game, t_params *params)
{
	(*game)->fcol = params->floor_r;
	(*game)->fcol = ((*game)->fcol << 8) + params->floor_g;
	(*game)->fcol = ((*game)->fcol << 8) + params->floor_b;
}

void	ceil_color_converter(t_game **game, t_params *params)
{
	(*game)->ccol = params->ceil_r;
	(*game)->ccol = ((*game)->ccol << 8) + params->ceil_g;
	(*game)->ccol = ((*game)->ccol << 8) + params->ceil_b;
}

void	color_converter(t_all *all, t_game **game)
{
	floor_color_converter(game, all->params);
	ceil_color_converter(game, all->params);
}

void	fov_setup(t_player **player, int fov)
{
	if ((*player)->dir_x != 0 && (*player)->dir_y == 0)
	{
		(*player)->plan_x = 0;
		(*player)->plan_y = fov / ((*player)->dir_x * 100);
	}
	if ((*player)->dir_y != 0 && (*player)->dir_x == 0)
	{
		(*player)->plan_y = 0;
		(*player)->plan_x = -fov / ((*player)->dir_y * 100);
	}
}

int		params_picker(t_game **game, t_all *all)
{
	double	fov;

	fov = 66.0;
	if (player_parsing(&all, game) == -1)
		return (-1);
	color_converter(all, game);
	fov_setup(&((*game)->player), fov);
	(*game)->window->width = all->params->h_res;
	(*game)->window->height = all->params->v_res;
	if ((*game)->window->width == 0 || (*game)->window->height == 0)
		return (write_parameters_errors(2));
	(*game)->no_path = all->params->no_path;
	(*game)->so_path = all->params->so_path;
	(*game)->we_path = all->params->we_path;
	(*game)->ea_path = all->params->ea_path;
	(*game)->sprite = all->params->sprite;
	(*game)->map = all->map_s->map;
	(*game)->map[(int)(*game)->player->y][(int)(*game)->player->x] = '0';
	(*game)->save = all->params->save;
	(*game)->all = all;
	return (0);
}
