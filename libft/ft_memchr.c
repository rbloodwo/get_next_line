/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbloodwo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 00:43:11 by rbloodwo          #+#    #+#             */
/*   Updated: 2018/05/09 00:43:17 by rbloodwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)src;
	while (i < n)
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}
