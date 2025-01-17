/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:38:34 by igrousso          #+#    #+#             */
/*   Updated: 2024/12/02 23:16:15 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_charset(char c, char const *set)
{
	int	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_first(char const *s1, char const *set)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	if (check_charset(s1[0], set) == 1)
	{
		i++;
		ct++;
		while (check_charset(s1[i], set) == 1)
		{
			ct++;
			i++;
		}
	}
	return (ct);
}

int	count_end(char const *s1, char const *set)
{
	int	len;
	int	ct;

	len = ft_strlen(s1);
	ct = 0;
	if (check_charset(s1[len - 1], set) == 1 && s1[len] == '\0')
	{
		ct++;
		len -= 2;
		while (check_charset(s1[len], set) == 1)
		{
			ct++;
			len--;
		}
	}
	return (ct);
}

int	count_for_malloc(char const *s1, char const *set)
{
	int	ct;

	ct = 0;
	ct = count_first(s1, set);
	if (ct != (int)ft_strlen(s1))
		ct += count_end(s1, set);
	return (ct);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int		j;
	char	*s2;
	int		l;
	size_t	k;

	s2 = ft_calloc(((ft_strlen(s1) - count_for_malloc(s1, set)) + 1),
			sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	k = ft_strlen(s1);
	l = count_end(s1, set);
	if (check_charset(s1[0], set) == 1)
	{
		i++;
		while (check_charset(s1[i], set) == 1)
			i++;
	}
	while (i < (k - l))
		s2[j++] = s1[i++];
	s2[j] = '\0';
	return (s2);
}

// int	main(int a, char **v)
// {
// 	char *s1;
// 	char *set;
// 	char *s;

// 	if (a > 1)
// 	{
// 		s1 = v[1];
// 		set = v[2];
// 		s = ft_strtrim(s1, set);
// 		printf("%s\n", s);
// 		free(s);
// 	}

// 	return (0);
// }