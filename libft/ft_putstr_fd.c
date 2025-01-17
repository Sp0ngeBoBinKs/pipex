/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:18:17 by igrousso          #+#    #+#             */
/*   Updated: 2024/11/10 22:22:07 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// int	main(int a, char **v)
// {
// 	if (a > 1)
// 	{
// 		ft_putstr_fd(v[1], ft_atoi(v[2]));
// 	}
// 	return (0);
// }