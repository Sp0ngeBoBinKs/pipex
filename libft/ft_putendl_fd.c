/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putend1_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:23:00 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/12 15:51:17 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// int	main(int a, char **v)
// {
// 	if (a > 1)
// 	{
// 		ft_putend1_fd(v[1], ft_atoi(v[2]));
// 	}
// 	return (0);
// }