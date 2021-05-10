/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:32:32 by user42            #+#    #+#             */
/*   Updated: 2020/10/31 01:38:19 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		write_parameters_errors(int option)
{
	if (option == 1)
		write(1, "Error\nMultiple players detected\n", 32);
	if (option == 2)
		write(1, "Error\nWrong resolution detected\n", 32);
	return (-1);
}
