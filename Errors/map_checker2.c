/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:38:39 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/29 16:15:35 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_back_walls(char *topline, char *botline)
{
	if (last_wall(topline) < last_wall(botline))
	{
		if (botline[last_wall(topline)] != '1')
			return (write_map_errors(1));
	}
	else if (last_wall(topline) > last_wall(botline))
	{
		if (topline[last_wall(botline)] != '1')
			return (write_map_errors(1));
	}
	else if (last_wall(topline) == last_wall(botline))
	{
		if (botline[last_wall(topline) - 1] != '1')
			return (write_map_errors(1));
	}
	return (0);
}

int		check_front_walls(char *topline, char *botline)
{
	if (first_wall(topline) > first_wall(botline))
	{
		if (botline[first_wall(topline) - 1] != '1')
			return (write_map_errors(1));
	}
	if (first_wall(topline) < first_wall(botline))
	{
		if (topline[first_wall(botline) - 1] != '1')
			return (write_map_errors(1));
	}
	if (first_wall(topline) == first_wall(botline))
	{
		if (botline[first_wall(topline)] != '1')
			return (write_map_errors(1));
	}
	return (0);
}

int		check_holes(char *topline, char *botline)
{
	int i;

	i = 0;
	while (topline[i])
	{
		if (topline[i] == ' ' && i != 0)
		{
			if (topline[i - 1] != '1' && topline[i - 1] != ' ' &&
				(topline[i + 1] <= 9 && topline[i + 1] >= 13))
				return (write_map_errors(1));
			if (topline[i + 1] != '1' && topline[i + 1] != ' ' &&
				(topline[i + 1] <= 9 && topline[i + 1] >= 13))
				return (write_map_errors(1));
			if (botline[i] != '1' && botline[i] != ' ' &&
				(topline[i + 1] <= 9 && topline[i + 1] >= 13))
				return (write_map_errors(1));
		}
		if (botline[i] == ' ' && i != 0)
			if (topline[i] != '1' && topline[i] != ' ' &&
				(topline[i + 1] <= 9 && topline[i + 1] >= 13))
				return (write_map_errors(1));
		i++;
	}
	return (0);
}
