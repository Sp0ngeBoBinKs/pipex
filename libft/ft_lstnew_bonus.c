/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:44:46 by igrousso          #+#    #+#             */
/*   Updated: 2024/12/02 23:14:11 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// int	main(int a, char **v)
// {
// 	t_list *myList;

// 	int j = atoi(v[1]);

// 	int *i = &j;

// 	myList = ft_lstnew(i);
// 	printf("%d", *(int *)(myList->content));

// 	return (0);
// }