/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:12:14 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/07 23:38:21 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size == 0 || dstlen >= size)
		return (srclen + size);
	while (src[i] != '\0' && size - dstlen - 1 > i)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (srclen + dstlen);
}

// int	main(int a, char **v)
// {
// 	if (a == 4)
// 	{
// 		printf("%zu\n%s\n", ft_strlcat(v[1], v[2], atoi(v[3])), v[1]);
// 	}
// 	return (0);
// }