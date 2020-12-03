/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_fcol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:25:01 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/30 11:44:18 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		fcol_find_check2(char *str, t_params **params, int i)
{
	if (str[i] >= '0' && str[i] <= '9' && (*params)->floor_r == -1)
	{
		(*params)->floor_r = ft_atoi_col(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	else if (str[i] >= '0' && str[i] <= '9' && (*params)->floor_g == -1)
	{
		(*params)->floor_g = ft_atoi_col(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	else if (str[i] >= '0' && str[i] <= '9' && (*params)->floor_b == -1)
	{
		(*params)->floor_b = ft_atoi_col(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (i);
}

int		fcol_find_check(char *str, t_params **params, int i)
{
	if (str[i] >= '0' && str[i] <= '9' && (*params)->floor_r != -1
		&& (*params)->floor_g != -1 && (*params)->floor_b != -1)
	{
		write(1, "Error\nParsing : floor colors error detected\n", 44);
		return (-1);
	}
	if (str[i] < '0' || str[i] > '9')
	{
		write(1, "Error\nParsing : floor colors error detected\n", 44);
		return (-1);
	}
	return (fcol_find_check2(str, params, i));
}

int		check_fcol(t_all **all)
{
	if ((*all)->params->floor_r == -1 || (*all)->params->floor_g == -1
			|| (*all)->params->floor_b == -1)
	{
		write(1, "Error\nParsing : floor colors error detected\n", 44);
		return (-1);
	}
	return (0);
}

int		f_col_extract2(char *str, t_all **all, int i)
{
	if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != ','
		&& (str[i] < 9 || str[i] > 13))
	{
		write(1, "Error\nParsing : floor colors error detected\n", 44);
		return (-1);
	}
	if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == ',' || i == 0)
	{
		if (i != 0)
			i++;
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		i = fcol_find_check(str, &((*all)->params), i);
		if (i == -1)
			return (-1);
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
	}
	return (i);
}

int		f_col_extract(char *str, t_all **all)
{
	int i;

	i = 0;
	check_whitespace(&str);
	while (str[i])
	{
		i = f_col_extract2(str, all, i);
		if (i == -1)
			return (-1);
		if (str[i] >= '0' && str[i] <= '9')
		{
			write(1, "Error\nParsing : floor colors error detected\n", 44);
			return (-1);
		}
	}
	if (check_fcol(all) == -1)
		return (-1);
	(*all)->params->done++;
	return (0);
}
