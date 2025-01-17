/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:23:45 by igrousso          #+#    #+#             */
/*   Updated: 2024/12/04 23:44:30 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
		str[i++] = 0;
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
// 		ft_bzero(s, 2);
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
// 	bzero(s, 2);
// 	printf("%s\n", s);
// 	free(s);
// 	return (0);
// }