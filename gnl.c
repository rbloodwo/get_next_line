
#include "get_next_line.h"
#include <stdio.h> // remove later

char	*access_file(int fd, t_fileinfo *finfo)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	temp = ft_strnew(BUFF_SIZE);
	while ((finfo->ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[finfo->ret] = '\0';
		temp = ft_strjoin(temp, buf);
	}
	if (finfo->ret == -1)
		temp = ft_strnew(0);
	return (temp);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str[1024];
	t_fileinfo		*finfo;
	char			*ptr;

	finfo = malloc(sizeof(t_fileinfo));
	if (!line || fd < 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(BUFF_SIZE);
	str[fd] = ft_strjoin(str[fd], access_file(fd, finfo));
	if (finfo->ret == -1)
		return (-1);
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
	if (finfo->ret < BUFF_SIZE)
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

