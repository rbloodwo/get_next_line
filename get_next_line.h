/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbloodwo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 21:21:08 by rbloodwo          #+#    #+#             */
/*   Updated: 2018/09/09 21:21:11 by rbloodwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 12
# define MAX_FD 1024

# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_file_info
{
	int				bytes;
	char			*ptr;
	char			*file;
}					t_fileinfo;

int					get_next_line(const int fd, char **line);

#endif
