/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:20:52 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/13 20:27:05 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

// int	main(int a, char **v)
// {
// 	char *s;
// 	char *s2;

// 	s2[0] = '\0';
// 	if (a > 1)
// 	{
// 		s = ft_strjoin(s2, s2);
// 		printf("%s\n", s);
// 		free(s);
// 	}
// 	return (0);
// }