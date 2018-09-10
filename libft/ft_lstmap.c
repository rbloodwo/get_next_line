/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbloodwo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 21:15:22 by rbloodwo          #+#    #+#             */
/*   Updated: 2018/05/09 21:15:31 by rbloodwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;

	if (lst == NULL || f == NULL)
		return (NULL);
	newlst = f(lst);
	if (newlst != NULL && f != NULL)
		newlst->next = ft_lstmap(lst->next, f);
	return (newlst);
}
