/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 04:37:13 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/26 16:13:35 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pixel_draw(t_image *image, int x, int y, int color)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	image->img_data[y * image->size_line + x * image->bpp / 8] = r;
	image->img_data[y * image->size_line + x * image->bpp / 8 + 1] = g;
	image->img_data[y * image->size_line + x * image->bpp / 8 + 2] = b;
}

void	set_color_on_image(t_game **game, t_ray *ray)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
	{
		pixel_draw((*game)->image, ray->x, y, (*game)->ccol);
		y++;
	}
	y = ray->draw_end;
	while (y < (*game)->window->height)
	{
		pixel_draw((*game)->image, ray->x, y, (*game)->fcol);
		y++;
	}
}

void	texture_projection(t_game **game, t_image *texture, t_ray **ray)
{
	int	d;

	(*ray)->y = (*ray)->draw_start;
	while ((*ray)->y <= ((*ray)->draw_end))
	{
		d = (*ray)->y * texture->size_line - (*game)->window->height
			* texture->size_line / 2 + (*ray)->line_h * texture->size_line / 2;
		(*ray)->text_y = ((d * texture->height) / (*ray)->line_h)
			/ texture->size_line;
		(*game)->image->img_data[(*ray)->y * (*game)->image->size_line
			+ (*ray)->x * (*game)->image->bpp / 8] =
			texture->img_data[(*ray)->text_y * texture->size_line
			+ (*ray)->text_x * (texture->bpp / 8)];
		(*game)->image->img_data[(*ray)->y * (*game)->image->size_line
			+ (*ray)->x * (*game)->image->bpp / 8 + 1] =
			texture->img_data[(*ray)->text_y * texture->size_line
			+ (*ray)->text_x * (texture->bpp / 8) + 1];
		(*game)->image->img_data[(*ray)->y * (*game)->image->size_line
			+ (*ray)->x * (*game)->image->bpp / 8 + 2] =
			texture->img_data[(*ray)->text_y * texture->size_line
			+ (*ray)->text_x * (texture->bpp / 8) + 2];
		(*ray)->y++;
	}
}

int		set_wall(t_game **game, t_ray **ray)
{
	int		text_x;
	t_image	*text;

	if (!((text = malloc(sizeof(t_image)))))
		return (-1);
	image_init(&text);
	texture_choice(&text, *game, *ray);
	if (get_textures_info(&text, (*game)->window) == -1)
	{
		free_image(&text, &((*game)->window));
		return (-1);
	}
	text_x = (int)((*ray)->wall_x * (double)text->width);
	if (((*ray)->side == 0 || (*ray)->side == 1) && (*ray)->dir_x > 0)
		text_x = text->width - text_x - 1;
	if (((*ray)->side == 2 || (*ray)->side == 3) && (*ray)->dir_y < 0)
		text_x = text->width - text_x - 1;
	(*ray)->text_x = text_x;
	texture_projection(game, text, ray);
	free_image(&text, &((*game)->window));
	return (0);
}

int		draw_walls(t_game **game, t_ray **ray)
{
	(*ray)->draw_start = -((*ray)->line_h / 2) + (*game)->window->height / 2;
	(*ray)->draw_end = (*ray)->line_h / 2 + (*game)->window->height / 2;
	if ((*ray)->draw_start < 0 || (*ray)->draw_start > (*ray)->draw_end)
		(*ray)->draw_start = 0;
	if ((*ray)->draw_end >= (*game)->window->height
		|| (*ray)->draw_end < (*ray)->draw_start)
		(*ray)->draw_end = (*game)->window->height - 1;
	if ((*ray)->side == 0 || (*ray)->side == 1)
		(*ray)->wall_x = (*game)->player->y +
			(*ray)->walldist_p * (*ray)->dir_y;
	else
		(*ray)->wall_x = (*game)->player->x +
			(*ray)->walldist_p * (*ray)->dir_x;
	(*ray)->wall_x -= floor((*ray)->wall_x);
	if (set_wall(game, ray) == -1)
		return (-1);
	set_color_on_image(game, *ray);
	return (0);
}
