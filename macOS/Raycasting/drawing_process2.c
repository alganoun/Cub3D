/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_process2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 06:02:37 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/29 21:50:31 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	texture_put(t_game *game, t_sprites *sprite, t_image *sprite_text)
{
	int	index;
	int	index_sprite;

	index = sprite->y * game->image->size_line
	+ sprite->x * game->image->bpp / 8;
	index_sprite = sprite->text_y * sprite_text->size_line + sprite->text_x
	* sprite_text->bpp / 8;
	game->image->img_data[index] = sprite_text->img_data[index_sprite];
	game->image->img_data[index + 1] =
	sprite_text->img_data[index_sprite + 1];
	game->image->img_data[index + 2] =
	sprite_text->img_data[index_sprite + 2];
}

void	sprite_put(t_game *game, t_window *window, t_sprites *sprite,
		t_image *sprite_text)
{
	int	d;
	int	color;
	int	index;

	d = sprite->y * sprite_text->size_line - window->height
	* sprite_text->size_line / 2 + sprite->sprite_height
	* sprite_text->size_line / 2;
	sprite->text_y = (int)(d * sprite_text->height / sprite->sprite_height
	/ sprite_text->size_line);
	index = sprite->text_y * sprite_text->size_line
	+ sprite->text_x * sprite_text->bpp / 8;
	color = sprite_text->img_data[index]
	+ sprite_text->img_data[index + 1]
	+ sprite_text->img_data[index + 2];
	if (color != 0)
		texture_put(game, sprite, sprite_text);
}

void	set_sprite_on_image(t_game *game, t_sprites **current,
			t_image *sprite_text, t_ray *ray)
{
	(*current)->x = (*current)->draw_start_x;
	while ((*current)->x < (*current)->draw_end_x)
	{
		if ((*current)->transform_y > 0
			&& (*current)->transform_y < ray->z_buffer[(*current)->x])
		{
			(*current)->y = (*current)->draw_start_y;
			(*current)->text_x = (int)(sprite_text->size_line
			* ((*current)->x - (-(*current)->sprite_width / 2
			+ (*current)->sprite_screen_x)) * sprite_text->width
			/ (*current)->sprite_width) / sprite_text->size_line;
			while ((*current)->y < (*current)->draw_end_y)
			{
				sprite_put(game, game->window, *current, sprite_text);
				(*current)->y++;
			}
		}
		(*current)->x++;
	}
}

int		draw_sprites(t_game **game, t_window *window, t_ray *ray)
{
	t_sprites	*current;
	t_image		*sprite_text;

	if (!(sprite_text = malloc(sizeof(t_image))))
		return (-1);
	image_init(&sprite_text);
	sprite_text->path = (*game)->sprite;
	current = (*game)->sprites_begin;
	if (get_textures_info(&sprite_text, window) == -1)
		return (-1);
	while (current != NULL)
	{
		projection_sprite((*game)->player, window, &current);
		size_sprite(&current, window);
		set_sprite_on_image(*game, &current, sprite_text, ray);
		current = current->next;
	}
	free_sprites_chain(&((*game)->sprites_begin));
	free_image(&sprite_text, &window);
	return (0);
}
