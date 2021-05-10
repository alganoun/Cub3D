/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allanganoun <allanganoun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:37:37 by allanganoun       #+#    #+#             */
/*   Updated: 2021/05/10 16:03:01 by allanganoun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		no_text_extract(char *str, t_all **all)
{
	check_whitespace(&str);
	if (extension_checker(str, ".xpm") != -1)
	{
		if (!((*all)->params->no_path = ft_strjoin(str, NULL)))
		{
			write(1, "Error\nParameters : malloc error.\n", 33);
			return (-1);
		}
	}
	else
	{
		write(1, "Error\nNorth texture : you need a .xpm file.\n", 44);
		return (-1);
	}
	(*all)->params->done++;
	return (0);
}

int		so_text_extract(char *str, t_all **all)
{
	check_whitespace(&str);
	if (extension_checker(str, ".xpm") != -1)
	{
		if (!((*all)->params->so_path = ft_strjoin(str, NULL)))
		{
			write(1, "Error\nParameters : malloc error.\n", 33);
			return (-1);
		}
	}
	else
	{
		write(1, "Error\nSouth texture : you need a .xpm file.\n", 44);
		return (-1);
	}
	(*all)->params->done++;
	return (0);
}

int		we_text_extract(char *str, t_all **all)
{
	check_whitespace(&str);
	if (extension_checker(str, ".xpm") != -1)
	{
		if (!((*all)->params->we_path = ft_strjoin(str, NULL)))
		{
			write(1, "Error\nParameters : malloc error.\n", 33);
			return (-1);
		}
	}
	else
	{
		write(1, "Error\nWest texture : you need a .xpm file.\n", 43);
		return (-1);
	}
	(*all)->params->done++;
	return (0);
}

int		ea_text_extract(char *str, t_all **all)
{
	check_whitespace(&str);
	if (extension_checker(str, ".xpm") != -1)
	{
		if (!((*all)->params->ea_path = ft_strjoin(str, NULL)))
		{
			write(1, "Error\nParameters : malloc error.\n", 33);
			return (-1);
		}
	}
	else
	{
		write(1, "Error\nEast texture : you need a .xpm file.\n", 43);
		return (-1);
	}
	(*all)->params->done++;
	return (0);
}

int		s_text_extract(char *str, t_all **all)
{
	check_whitespace(&str);
	if (extension_checker(str, ".xpm") != -1)
	{
		if (!((*all)->params->sprite = ft_strjoin(str, NULL)))
		{
			write(1, "Error\nParameters : malloc error.\n", 33);
			return (-1);
		}
	}
	else
	{
		write(1, "Error\nSprite texture : you need a .xpm file.\n", 45);
		return (-1);
	}
	(*all)->params->done++;
	return (0);
}
