
#include "get_next_line.h"
#include <stdio.h> // remove later

int		get_next_line(const int fd, char **line)
{
	static char		*str[1024];
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*ptr;

	if (!line || fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0) // access file while there's still content
	{
		if (!str[fd])
			str[fd] = ft_strnew(BUFF_SIZE);
		buf[ret] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
	}
	if (ret == -1)
	{
		*line = ft_strnew(0);
		return (-1); // error
	}
	if ((ptr = ft_strchr(str[fd], '\n')) != NULL)
	{
		*ptr = '\0';
		*line = ft_strdup(str[fd]);
		ptr = ft_strdup(ptr + 1);
		free(str[fd]);
		str[fd] = ptr;
		return (1); // a line has been read
	}
	if (!ft_strlen(str[fd]))
	{
		*line = ft_strnew(0);
		return (0); // nothing left in file
	}
	if (ret < BUFF_SIZE)
	{
		*line = ft_strdup(str[fd]);
		ft_bzero((void *)str[fd], ft_strlen(str[fd]));
		return (1); // a line has been read
	}
	return (1);
}
/*
int		main(void)
{

	return (0);
}
*/

int		main()
{
	int fd;
	char *line;
	int ret;
	int i;
	i = 0;

	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		printf("ret:%d: %s\n", ret, line);
		free(line);
	}
	free(line);
	printf("ret:%d: %s\n", ret, line);
}

