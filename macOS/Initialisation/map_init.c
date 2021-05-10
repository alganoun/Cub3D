/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:16:18 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/29 14:06:29 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_init(t_map **map_s)
{
	if (*map_s)
	{
		(*map_s)->premap = NULL;
		(*map_s)->map = NULL;
		(*map_s)->mapfound = 0;
		(*map_s)->mapdone = 0;
	}
}

int		map_create(t_all **all)
{
	if (!((*all)->map_s = malloc(sizeof(t_map))))
		return ((*all)->errors->map_malloc = -1);
	map_init(&((*all)->map_s));
	if (!((*all)->map_s->premap = malloc(1)))
		return ((*all)->errors->map_malloc = -1);
	(*all)->map_s->premap[0] = '\0';
	return (0);
}
