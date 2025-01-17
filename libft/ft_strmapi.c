/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:14:53 by igrousso          #+#    #+#             */
/*   Updated: 2024/12/02 23:15:48 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	test(unsigned int i, char c)
// {
// 	char	d;

// 	d = c + i;
// 	return (d);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!s2)
		return (NULL);
	while (s[i] != '\0')
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

// int	main(int a, char **v)
// {
// 	char *s;
// 	if (a > 1)
// 	{
// 		s = ft_strmapi(v[1], test);
// 		printf("%s\n", s);
// 		free(s);
// 	}
// 	return (0);
// }