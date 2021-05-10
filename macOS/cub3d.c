/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allanganoun <allanganoun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:53:05 by allanganoun       #+#    #+#             */
/*   Updated: 2021/05/10 17:00:03 by allanganoun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		free_all(t_all **all)
{
	if (*all)
	{
		free_params(&((*all)->params));
		free_map(&((*all)->map_s));
		free_errors(&((*all)->errors));
		safe_free((char **)all);
	}
	return (0);
}

int		ft_init(t_all **all)
{
	if (overall_create(all) == -1)
		return (write_init_errors(1));
	if (errors_create(all) == -1)
		return (write_init_errors(2));
	if (params_create(all) == -1)
		return (write_init_errors(3));
	if (map_create(all) == -1)
		return (write_init_errors(4));
	return (0);
}

int		ft_parsing(int fd, t_all **all)
{
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	while (ret > 0)
	{
		ret = get_next_line(fd, &str);
		if ((*all)->params->done < 8)
		{
			if (params_parsing(str, all) == -1)
				return (safe_free(&str));
		}
		else
			map_extraction(str, &((*all)->map_s));
		safe_free(&str);
	}
	if ((*all)->params->done < 8)
		return (write_missing_parameter((*all)->params));
	if (map_builder(&((*all)->map_s)) == -1)
		return (safe_free(&str));
	if (map_checker(all) == -1)
		return (safe_free(&str));
	safe_free(&str);
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd;
	int			save;
	t_all		*all;

	all = NULL;
	save = 0;
	fd = 0;
	if (check_args(argc, argv) == -1)
		return (0);
	if (argc == 3)
		save = 1;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		write(1, "Error\nPlease chose a valid Map\n", 31);
		return (-1);
	}
	if (ft_init(&all) == -1)
		return (free_all(&all));
	all->params->save = save;
	if (ft_parsing(fd, &all) == -1)
		return (free_all(&all));
	if (check_textures(all->params) == -1)
		return (free_all(&all));
	rendering(&all);
	return (0);
}
