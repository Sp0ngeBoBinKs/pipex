/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:41:50 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/12 22:57:20 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (i < len && s1[i] != '\0')
	{
		j = 0;
		while (i + j < len && s1[i + j] == s2[j])
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(int a, char **v)
// {
// 	char *s1 = malloc(50);

// 	bzero(s1, 50);
// 	if (a > 1)
// 	{
// 		s1 = ft_strnstr(v[1], v[2], 11);
// 		printf("%s\n", s1);
// 	}
// 	return (0);
// }