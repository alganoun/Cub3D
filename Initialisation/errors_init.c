/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 20:35:17 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/29 14:03:06 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	errors_init(t_errors **errors)
{
	(*errors)->init_errors = 0;
	(*errors)->params_malloc = 0;
	(*errors)->map_malloc = 0;
	(*errors)->datastruct_malloc = 0;
	(*errors)->map_not_closed = 0;
	(*errors)->map_invalid_char = 0;
	(*errors)->res_col_errors = 0;
	(*errors)->double_params = 0;
	(*errors)->keys_malloc = 0;
	(*errors)->ray_malloc = 0;
	(*errors)->player_malloc = 0;
	(*errors)->window_malloc = 0;
	(*errors)->image_malloc = 0;
	(*errors)->player_found = 0;
}

int		errors_create(t_all **all)
{
	if (!((*all)->errors = malloc(sizeof(t_errors))))
	{
		write(1, "malloc error : errors structure not initiated\n", 50);
		return (-1);
	}
	errors_init(&((*all)->errors));
	return (0);
}
