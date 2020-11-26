/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:05:52 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/26 01:09:33 by user42           ###   ########lyon.fr   */
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
		if (nb >= 2147483647)
			return (2147483647);
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
