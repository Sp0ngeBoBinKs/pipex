/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:38:13 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/14 15:47:08 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t size)
{
	void	*s;

	if (size > 0 && (size_t)-1 / size < nelem)
		return (NULL);
	s = malloc(nelem * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, nelem * size);
	return (s);
}

// int	main(void)
// {
// 	int i;
// 	char *s;

// 	i = 0;
// 	s = ft_calloc(10, 1);
// 	while (i < 10 && s[i] == '\0')
// 	{
// 		printf("ok%d\n", i + 1);
// 		i++;
// 	}
// 	return (0);
// }