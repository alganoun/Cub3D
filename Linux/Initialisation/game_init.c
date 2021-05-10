/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 02:03:30 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/29 14:03:38 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	game_init(t_game **game)
{
	if (*game)
	{
		(*game)->map_started = 0;
		(*game)->map_stopped = 0;
		(*game)->save = 0;
		(*game)->ccol = 0;
		(*game)->fcol = 0;
		(*game)->map = NULL;
		(*game)->no_path = NULL;
		(*game)->so_path = NULL;
		(*game)->we_path = NULL;
		(*game)->ea_path = NULL;
		(*game)->sprite = NULL;
		(*game)->keys = NULL;
		(*game)->ray = NULL;
		(*game)->player = NULL;
		(*game)->window = NULL;
		(*game)->image = NULL;
		(*game)->sprites_begin = NULL;
	}
}

int		game_create(t_game **game)
{
	if (!(*game = malloc(sizeof(t_game))))
	{
		write(1, "Error\n: Game structure not initiated\n", 37);
		return (-1);
	}
	game_init(game);
	return (0);
}
