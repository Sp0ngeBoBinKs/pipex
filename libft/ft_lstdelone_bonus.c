/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:55:18 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/14 01:36:23 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	del(void *content)
// {
// 	if (content)
// 		content = NULL;
// }

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

// void	affichelist(t_list *l)
// {
// 	while (l != NULL)
// 	{
// 		printf("%s", (char *)l->content);
// 		l = l->next;
// 	}
// }

// int	main(int a, char **v)
// {
// 	if (a < 2)
// 		return (1);
// 	t_list *mylist;
// 	t_list *l;
// 	mylist = malloc(sizeof(t_list));

// 	l = mylist;
// 	l->content = strdup("c");
// 	l->next = malloc(sizeof(t_list));
// 	l = l->next;

// 	l->content = strdup("a");
// 	l->next = malloc(sizeof(t_list));
// 	l = l->next;

// 	l->content = strdup("c");
// 	l->next = malloc(sizeof(t_list));
// 	l = l->next;

// 	l->content = strdup("a");
// 	l->next = NULL;

// 	affichelist(mylist);

// 	// t_list	*t = mylist->next;
// 	// mylist->next = t->next;
// 	ft_lstdelone(mylist, del);
// 	printf("\n");
// 	affichelist(mylist);
// 	return (0);
// }