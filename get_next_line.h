/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:47:17 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/03 22:47:25 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 72

# define FDS_SIZE 1999999
# define EOL_FIND ft_strchr(fds[fd], '\n')

# include "libft/libft.h"

int		get_next_line(int fd, char **line);

#endif
