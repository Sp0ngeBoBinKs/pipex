/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:21:33 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/14 16:45:17 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	**first;

	if (!lst)
		return (NULL);
	l = NULL;
	l = ft_lstnew(f(lst->content));
	if (!l)
		return (NULL);
	first = &lst;
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&l, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	ft_lstclear(first, del);
	return (l);
}
