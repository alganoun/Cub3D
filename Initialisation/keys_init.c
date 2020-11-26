/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 02:27:52 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/30 19:16:54 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	keys_init(t_keys **keys)
{
	if (*keys)
	{
		(*keys)->left = 0;
		(*keys)->right = 0;
		(*keys)->w = 0;
		(*keys)->a = 0;
		(*keys)->s = 0;
		(*keys)->d = 0;
		(*keys)->shift = 0;
		(*keys)->esc = 0;
	}
}

int		keys_create(t_game **game, t_all **all)
{
	if (!((*game)->keys = malloc(sizeof(t_keys))))
		return ((*all)->errors->keys_malloc = -1);
	keys_init(&((*game)->keys));
	return (0);
}
