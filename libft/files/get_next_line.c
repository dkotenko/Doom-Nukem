/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 15:10:51 by clala             #+#    #+#             */
/*   Updated: 2020/02/15 21:53:21 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		copy_to_fd_arr(char **fd_arr, char *stack)
{
	char		*tmp;
	size_t		len;

	if (!*fd_arr)
	{
		*fd_arr = ft_strdup(stack);
		return ;
	}
	len = ft_strlen(*fd_arr);
	tmp = *fd_arr;
	*fd_arr = ft_strnew(len + BUFF_SIZE);
	if (*fd_arr)
	{
		ft_memcpy(*fd_arr, (const void *)tmp, len);
		ft_memcpy(*fd_arr + len, (const void *)stack, BUFF_SIZE + 1);
	}
	free(tmp);
}

static void		get_line_from_fd_arr(char **fd_arr, char **line,
		char *n, int len_before_n)
{
	char		*tmp;
	size_t		len_n;

	if (!(*line = ft_strnew(len_before_n + 1)))
		return ;
	ft_memcpy(*line, *fd_arr, len_before_n);
	tmp = *fd_arr;
	len_n = ft_strlen(n);
	*fd_arr = ft_strnew(len_n);
	ft_memcpy(*fd_arr, n + 1, len_n - 1);
	free(tmp);
}

int				get_next_line(int const fd, char **line)
{
	static char	*fd_arr[FD_SETSIZE + 1];
	char		stack[BUFF_SIZE + 1];
	int			r;
	char		*n;

	if (!(r = 0) && ((read(fd, stack, 0) < 0) || fd < 0 || fd > FD_SETSIZE))
		return (-1);
	if (!(*line = NULL) && !fd_arr[fd])
		fd_arr[fd] = ft_strnew(0);
	while (!(ft_strchr(fd_arr[fd], '\n')) && (r = read(fd, stack, BUFF_SIZE)))
	{
		stack[r] = '\0';
		copy_to_fd_arr(&fd_arr[fd], stack);
		ft_strclr(stack);
	}
	if ((n = ft_strchr(fd_arr[fd], '\n')))
		get_line_from_fd_arr(&fd_arr[fd], line, n, n - fd_arr[fd]);
	else
	{
		*line = fd_arr[fd];
		fd_arr[fd] = NULL;
	}
	if (!r && !fd_arr[fd] && *line[0] == '\0')
		ft_strdel(line);
	return (*line ? 1 : 0);
}
