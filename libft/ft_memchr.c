/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:08:43 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/13 23:41:21 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

// #include <string.h>

// int	main(int a, char **v)
// {
// 	char *s;
// 	char *d;
// 	char *d1;

// 	s = malloc(100);
// 	d = malloc(100);
// 	d1 = malloc(100);
// 	if (!s || !d || !d1)
// 		return (1);
// 	if (a >= 2 && v[1] != NULL)
// 	{
// 		strncpy(s, v[1], 99);
// 		s[99] = '\0';
// 		d = ft_memchr("abab\336abab", '\336', 100);
// 		d1 = memchr("abab\336abab", '\336', 100);
// 		printf("%p\n", d);
// 		printf("%p\n", d1);
// 	}
// 	free(s);
// 	return (0);
// }