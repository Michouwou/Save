/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 20:02:36 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/20 18:17:32 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include "libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
#include <stdio.h>
# define BUFF_SIZE 50

typedef struct	s_memory
{
	char			**next_lines;
	int				fd;
	struct s_memory	*next;
}				t_memory;

int				get_next_line(int const fd, char **line);
char			*ft_is_memory(t_memory *memory, int const fd);
int				ft_set_memory(int const fd, t_memory **memory);
int				ft_next_line(char *rest, char **line, int const fd, t_memory *memory);
int				ft_next_read(int const fd, char **rest);

#endif
