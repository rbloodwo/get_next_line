/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbloodwo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 00:54:55 by rbloodwo          #+#    #+#             */
/*   Updated: 2018/05/09 00:55:01 by rbloodwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;

	str = (char *)s;
	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	while (*str != (char)c && len > 0)
	{
		if (*str == (char)c)
			return (str);
		str--;
		len--;
	}
	if (*str == (char)c)
		return (str);
	return (NULL);
}
