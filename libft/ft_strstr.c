/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbloodwo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 00:55:28 by rbloodwo          #+#    #+#             */
/*   Updated: 2018/05/09 00:55:32 by rbloodwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int x;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return (str);
	while (str[i] != '\0')
	{
		x = 0;
		while (to_find[x] == str[i + x])
		{
			if (to_find[x + 1] == '\0')
			{
				return (str + i);
			}
			x++;
		}
		i++;
	}
	return (NULL);
}
