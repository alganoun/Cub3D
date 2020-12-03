/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:49:29 by allanganoun       #+#    #+#             */
/*   Updated: 2020/12/01 09:09:06 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_first_last(char *str)
{
	int i;

	i = 0;
	check_whitespace(&str);
	while (str[i])
	{
		if (str[i] == '1' || str[i] == ' '
			|| ((str[i] >= 9 && str[i] <= 13)))
			i++;
		else
			return (write_map_errors(1));
	}
	return (0);
}

int		check_inside(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == '2' || str[i] == '1' || str[i] == 'N'
				|| str[i] == 'S' || str[i] == 'E' || str[i] == 'W'
					|| str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		else
		{
			write(1, "Error\nMap : invalid char detected\n", 34);
			return (-9999);
		}
	}
	return (i);
}

int		checkline(char *str)
{
	int i;

	i = 0;
	check_whitespace(&str);
	if (str[0] != '1')
		return (write_map_errors(1));
	while (str[i] == '1')
		i++;
	if (str[i] == '\0')
		return (0);
	else if ((i = check_inside(&str[i]) + i) < 0)
		return (-1);
	while (str[i - 1] == ' ')
		i--;
	if (str[i - 1] != '1')
		return (write_map_errors(1));
	return (0);
}

int		map_checker(t_all **all)
{
	int i;

	i = 1;
	if (check_first_last((*all)->map_s->map[0]) == -1)
		return (-1);
	while ((*all)->map_s->map[i] != NULL)
	{
		if (checkline((*all)->map_s->map[i]) == -1)
			return (-1);
		if (check_front_walls((*all)->map_s->map[i - 1],
			(*all)->map_s->map[i]) == -1)
			return (-1);
		if (check_back_walls((*all)->map_s->map[i - 1],
			(*all)->map_s->map[i]) == -1)
			return (-1);
		if (check_holes((*all)->map_s->map[i - 1],
			(*all)->map_s->map[i]) == -1)
			return (-1);
		i++;
	}
	if (check_first_last((*all)->map_s->map[i - 1]) == -1)
		return (-1);
	return (0);
}
