/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:46:58 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/03 22:47:10 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_line_tail_handle(char **line, int fd, char *fds[fd])
{
	char		*n_place;
	size_t		tl_start;
	size_t		len;
	size_t		line_size;
	char		*saver_tmp;

	n_place = EOL_FIND;
	len = ft_strlen(fds[fd]);
	if (n_place)
	{
		line_size = n_place - fds[fd];
		*line = ft_strsub(fds[fd], 0, line_size);
		saver_tmp = fds[fd];
		tl_start = n_place - fds[fd] + 1;
		fds[fd] = ft_strsub(fds[fd], (int)tl_start, len);
		free(saver_tmp);
	}
	else
	{
		*line = ft_strndup(fds[fd], len);
		ft_memdel((void *)&fds[fd]);
	}
}

static int		ft_read_search(int fd, char *fds[fd])
{
	char	buffer[BUFF_SIZE + 1];
	char	*saver_tmp;
	ssize_t rd_cnt;

	while (!EOL_FIND && (rd_cnt = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		saver_tmp = fds[fd];
		buffer[rd_cnt] = '\0';
		fds[fd] = ft_strjoin(fds[fd], buffer);
		free(saver_tmp);
	}
	if (rd_cnt < 0)
		return (-1);
	else
		return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char *fds[FDS_SIZE];

	if (fd > FDS_SIZE || fd < 0 || line == NULL)
		return (-1);
	if (!fds[fd] && !(fds[fd] = ft_strnew(1)))
		return (-1);
	if (ft_read_search(fd, fds) == -1)
		return (-1);
	ft_line_tail_handle(line, fd, fds);
	if (!fds[fd] && ft_strlen(*line) == 0)
		return (0);
	return (1);
}
