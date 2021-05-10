/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:42:10 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/26 11:47:54 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		close_window(t_game *game)
{
	game_exit(&game, &(game->all));
	return (0);
}

void	game_exit(t_game **game, t_all **all)
{
	if (all != NULL)
		free_all(all);
	if (game != NULL)
		free_game(game);
	exit(0);
}

int		last_wall(char *str)
{
	int len;

	len = ft_strlen(str);
	while (str[len - 1] == ' ')
		len--;
	return (len);
}

int		first_wall(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}
