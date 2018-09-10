/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbloodwo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 21:20:50 by rbloodwo          #+#    #+#             */
/*   Updated: 2018/09/09 21:20:53 by rbloodwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	unsigned int	len;
	char			*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, (char *)s1);
	ft_strcat(str, (char *)s2);
	free(s1);
	return (str);
}

char	*access_file(int fd, t_fileinfo *finfo)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	temp = ft_strnew(BUFF_SIZE);
	while ((finfo->bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[finfo->bytes] = '\0';
		temp = ft_strjoin_gnl(temp, buf);
	}
	if (finfo->bytes == -1)
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

int		checks(char **line, char *str, t_fileinfo *finfo)
{
	int ret;

	ret = -1;
	if (finfo->bytes < BUFF_SIZE)
	{
		*line = ft_strdup(str);
		ret = 1;
	}
	if (!ft_strlen(str))
	{
		*line = ft_strnew(0);
		ret = 0;
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str[1024];
	t_fileinfo		finfo;

	if (!line || fd < 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(BUFF_SIZE);
	finfo.file = access_file(fd, &finfo);
	str[fd] = ft_strjoin_gnl(str[fd], finfo.file);
	free(finfo.file);
	if (finfo.bytes == -1)
		return (-1);
	if ((finfo.ptr = set_line(finfo.ptr, line, str[fd])) != NULL)
	{
		free(str[fd]);
		str[fd] = finfo.ptr;
		return (1);
	}
	if (checks(line, str[fd], &finfo) == 0)
		return (0);
	else
	{
		ft_bzero((void *)str[fd], ft_strlen(str[fd]));
		return (1);
	}
}
