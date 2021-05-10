/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overall_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:03:15 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/29 14:07:05 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	overall_init(t_all **all)
{
	if (*all)
	{
		(*all)->params = NULL;
		(*all)->map_s = NULL;
		(*all)->errors = NULL;
	}
}

int		overall_create(t_all **all)
{
	if (!(*all = malloc(sizeof(t_all))))
	{
		write(1, "malloc error : Overall structure not initiated\n", 47);
		return (-1);
	}
	overall_init(all);
	return (0);
}
