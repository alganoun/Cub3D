/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 23:26:32 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/29 13:45:49 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		double_params2(char *str, t_params **params)
{
	if (str[0] == 'E' && str[1] == 'A' && (*params)->ea_path != NULL)
	{
		write(1, "Error\nParsing : 2 East texture detected\n", 40);
		return (-1);
	}
	else if (str[0] == 'S' && str[1] != 'O' && (*params)->sprite != NULL)
	{
		write(1, "Error\nParsing : 2 Sprite texture detected\n", 42);
		return (-1);
	}
	else if (str[0] == 'F' && (*params)->floor_r != -1
			&& (*params)->floor_g != -1 && (*params)->floor_b != -1)
	{
		write(1, "Error\nParsing : 2 floor colors detected\n", 40);
		return (-1);
	}
	else if (str[0] == 'C' && (*params)->ceil_r != -1
			&& (*params)->ceil_g != -1 && (*params)->ceil_b != -1)
	{
		write(1, "Error\nParsing : 2 ceiling colors detected\n", 42);
		return (-1);
	}
	return (0);
}

int		double_params(char *str, t_params **params)
{
	if (str[0] == 'R' && (*params)->h_res != -1 && (*params)->v_res != -1)
	{
		write(1, "Error\nParsing : 2 resolution detected\n", 38);
		return (-1);
	}
	else if (str[0] == 'N' && str[1] == 'O' && (*params)->no_path != NULL)
	{
		write(1, "Error\nParsing : 2 North texture detected\n", 41);
		return (-1);
	}
	else if (str[0] == 'S' && str[1] == 'O' && (*params)->so_path != NULL)
	{
		write(1, "Error\nParsing : 2 South texture detected\n", 41);
		return (-1);
	}
	else if (str[0] == 'W' && str[1] == 'E' && (*params)->we_path != NULL)
	{
		write(1, "Error\nParsing : 2 West texture detected\n", 40);
		return (-1);
	}
	if (double_params2(str, params) == -1)
		return (-1);
	return (0);
}
