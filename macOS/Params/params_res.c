/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:35:01 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/26 01:25:19 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		single_res_check(t_params *params)
{
	if (params->h_res != -1)
		if (params->v_res == -1)
		{
			write(1, "Error\nParsing : resolution error detected\n", 42);
			return (-1);
		}
	return (0);
}

int		res_find_check(char *str, t_params **params, int i)
{
	if (str[i] >= '0' && str[i] <= '9' && (*params)->h_res != -1
		&& (*params)->v_res != -1)
	{
		write(1, "Error\nParsing : resolution error detected\n", 42);
		return (-1);
	}
	else if (str[i] >= '0' && str[i] <= '9' && (*params)->h_res == -1)
	{
		(*params)->h_res = ft_atoi_width(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	else if (str[i] >= '0' && str[i] <= '9' && (*params)->h_res != -1)
	{
		(*params)->v_res = ft_atoi_height(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (i);
}

int		ft_res_extract(char *str, t_all **all)
{
	int i;

	i = 1;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' '
			&& (str[i] < 9 || str[i] > 13))
		{
			write(1, "Error\nParsing : resolution error detected\n", 42);
			return (-1);
		}
		else if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		i = res_find_check(str, &((*all)->params), i);
		if (i == -1)
			return (-1);
	}
	if (single_res_check((*all)->params) == -1)
		return (-1);
	(*all)->params->done++;
	return (0);
}
