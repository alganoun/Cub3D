/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 02:47:09 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/30 20:26:06 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_init(t_player **player)
{
	if (*player)
	{
		(*player)->x = 0;
		(*player)->y = 0;
		(*player)->dir_x = 0;
		(*player)->dir_y = 0;
		(*player)->plan_x = 0;
		(*player)->plan_y = 0;
		(*player)->mov_speed = 0.1;
		(*player)->rot_speed = 0.1;
		(*player)->found = 0;
	}
}

int		player_create(t_game **game, t_all **all)
{
	if (!((*game)->player = malloc(sizeof(t_player))))
		return ((*all)->errors->player_malloc = -1);
	player_init(&((*game)->player));
	return (0);
}
