/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:26:35 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/14 15:41:50 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

// int	main(int a, char **v)
// {
// 	char	*s;
// 	char	*s2;

// 	s = malloc(100);
// 	s2 = malloc(100);
// 	if (s == NULL || s2 == NULL)
// 		return (1);
// 	if (a >= 2 && v[1] != NULL && v[2] != NULL)
// 	{
// 		strncpy(s, v[1], 99);
// 		strncpy(s2, v[2], 99);
// 		s[99] = '\0';
// 		s2[99] = '\0';
// 		ft_memmove(s, s2, atoi(v[3]));
// 		printf("%s\n", s);
// 	}
// 	free(s);
// 	free(s2);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*s;
// 	char	*s2;

// 	s = malloc(10);
// 	s2 = malloc(10);
// 	if (s == NULL || s2 == NULL)
// 		return (1);
// 	strcpy(s, "groscaca");
// 	strcpy(s2, "bien");
// 	ft_memmove(s, s2, 4);
// 	printf("%s\n", s);
// 	free(s);
// 	free(s2);
// 	return (0);
// }
