/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:04:43 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/14 01:26:26 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
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
// 	ft_lstadd_front(&mylist, mylist3);

// 	while (mylist)
// 	{
// 		printf("%s", (char *)mylist->content);
// 		mylist = mylist->next;
// 	}
// 	return (0);
// }