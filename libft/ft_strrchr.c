/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:37:28 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/18 21:33:24 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)&s[len]);
	while ((int)len >= 0)
	{
		if (s[len] == (unsigned char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}

// #include <string.h>

// int	main(int a, char **v)
// {
// 	char *s;

// 	s = malloc(100);
// 	if (s == NULL)
// 		return (1);
// 	if (a >= 2 && v[1] != NULL)
// 	{
// 		strncpy(s, v[1], 99);
// 		s[99] = '\0';
// 		printf("%s\n", ft_strrchr(s, '\0'));
// 		printf("%s\n", strrchr(s, '\0'));
// 	}
// 	free(s);
// 	return (0);
// }