
#include "get_next_line.h"
#include <stdio.h> // remove later

char	*access_file(int fd, t_fileinfo *finfo) // this works
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

char	*set_line(char *ptr, char **line, char *str)
{
	if ((ptr = ft_strchr(str, '\n')) != NULL)
	{
		*ptr = '\0';
		*line = ft_strdup(str);
		ptr = ft_strdup(ptr + 1);
	}
	return (ptr);
}

int		check_len(char **line, char *str)
{
	if (!ft_strlen(str))
	{
		*line = ft_strnew(0);
		return (0);
	}
	return (1);
}

int		check_ret(char **line, char *str, t_fileinfo *finfo) // maybe change function name
{
	if (finfo->ret < BUFF_SIZE)
	{
		*line = ft_strdup(str);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str[1024];
	t_fileinfo		*finfo;
//	char			*ptr; // can possibly stick in finfo struct to save space

//	ptr = NULL;
	finfo = malloc(sizeof(t_fileinfo));
	if (!line || fd < 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(BUFF_SIZE);
	str[fd] = ft_strjoin(str[fd], access_file(fd, finfo));
	if (finfo->ret == -1)
		return (-1);
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	if ((finfo->ptr = set_line(finfo->ptr, line, str[fd])) != NULL)
	{
		free(str[fd]);
		str[fd] = finfo->ptr;
		return (1);
	}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	if (check_len(line, str[fd]) == 0)
		return (0);
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	if (check_ret(line, str[fd], finfo) == 1)
	{
		ft_bzero((void *)str[fd], ft_strlen(str[fd]));
		return (1);
	}
	return (1);
}


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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

/*
void	test(char *str)
{
	ft_putstr(str);
}

int		get_next_line(int fd, char **line)
{
	static char *str[1024];
	fd = 0;
	line = NULL;

	str[0] = ft_strnew(BUFF_SIZE);
	str[0] = "test\n";
	test(str[0]);
	return (1);
}

int		main(void)
{
	char **line = NULL;
	int i = get_next_line(0, line);
	i = 0;
	return (0);
}
*/
