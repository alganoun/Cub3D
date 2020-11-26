/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:11:43 by allanganoun       #+#    #+#             */
/*   Updated: 2020/10/29 10:35:50 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	params_init(t_params **params)
{
	if (*params)
	{
		(*params)->h_res = -1;
		(*params)->v_res = -1;
		(*params)->floor_r = -1;
		(*params)->floor_g = -1;
		(*params)->floor_b = -1;
		(*params)->ceil_r = -1;
		(*params)->ceil_g = -1;
		(*params)->ceil_b = -1;
		(*params)->no_path = NULL;
		(*params)->so_path = NULL;
		(*params)->we_path = NULL;
		(*params)->ea_path = NULL;
		(*params)->sprite = NULL;
		(*params)->done = 0;
	}
}

int		params_create(t_all **all)
{
	if (!((*all)->params = (t_params *)malloc(sizeof(t_params))))
		return ((*all)->errors->map_malloc = -1);
	params_init(&((*all)->params));
	return (0);
}
