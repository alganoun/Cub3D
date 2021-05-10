/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:38:42 by allanganoun       #+#    #+#             */
/*   Updated: 2020/11/25 22:33:54 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	check_whitespace(char **str)
{
	int i;

	i = 0;
	while (((*str)[0] >= 9 && (*str)[0] <= 13) || (*str)[0] == 32)
		(*str)++;
	if ((*str)[0] != '\0')
	{
		i = ft_strlen((*str)) - 1;
		while (((*str)[i] >= 9 && (*str)[i] <= 13) || (*str)[i] == 32)
			i--;
		(*str)[i + 1] = '\0';
	}
}

int		ft_digitnb(int nb)
{
	int digitnb;

	digitnb = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		digitnb++;
	}
	return (digitnb);
}

char	*ft_strcpy(char *src, char *dest)
{
	int i;

	i = 0;
	if (!(dest = malloc(ft_strlen(src) * sizeof(char))))
		return (NULL);
	while (src && dest && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
