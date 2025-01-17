/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:30:25 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/04 19:45:41 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
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

// 	printf("%d", ft_lstsize(mylist));
// 	return (0);
// }