/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 06:49:17 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/29 14:15:18 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_sprites	*sprites_init(t_sprite *sprite, double distance)
{
	t_sprites	*sprites;

	if (!(sprites = (t_sprites *)malloc(sizeof(t_sprites))))
		return (NULL);
	sprites->sprite = sprite;
	sprites->distance = distance;
	sprites->next = NULL;
	sprites->draw_start_x = 0;
	sprites->draw_end_x = 0;
	sprites->draw_start_y = 0;
	sprites->draw_end_y = 0;
	sprites->sprite_x = 0;
	sprites->sprite_y = 0;
	sprites->inv_det = 0;
	sprites->transform_x = 0;
	sprites->transform_y = 0;
	sprites->sprite_screen_x = 0;
	sprites->sprite_height = 0;
	sprites->sprite_width = 0;
	sprites->x = 0;
	sprites->y = 0;
	sprites->text_x = 0;
	sprites->text_y = 0;
	return (sprites);
}
