/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allanganoun <allanganoun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 02:50:49 by allanganoun       #+#    #+#             */
/*   Updated: 2021/05/10 13:22:39 by allanganoun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	window_init(t_window **window)
{
	if (*window)
	{
		(*window)->width = 0;
		(*window)->height = 0;
		(*window)->max_width = 1920;
		(*window)->max_height = 1080;
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
