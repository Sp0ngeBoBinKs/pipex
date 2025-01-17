/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:36:13 by igrousso          #+#    #+#             */
/*   Updated: 2024/12/02 23:15:28 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(int a, char **v)
// {
// 	char *s;

// 	if (a > 1)
// 	{
// 		s = ft_strdup(v[1]);
// 		printf("%s\n", s);
// 		free(s);
// 	}
// 	return (0);
// }