/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:43:51 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/14 01:19:28 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// int	main(int a, char **v)
// {
// 	if (a < 2)
// 		return (1);

// 	t_list *mylist;
// 	t_list *mylist1;
// 	t_list *mylist2;
// 	t_list *mylist3;

// 	mylist = ft_lstnew(v[4]);
// 	mylist1 = ft_lstnew(v[1]);
// 	mylist2 = ft_lstnew(v[2]);
// 	mylist3 = ft_lstnew(v[3]);

// 	ft_lstadd_front(&mylist, mylist1);
// 	ft_lstadd_front(&mylist, mylist2);
// 	ft_lstadd_front(&mylist, mylist3);

// 	mylist = ft_lstlast(mylist);
// 	printf("%s", (char *)mylist->content);
// 	return (0);
// }