
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft/libft.h"

typedef struct		s_file_info
{
	int				ret;
	char			*ptr;
}					t_fileinfo;

int					get_next_line(const int fd, char **line);

#endif
