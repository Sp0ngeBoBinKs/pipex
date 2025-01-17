/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:27:27 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/17 20:08:53 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	n;
	int	i;
	int	moins;

	i = 0;
	n = 0;
	moins = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == 43)
		i++;
	else if (s[i] == 45)
	{
		moins = -moins;
		i++;
	}
	while (ft_isdigit(s[i]) != 0 && s[i] != '\0')
		n = n * 10 + (s[i++] - 48);
	return (n * moins);
}

// int	main(int a, char **v)
// {
// 	if (a < 2)
// 		return (1);
// 	(void)v;
// 	printf("%d\n", ft_atoi("\n\n\n  -46\b9 \n5d6"));
// 	printf("%d", atoi("\n\n\n  -46\b9 \n5d6"));
// 	return (0);
// }