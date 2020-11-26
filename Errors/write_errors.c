/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:19:17 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/26 16:15:57 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		write_init_errors(int option)
{
	if (option == 1)
		write(1, "Error\nMalloc : overall structure not initiated\n", 47);
	if (option == 2)
		write(1, "Error\nMalloc : error structure not initiated\n", 45);
	if (option == 3)
		write(1, "Error\nMalloc : param structure not initiated\n", 45);
	if (option == 4)
		write(1, "Error\nMalloc : map structure not initiated\n", 43);
	return (-1);
}

int		write_init_errors2(int option)
{
	if (option == 1)
		write(1, "Error\nMalloc : game structure not initiated\n", 44);
	if (option == 2)
		write(1, "Error\nMalloc : keys structure not initiated\n", 44);
	if (option == 3)
		write(1, "Error\nMalloc : ray structure not initiated\n", 43);
	if (option == 4)
		write(1, "Error\nMalloc : player structure not initiated\n", 46);
	if (option == 5)
		write(1, "Error\nMalloc : window structure not initiated\n", 46);
	if (option == 6)
		write(1, "Error\nMalloc : player structure not initiated\n", 46);
	return (-1);
}

int		write_map_errors(int option)
{
	if (option == 1)
	{
		write(1, "Error\nMap : map not closed", 26);
		write(1, " or invalid char outside the map\n", 33);
	}
	if (option == 2)
		write(1, "Error\nMap : invalid char detected\n", 34);
	if (option == 3)
		write(1, "Error\nMap : more than one player detected\n", 42);
	if (option == 4)
		write(1, "Error\nMap : no player detected\n", 31);
	if (option == 5)
		write(1, "Error\nMap : no map detected\n", 28);
	if (option == 6)
	{
		write(1, "Error\nMap : with this size, the map can't be", 44);
		write(1, " closed AND have a player in it.\n", 33);
	}
	return (-1);
}

int		write_argument_errors(int option)
{
	if (option == 1)
		write(1, "Error\nWrong number of arguments\n", 32);
	if (option == 2)
		write(1, "Error\nMap needs to have .cub format\n", 36);
	if (option == 3)
		write(1, "Error\nInvalid option\n", 21);
	return (-1);
}

int		write_missing_parameter(t_params *params)
{
	write(1, "Error\n", 6);
	if (params->no_path == NULL)
		write(1, "You need to add a North texture\n", 32);
	if (params->so_path == NULL)
		write(1, "You need to add a South texture\n", 32);
	if (params->we_path == NULL)
		write(1, "You need to add a West texture\n", 31);
	if (params->ea_path == NULL)
		write(1, "You need to add a East texture\n", 31);
	if (params->sprite == NULL)
		write(1, "You need to add a Sprite texture\n", 33);
	return (-1);
}
