/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbloodwo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 00:54:38 by rbloodwo          #+#    #+#             */
/*   Updated: 2018/05/09 00:54:41 by rbloodwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t i;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return (str);
	while (*str && len > 0)
	{
		if (*str == to_find[i])
			i++;
		else
			i = 0;
		if (to_find[i] == '\0')
			return (str - i + 1);
		str++;
		len--;
	}
	return (NULL);
}
