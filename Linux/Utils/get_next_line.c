/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:56:09 by hor4tio           #+#    #+#             */
/*   Updated: 2020/10/30 11:34:03 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int		check_error(int fd, t_list **lst, char **line, char **str)
{
	if (!(*str = malloc(1)))
		return (-1);
	(*str)[0] = '\0';
	if (!line || read(fd, 0, 0) < 0)
		return (-1);
	if (*line != NULL)
		*line = NULL;
	if (!(*lst))
		return (-1);
	if (!((*lst)->rest))
	{
		if (!((*lst)->rest = malloc(BUFFER_SIZE + 1)))
			return (-1);
		(*lst)->rest[0] = 0;
	}
	return (1);
}

int		check_line(char **buf, char **rest)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			(*buf)[i] = '\0';
			tmp = *buf + i + 1;
			i = 0;
			while (tmp[i])
			{
				(*rest)[i] = tmp[i];
				i++;
			}
			(*rest)[i] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

int		read_file(int fd, char **str, char **rest)
{
	int		ret;
	int		i;
	char	*buf;
	char	*tmp;

	i = 0;
	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	buf[0] = 0;
	while (i == 0 && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		i = check_line(&buf, rest);
		tmp = *str;
		if (!(*str = ft_strjoin(*str, buf)))
			i = -1;
		safe_free(&tmp);
	}
	safe_free(&buf);
	if (i == -1 || i == 1)
		return (i);
	return (0);
}

int		check_rest(char **rest1, char **rest2, char **str, char **line)
{
	if (*rest1)
	{
		if (!(*rest2 = ft_strjoin(*rest1, NULL)))
			return (-1);
		if (check_line(rest2, rest1) == 1)
		{
			*line = *rest2;
			safe_free(str);
			return (1);
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			*str;
	t_list			*lst;
	int				check_r;
	static t_list	*begin_list;

	if (!(lst = fd_check(&begin_list, fd)))
		return (lst_del(-1, &begin_list, &lst, &str));
	if (check_error(fd, &lst, line, &str) == -1)
		return (lst_del(-1, &begin_list, &lst, &str));
	check_r = check_rest(&(lst->rest), &(lst->rest2), &str, line);
	if (check_r == 1)
		return (1);
	else if (check_r == -1)
		return (lst_del(-1, &begin_list, &lst, &str));
	if ((ret = read_file(fd, &str, &(lst->rest))) == -1)
		return (lst_del(-1, &begin_list, &lst, &str));
	if (!(*line = ft_strjoin(lst->rest2, str)))
		return (lst_del(-1, &begin_list, &lst, &str));
	safe_free(&(lst->rest2));
	safe_free(&str);
	return (ret == 0 ? lst_del(0, &begin_list, &lst, &str) : ret);
}
