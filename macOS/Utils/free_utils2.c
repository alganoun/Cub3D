/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 07:53:31 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/26 16:05:53 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_sprites_chain(t_sprites **begin)
{
	t_sprites	*current;

	current = (*begin);
	while ((*begin)->next != NULL)
	{
		current = (*begin)->next;
		(*begin)->next = current->next;
		current->next = NULL;
		safe_free((char **)&(current->sprite));
		safe_free((char **)&current);
	}
	safe_free((char **)&((*begin)->sprite));
	safe_free((char **)begin);
}

void	free_ray(t_ray **ray)
{
	safe_free((char **)&((*ray)->z_buffer));
	safe_free((char **)ray);
}

void	free_window(t_window **window)
{
	if ((*window)->win_ptr)
		mlx_destroy_window((*window)->mlx_ptr, (*window)->win_ptr);
	safe_free((char **)&(*window)->mlx_ptr);
	safe_free((char **)window);
}

void	free_image(t_image **image, t_window **window)
{
	if ((*image)->img_ptr)
		mlx_destroy_image((*window)->mlx_ptr, (*image)->img_ptr);
	safe_free((char **)image);
}

int		free_game(t_game **game)
{
	free_ray(&((*game)->ray));
	free_image(&((*game)->image), &((*game)->window));
	safe_free((char **)&((*game)->player));
	free_window(&((*game)->window));
	safe_free((char **)&(*game)->keys);
	safe_free((char **)game);
	return (-1);
}
