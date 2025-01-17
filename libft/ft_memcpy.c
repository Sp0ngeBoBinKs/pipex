/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:14:34 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/14 01:13:01 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	str = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (i < n)
	{
		str[i] = str2[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char *s = malloc(10000);
// 	char *s2 = malloc(1000);

// 	// strcpy(s, "groscaca");
// 	// strcpy(s2, "bien");
// 	// s2 = NULL;
// 	// s = NULL;
// 	// ft_memcpy(NULL, NULL, 4);
// 	memcpy(NULL, NULL, 4);
// 	// printf("%s\n", s);
// 	// free(s);
// 	// free(s2);
// 	return (0);
// }