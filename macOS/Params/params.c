/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allanganoun <allanganoun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:37:56 by allanganoun       #+#    #+#             */
/*   Updated: 2021/05/10 15:55:04 by allanganoun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int		params_extraction(char *str, t_all **all)
{
	if (str[0] == 'R' && is_white_space(str[1]) == 1)
		return (ft_res_extract(str + 1, all));
	else if (str[0] == 'N' && str[1] == 'O' && is_white_space(str[2]) == 1)
		return (no_text_extract(str + 2, all));
	else if (str[0] == 'S' && str[1] == 'O' && is_white_space(str[2]) == 1)
		return (so_text_extract(str + 2, all));
	else if (str[0] == 'W' && str[1] == 'E' && is_white_space(str[2]) == 1)
		return (we_text_extract(str + 2, all));
	else if (str[0] == 'E' && str[1] == 'A' && is_white_space(str[2]) == 1)
		return (ea_text_extract(str + 2, all));
	else if (str[0] == 'S' && is_white_space(str[1]) == 1)
		return (s_text_extract(str + 1, all));
	else if (str[0] == 'F' && is_white_space(str[1]) == 1)
		return (f_col_extract(str + 1, all));
	else if (str[0] == 'C' && is_white_space(str[1]) == 1)
		return (c_col_extract(str + 1, all));
	else if (str[0] == '\0')
		return (0);
	else
	{
		write(1, "Error\nSome parameters are invalid\n", 34);
		return (-1);
	}
	return (0);
}

int		params_parsing(char *str, t_all **all)
{
	check_whitespace(&str);
	if (double_params(str, &((*all)->params)) == -1)
		return (-1);
	if (params_extraction(str, all) == -1)
		return (-1);
	return (0);
}
