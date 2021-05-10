/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 08:20:43 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/24 10:13:02 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		extract_player_vector2(int i, int j, char player, t_game **game)
{
	if (player == 'W')
	{
		(*game)->player->dir_x = -1.0;
		(*game)->player->dir_y = 0.0;
	}
	else if (player == 'E')
	{
		(*game)->player->dir_x = 1.0;
		(*game)->player->dir_y = 0.0;
	}
	(*game)->player->x = j + 0.5;
	(*game)->player->y = i + 0.5;
	return ((*game)->player->found = 1);
}

int		extract_player_vector(int i, int j, char player, t_game **game)
{
	if (player == 'N')
	{
		(*game)->player->dir_x = 0.;
		(*game)->player->dir_y = -1.;
	}
	else if (player == 'S')
	{
		(*game)->player->dir_x = 0.;
		(*game)->player->dir_y = 1.;
	}
	return (extract_player_vector2(i, j, player, game));
}

int		player_parsing(t_all **all, t_game **game)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = (*all)->map_s->map;
	while (tab[i] != NULL)
	{
		while (tab[i][j])
		{
			if ((tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'W'
				|| tab[i][j] == 'E') && (*game)->player->found == 0)
				extract_player_vector(i, j, tab[i][j], game);
			else if ((tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'W'
				|| tab[i][j] == 'E') && (*game)->player->found == 1)
				return (write_map_errors(3));
			j++;
		}
		j = 0;
		i++;
	}
	if ((*game)->player->found == 0)
		return (write_map_errors(4));
	return (0);
}
