/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:25:59 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/30 11:33:22 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_params(t_params **params)
{
	if (*params)
	{
		safe_free(&(*params)->no_path);
		safe_free(&(*params)->so_path);
		safe_free(&(*params)->we_path);
		safe_free(&(*params)->ea_path);
		safe_free(&(*params)->sprite);
	}
	safe_free((char **)params);
}

void	free_map(t_map **map_s)
{
	int i;

	i = 0;
	if (*map_s)
	{
		safe_free(&((*map_s)->premap));
		if ((*map_s)->map)
		{
			while ((*map_s)->map[i] != NULL)
				safe_free(&(*map_s)->map[i++]);
			free((*map_s)->map);
			(*map_s)->map = NULL;
		}
	}
	safe_free((char **)map_s);
}

void	free_errors(t_errors **errors)
{
	if (*errors)
	{
		safe_free((char **)errors);
	}
}
