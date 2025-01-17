/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:42:23 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/14 00:29:10 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	test(unsigned int i, char *s)
// {
// 	while (s[i] != '\0')
// 	{
// 		if (i % 2 == 0)
// 			s[i] = 'c';
// 		else
// 			s[i] = 'a';
// 		i++;
// 	}
// 	if (ft_strlen(s) % 2 == 1)
// 	{
// 		s[ft_strlen(s) - 1] = '\0';
// 	}
// }

// void	iter(unsigned int i, char *s)
// {
// 	*s += i;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// int	main(int a, char **v)
// {
// 	char s[] = "0000000000";

// 	if (a > 1)
// 	{
// 		(void)v;
// 		// s = v[1];
// 		ft_striteri(s, test);
// 		printf("%s\n", s);
// 	}
// 	return (0);
// }