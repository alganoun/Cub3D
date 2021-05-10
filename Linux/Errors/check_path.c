/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:19:46 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/02 15:05:16 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_path(char *str, int option)
{
	int fd;

	if ((fd = open(str, O_RDONLY)) < 0)
	{
		if (option == 1)
			write(1, "Error\nNorth texture file invalid\n", 33);
		else if (option == 2)
			write(1, "Error\nSouth texture file invalid\n", 33);
		else if (option == 3)
			write(1, "Error\nWest texture file invalid\n", 32);
		else if (option == 4)
			write(1, "Error\nEast texture file invalid\n", 32);
		else if (option == 5)
			write(1, "Error\nSprite texture file invalid\n", 34);
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int		check_textures(t_params *params)
{
	if (check_path(params->no_path, 1) == -1)
		return (-1);
	if (check_path(params->so_path, 2) == -1)
		return (-1);
	if (check_path(params->we_path, 3) == -1)
		return (-1);
	if (check_path(params->ea_path, 4) == -1)
		return (-1);
	if (check_path(params->sprite, 5) == -1)
		return (-1);
	return (0);
}
