/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:17:55 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/26 16:13:17 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_textures_info(t_image **text, t_window *window)
{
	if (!((*text)->img_ptr = mlx_xpm_file_to_image(window->mlx_ptr,
			(*text)->path, &((*text)->width), &((*text)->height))))
	{
		write(1, "Error\nTexture data corrupted\n", 30);
		return (-1);
	}
	if (!((*text)->img_data =
		mlx_get_data_addr((*text)->img_ptr, &((*text)->bpp),
		&((*text)->size_line), &((*text)->endian))))
	{
		write(1, "Error\nTexture data corrupted\n", 30);
		return (-1);
	}
	return (0);
}

void	texture_choice(t_image **text, t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		(*text)->path = game->we_path;
	if (ray->side == 1)
		(*text)->path = game->ea_path;
	if (ray->side == 2)
		(*text)->path = game->no_path;
	if (ray->side == 3)
		(*text)->path = game->so_path;
}
