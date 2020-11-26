/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 19:14:33 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/26 16:18:18 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_init2(t_game **game, t_all **all)
{
	if (game_create(game) == -1)
		return (write_init_errors2(1));
	if (keys_create(game, all) == -1)
		return (write_init_errors2(2));
	if (ray_create(game, all) == -1)
		return (write_init_errors2(3));
	if (player_create(game, all) == -1)
		return (write_init_errors2(4));
	if (window_create(game, all) == -1)
		return (write_init_errors2(5));
	if (image_create(game, all) == -1)
		return (write_init_errors2(6));
	return (0);
}

void	fill_window_data(t_game **game)
{
	(*game)->window->mlx_ptr = mlx_init();
	mlx_get_screen_size((*game)->window->mlx_ptr,
		&((*game)->window->max_width), &((*game)->window->max_height));
	if ((*game)->window->width > (*game)->window->max_width)
		(*game)->window->width = (*game)->window->max_width;
	if ((*game)->window->height > (*game)->window->max_height)
		(*game)->window->height = (*game)->window->max_height;
	if ((*game)->save != 1)
		(*game)->window->win_ptr = mlx_new_window((*game)->window->mlx_ptr,
				(*game)->window->width, (*game)->window->height, "Cub3D");
	(*game)->image->img_ptr = mlx_new_image((*game)->window->mlx_ptr,
				(*game)->window->width, (*game)->window->height);
	(*game)->image->img_data = mlx_get_data_addr((*game)->image->img_ptr,
		&((*game)->image->bpp), &((*game)->image->size_line),
			&((*game)->image->endian));
}

int		raycasting_loop(t_game **game)
{
	if (raycasting(game) == -1)
		game_exit(game, &((*game)->all));
	key_manager(*game);
	return (0);
}

void	game_on_screen(t_game *game)
{
	mlx_hook(game->window->win_ptr, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->window->win_ptr, 3, 1L << 1, key_released, game);
	mlx_hook(game->window->win_ptr, 33, 1L << 17, close_window, game);
	mlx_loop_hook(game->window->mlx_ptr, raycasting_loop, &game);
	mlx_loop(game->window->mlx_ptr);
}

void	rendering(t_all **all)
{
	t_game *game;

	if (ft_init2(&game, all) == -1)
		game_exit(&game, all);
	if (params_picker(&game, (*all)) == -1)
		game_exit(&game, all);
	fill_window_data(&game);
	if (game->save == 1)
	{
		if (raycasting(&game) == -1)
		{
			write(1, "Error\nSomething went wrong with ", 32);
			write(1, "the raycasting process\n", 23);
			game_exit(&game, all);
		}
		game_exit(&game, all);
	}
	else
		game_on_screen(game);
}
