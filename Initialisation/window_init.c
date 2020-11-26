/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 02:50:49 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/30 17:20:06 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	window_init(t_window **window)
{
	if (*window)
	{
		(*window)->width = 0;
		(*window)->height = 0;
		(*window)->max_width = 0;
		(*window)->max_height = 0;
		(*window)->mlx_ptr = NULL;
		(*window)->win_ptr = NULL;
	}
}

int		window_create(t_game **game, t_all **all)
{
	if (!((*game)->window = malloc(sizeof(t_window))))
		return ((*all)->errors->window_malloc = -1);
	window_init(&((*game)->window));
	return (0);
}
