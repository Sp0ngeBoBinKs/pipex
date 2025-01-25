/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:08:39 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/25 22:57:38 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchrgnl(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i + 1]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i + 1]);
	return (NULL);
}

char	*ft_join(char *temp, char *buff)
{
	char	*temp2;

	temp2 = ft_strjoin(temp, buff);
	free(temp);
	return (temp2);
}

char	*get_line_2(char *temp)
{
	int		i;
	char	*str;
	char	*temp2;

	i = 0;
	temp2 = ft_strchrgnl(temp, '\n');
	if (!temp2)
	{
		return (temp);
	}
	else
	{
		str = ft_calloc(temp2 - temp + 2, sizeof(char));
		while (temp[i] != '\0' && temp[i] != '\n')
		{
			str[i] = temp[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
}

char	*get_line1(int fd, char *temp, int byte)
{
	char	*buff;

	if (!temp)
		temp = ft_calloc(1, sizeof(char));
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff || !temp)
		return (NULL);
	while (byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte <= 0)
			break ;
		buff[byte] = '\0';
		temp = ft_join(temp, buff);
		if (ft_strchrgnl(temp, '\n'))
			break ;
	}
	free(buff);
	if (byte <= 0 && temp[0] == '\0')
	{
		free(temp);
		return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*str;
	char		*temp2;
	int			byte;

	byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (free(temp), temp = NULL, NULL);
	temp = get_line1(fd, temp, byte);
	if (!temp)
		return (free(temp), NULL);
	str = get_line_2(temp);
	if (!str)
		return (NULL);
	if (!(ft_strchr(temp, '\n')))
		temp = NULL;
	else
	{
		temp2 = ft_strdup(ft_strchrgnl(temp, '\n'));
		free(temp);
		temp = ft_strdup(temp2);
		free(temp2);
	}
	return (str);
}

// int	main(int ac, char **av)
// {
// 	char *line;
// 	char *name;
// 	int fd;
// 	int i;

// 	(void)ac;
// 	name = av[1];
// 	fd = open(name, O_RDONLY);
// 	i = 20;
// 	while (--i >= 0)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }