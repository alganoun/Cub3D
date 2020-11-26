/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:33:51 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/26 00:52:29 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_part_of_the_map(char *str, t_map **map_s)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0')
			return ((*map_s)->mapfound = 1);
		i++;
	}
	if ((*map_s)->mapfound == 1)
		return ((*map_s)->mapdone = 1);
	return (0);
}

int		map_builder2(t_map **map_s, int line_nb)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while ((*map_s)->premap[j] == '\n')
		j++;
	while (line_nb-- > 0)
	{
		if (!((*map_s)->map[i] =
			(char *)ft_calloc(ft_strlen_nl(&(*map_s)->premap[j]) + 1, 1)))
			return (-1);
		while ((*map_s)->premap[j] != '\n')
			(*map_s)->map[i][k++] = (*map_s)->premap[j++];
		(*map_s)->map[i][k] = '\0';
		k = 0;
		j++;
		i++;
	}
	(*map_s)->map[i] = NULL;
	return (0);
}

int		check_new_line(t_map **map_s, int i, int line_nb)
{
	while ((*map_s)->premap[i])
	{
		if ((*map_s)->premap[i] == '\n')
		{
			if ((*map_s)->premap[i + 1] == '\n')
				return (write_map_errors(1));
			line_nb++;
		}
		i++;
	}
	if (line_nb + 1 <= 2)
		return (write_map_errors(6));
	return (line_nb);
}

int		map_builder(t_map **map_s)
{
	int i;
	int j;
	int line_nb;

	i = 0;
	j = 0;
	line_nb = 0;
	while ((*map_s)->premap[i] == '\n')
		i++;
	if ((*map_s)->premap[i] == '\0')
		return (write_map_errors(5));
	while ((*map_s)->premap[j])
		j++;
	while ((*map_s)->premap[j - 1] == '\n')
		j--;
	(*map_s)->premap[j] = '\0';
	if ((line_nb = check_new_line(map_s, i, line_nb)) == -1)
		return (-1);
	if (!((*map_s)->map = (char **)ft_calloc(line_nb + 2, sizeof(char *))))
		return (-1);
	map_builder2(map_s, line_nb + 1);
	return (0);
}

int		map_extraction(char *str, t_map **map_s)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = 0;
	j = 0;
	len = ft_strlen((*map_s)->premap) + ft_strlen(str);
	if (!(tmp = (char *)ft_calloc(len + 2, 1)))
		return (-1);
	while ((*map_s)->premap[i])
		tmp[j++] = (*map_s)->premap[i++];
	i = 0;
	free((*map_s)->premap);
	while (str[i])
		tmp[j++] = str[i++];
	tmp[j++] = '\n';
	tmp[j] = '\0';
	(*map_s)->premap = tmp;
	tmp = NULL;
	return (0);
}
