/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:09:53 by igrousso          #+#    #+#             */
/*   Updated: 2024/12/14 15:24:32 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

// int	main(int a, char **v)
// {
// 	if (a < 2)
// 		return (1);

// 	t_list *mylist;
// 	t_list *mylist1;
// 	t_list *mylist2;
// 	t_list *mylist3;

// 	mylist = malloc(sizeof(t_list));
// 	mylist = ft_lstnew(v[4]);
// 	mylist1 = ft_lstnew(v[1]);
// 	mylist2 = ft_lstnew(v[2]);
// 	mylist3 = ft_lstnew(v[3]);

// 	ft_lstadd_front(&mylist, mylist1);
// 	ft_lstadd_front(&mylist, mylist2);

// 	ft_lstadd_back(&mylist, mylist3);

// 	while (mylist)
// 	{
// 		printf("%s", (char *)mylist->content);
// 		mylist = mylist->next;
// 	}

// 	return (0);
// }