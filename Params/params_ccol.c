/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_ccol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 23:08:16 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/24 10:48:58 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ccol_find_check2(char *str, t_params **params, int i)
{
	if (str[i] >= '0' && str[i] <= '9' && (*params)->ceil_r == -1)
	{
		(*params)->ceil_r = ft_atoi_col(&str[i]);
		i = i + ft_digitnb((*params)->ceil_r);
		if ((*params)->ceil_r > 255)
			(*params)->ceil_r = 255;
	}
	else if (str[i] >= '0' && str[i] <= '9' && (*params)->ceil_g == -1)
	{
		(*params)->ceil_g = ft_atoi_col(&str[i]);
		i = i + ft_digitnb((*params)->ceil_g);
		if ((*params)->ceil_g > 255)
			(*params)->ceil_g = 255;
	}
	else if (str[i] >= '0' && str[i] <= '9' && (*params)->ceil_b == -1)
	{
		(*params)->ceil_b = ft_atoi_col(&str[i]);
		i = i + ft_digitnb((*params)->ceil_b);
		if ((*params)->ceil_b > 255)
			(*params)->ceil_b = 255;
	}
	return (i);
}

int		ccol_find_check(char *str, t_params **params, int i)
{
	if (str[i] >= '0' && str[i] <= '9' && (*params)->ceil_r != -1
		&& (*params)->ceil_g != -1 && (*params)->ceil_b != -1)
	{
		write(1, "Error\nParsing : ceil colors error detected\n", 44);
		return (-1);
	}
	if (str[i] < '0' || str[i] > '9')
	{
		write(1, "Error\nParsing : ceil colors error detected\n", 44);
		return (-1);
	}
	return (ccol_find_check2(str, params, i));
}

int		check_ccol(t_all **all)
{
	if ((*all)->params->ceil_r == -1 || (*all)->params->ceil_g == -1
			|| (*all)->params->ceil_b == -1)
	{
		write(1, "Error\nParsing : ceil colors error detected\n", 44);
		return (-1);
	}
	return (0);
}

int		c_col_extract2(char *str, t_all **all, int i)
{
	if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != ','
		&& (str[i] < 9 || str[i] > 13))
	{
		write(1, "Error\nParsing : ceil colors error detected\n", 44);
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
		i = ccol_find_check(str, &((*all)->params), i);
		if (i == -1)
			return (-1);
		while ((str[i] >= '0' && str[i] <= '9') || str[i] == ' '
			|| (str[i] >= 9 && str[i] <= 13))
			i++;
	}
	return (i);
}

int		c_col_extract(char *str, t_all **all)
{
	int i;

	i = 0;
	check_whitespace(&str);
	while (str[i])
	{
		i = c_col_extract2(str, all, i);
		if (i == -1)
			return (-1);
		if (str[i] >= '0' && str[i] <= '9')
			return (-1);
	}
	if (check_ccol(all) == -1)
		return (-1);
	(*all)->params->done++;
	return (0);
}
