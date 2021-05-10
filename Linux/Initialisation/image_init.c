/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 02:53:07 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/29 14:04:30 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	image_init(t_image **image)
{
	if (*image)
	{
		(*image)->bpp = 0;
		(*image)->size_line = 0;
		(*image)->endian = 0;
		(*image)->width = 0;
		(*image)->height = 0;
		(*image)->img_ptr = NULL;
		(*image)->img_data = NULL;
		(*image)->path = NULL;
		(*image)->pos = 0;
	}
}

int		image_create(t_game **game, t_all **all)
{
	if (!((*game)->image = malloc(sizeof(t_image))))
		return ((*all)->errors->image_malloc = -1);
	image_init(&((*game)->image));
	return (0);
}
