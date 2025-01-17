/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:08:52 by igrousso          #+#    #+#             */
/*   Updated: 2024/12/14 17:05:41 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "../libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

char	*get_next_line(int fd) __attribute__((destructor));
char	*get_line1(int fd, char *temp, int byte);
char	*get_line_2(char *temp);
char	*ft_join(char *temp, char *buff);
char	*ft_strchrgnl(const char *s, int c);

#endif