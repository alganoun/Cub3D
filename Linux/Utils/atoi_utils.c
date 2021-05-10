/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:05:52 by allanganoun       #+#    #+#             */
/*   Updated: 2020/12/03 11:47:18 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_atoi_col(char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (nb > 255)
		{
			write(1, "/!\\ Some RGB values are too high\n", 33);
			write(1, "Those values have been set to 255\n\n", 35);
			return (255);
		}
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb);
}

int		ft_atoi_width(char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (nb >= 2147483647)
			return (2147483647);
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (nb <= 9)
	{
		nb = 10;
		write(1, "/!\\ Horizontal resolution set to 10 to avoid crash\n", 50);
	}
	if (nb == 3000000000)
		return (300000000);
	return (nb);
}

int		ft_atoi_height(char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (nb >= 2147483647)
			return (2147483647);
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (nb <= 9)
	{
		nb = 10;
		write(1, "/!\\ Vertical resolution set to 10 to avoid crash\n", 48);
	}
	return (nb);
}

char	*ft_itoa_b16(int nb)
{
	char *str;
	char *result;
	char *base;

	base = "0123456789ABCDEF";
	result = NULL;
	while (nb != 0)
	{
		if (!(str = malloc(2)))
			return (NULL);
		str[0] = base[nb % 16];
		result = ft_strjoin(str, result);
		safe_free(&str);
		nb = nb / 16;
	}
	if (ft_strlen(result) == 1)
		result = ft_strjoin("0", result);
	return (result);
}
