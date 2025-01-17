/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:23:29 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/13 23:49:27 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*str1;
	const char	*str2;
	size_t		i;

	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	int		a;
// 	int		c;
// 	char	s2[] = {0, 0, 127, 0};
// 	char	s3[] = {0, 0, 42, 0};

// 	a = ft_memcmp(s2, s3, 4);
// 	c = memcmp(s2, s3, 4);
// 	printf("%d\n", a);
// 	printf("\n");
// 	printf("%d\n", c);
// 	return (0);
// }
