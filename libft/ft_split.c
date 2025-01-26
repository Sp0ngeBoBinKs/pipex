/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:19:07 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/26 17:42:42 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char *c)
{
	int	i;
	int	j;
	int	ct;

	i = 0;
	j = 0;
	ct = 0;
	while (s[i] != '\0')
	{
		if (!ft_strchr((char *)c, s[i]) && j == 0)
		{
			j = 1;
			ct++;
		}
		else if (ft_strchr((char *)c, s[i]))
			j = 0;
		i++;
	}
	return (ct);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc((finish - start + 1), sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
}

static char	**ft_split2(char const *s, char *c, char **tab)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= (int)ft_strlen(s))
	{
		if (!ft_strchr((char *)c, s[i]) && index < 0)
			index = i;
		else if ((ft_strchr((char *)c, s[i]) || i == (int)ft_strlen(s))
			&& index >= 0)
		{
			tab[j] = word_dup(s, index, i);
			if (!tab[j++])
				return (ft_free(tab), NULL);
			index = -1;
		}
		i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char *c)
{
	char	**tab;

	tab = ft_calloc((count_word(s, c) + 1), sizeof(char *));
	if (!s || !tab || !c)
		return (NULL);
	tab = ft_split2(s, c, tab);
	return (tab);
}

// int	main(int a, char **v)
// {
// 	int		i;
// 	char	**tab;

// 	if (a == 3)
// 	{
// 		i = 0;
// 		tab = ft_split(v[1], *v[2]);
// 		while (tab[i])
// 		{
// 			printf("%s\n", tab[i]);
// 			i++;
// 		}
// 		free(tab);
// 	}
// 	return (0);
// }
