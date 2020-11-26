/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:00:14 by hor4tio           #+#    #+#             */
/*   Updated: 2020/10/30 11:53:13 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# define BUFFER_SIZE 1024

typedef struct		s_list
{
	int				fd;
	char			*rest;
	char			*rest2;
	struct s_list	*next;
}					t_list;

t_list				*lstnew(int fd);
t_list				*fd_check(t_list **list, int fd);
int					safe_free(char **tab);
int					get_next_line(int fd, char **line);
char				*ft_strjoin(char *s1, char *s2);
int					lst_del(int return_value, t_list **list,
					t_list **to_delete, char **str);

#endif
