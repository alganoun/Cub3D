/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:20:32 by allanganoun       #+#    #+#             */
/*   Updated: 2020/12/01 15:34:23 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_strlen_nl(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*t;

	i = 0;
	t = s;
	while (i < n)
	{
		t[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*t;
	size_t	len;

	len = count * size;
	if (!(t = malloc(len)))
		return (NULL);
	ft_bzero(t, len);
	return (t);
}

int		check_args(int argc, char **argv)
{
	int		i;
	char	*save;

	i = 0;
	save = "--save";
	if (argc > 3 || argc < 2)
		return (write_argument_errors(1));
	else if (argc == 2)
	{
		if (extension_checker(argv[1], ".cub") == -1)
			return (write_argument_errors(2));
	}
	else if (argc == 3)
	{
		if (extension_checker(argv[1], ".cub") == -1)
			return (write_argument_errors(2));
		while (save[i++])
			if (argv[2][i] != save[i])
				return (write_argument_errors(3));
	}
	return (0);
}

int		extension_checker(char *str, char *ext)
{
	int i;
	int j;

	i = ft_strlen(str) - 1;
	j = 3;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i--;
	while (ext[j] != '.' && (str[i] == ext[j]))
	{
		i--;
		j--;
	}
	if (ext[j] == '.' && str[i] == '.')
		return (0);
	else
		return (-1);
}
