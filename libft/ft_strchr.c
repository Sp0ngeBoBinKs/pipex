/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:13:21 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/15 18:37:54 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

// #include <string.h>

// int	main(int a, char **v)
// {
// 	char *s;

// 	s = malloc(100);
// 	if (s == NULL)
// 		return (1);
// 	strncpy(s, v[1], 99);
// 	s[99] = '\0';
// 	printf("%p\n", ft_strchr("teste", '\0'));
// 	printf("%p\n", strchr("teste", '\0'));
// 	free(s);
// 	return (0);
// }