/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbloodwo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:06:47 by rbloodwo          #+#    #+#             */
/*   Updated: 2018/05/09 20:06:59 by rbloodwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*temp;

	temp = *alst;
	if (del == NULL || alst == NULL)
		return ;
	while (temp != NULL)
	{
		next = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = next;
	}
	*alst = NULL;
}
