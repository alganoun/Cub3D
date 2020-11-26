/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:58:18 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/30 11:32:29 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sorted_insert(t_sprites **begin, t_sprites *new_sprite)
{
	t_sprites *current;

	if ((*begin) == NULL || (*begin)->distance <= new_sprite->distance)
	{
		new_sprite->next = (*begin);
		(*begin) = new_sprite;
	}
	else
	{
		current = (*begin);
		while (current->next != NULL
			&& current->next->distance >= new_sprite->distance)
		{
			current = current->next;
		}
		new_sprite->next = current->next;
		current->next = new_sprite;
	}
}

void	projection_sprite(t_player *player, t_window *window,
	t_sprites **current)
{
	(*current)->sprite_x = (*current)->sprite->x - (player->x - 0.5);
	(*current)->sprite_y = (*current)->sprite->y - (player->y - 0.5);
	(*current)->inv_det = 1.0
		/ (player->plan_x * player->dir_y - player->plan_y
		* player->dir_x);
	(*current)->transform_x = (*current)->inv_det
		* (player->dir_y *
		(*current)->sprite_x - player->dir_x * (*current)->sprite_y);
	(*current)->transform_y = (*current)->inv_det
	* (player->plan_x *
		(*current)->sprite_y - player->plan_y * (*current)->sprite_x);
	(*current)->sprite_screen_x = (int)((window->width / 2)
	* (1 + (*current)->transform_x / (*current)->transform_y));
}

void	size_sprite(t_sprites **current, t_window *window)
{
	(*current)->sprite_height = abs((int)(window->height
		/ (*current)->transform_y));
	(*current)->draw_start_y = -(*current)->sprite_height
		/ 2 + window->height / 2;
	if ((*current)->draw_start_y < 0)
		(*current)->draw_start_y = 0;
	(*current)->draw_end_y = (*current)->sprite_height
		/ 2 + window->height / 2;
	if ((*current)->draw_end_y >= window->height)
		(*current)->draw_end_y = window->height - 1;
	(*current)->sprite_width = abs((int)(window->height
		/ (*current)->transform_y));
	(*current)->draw_start_x = -(*current)->sprite_width / 2
	+ (*current)->sprite_screen_x;
	if ((*current)->draw_start_x < 0)
		(*current)->draw_start_x = 0;
	(*current)->draw_end_x = (*current)->sprite_width
		/ 2 + (*current)->sprite_screen_x;
	if ((*current)->draw_end_x >= window->width)
		(*current)->draw_end_x = window->width - 1;
}

void	sprite_process(t_game *game, t_ray *ray)
{
	t_sprite	*new;
	t_sprites	*new_sprite;
	t_sprites	*current;
	double		distance;

	if (!(new = (t_sprite *)malloc(sizeof(t_sprite))))
		return ;
	new->x = ray->map_x;
	new->y = ray->map_y;
	current = game->sprites_begin;
	while (current != NULL)
	{
		if (current->sprite->x == new->x
			&& current->sprite->y == new->y)
		{
			safe_free((char **)&new);
			return ;
		}
		current = current->next;
	}
	distance = (game->player->x - new->x) * (game->player->x - new->x)
		+ (game->player->y - new->y) * (game->player->y - new->y);
	new_sprite = sprites_init(new, distance);
	sorted_insert(&(game->sprites_begin), new_sprite);
}
