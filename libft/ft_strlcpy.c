/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:54:43 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/14 18:50:37 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

// #include <bsd/string.h>

// int	main(void)
// {
// 	char dest[50] = "rrrrrr000000000";

// 	ft_strlcpy(dest, "lorem ipsum", 3);
// 	printf("%s /", dest);

// 	char dest2[50] = "rrrrrr000000000";

// 	strlcpy(dest2, "lorem ipsum", 3);
// 	printf("%s", dest2);
// 	printf("\n");

// 	char dest3[50] = "rrrrrr000000000";

// 	ft_strlcpy(dest3, "lorem ipsum dolor sit amet", 15);
// 	printf("%s /", dest3);

// 	char dest4[50] = "rrrrrr000000000";

// 	strlcpy(dest4, "lorem ipsum dolor sit amet", 15);
// 	printf("%s", dest4);
// }