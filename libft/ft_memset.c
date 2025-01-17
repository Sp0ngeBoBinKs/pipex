/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:46:03 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/13 23:42:21 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
		str[i++] = (unsigned char)c;
	return (s);
}

// int	main(int a, char **v)
// {
// 	char	*s;

// 	s = malloc(100);
// 	if (s == NULL)
// 		return (1);
// 	if (a >= 2 && v[1] != NULL)
// 	{
// 		strncpy(s, v[1], 99);
// 		s[99] = '\0';
// 		memset(s, 'a', 2);
// 		printf("%s\n", s);
// 	}
// 	free(s);
// 	return (0);
// }

// int	main(void)
// {
// 	char *s = malloc(10);
// 	if (s == NULL)
// 		return (1);
// 	strcpy(s, "salut");
// 	ft_memset(((void *)0), 'a', 2);
// 	printf("%s\n", s);
// 	free(s);
// 	return (0);
// }