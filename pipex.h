/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:06:19 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/24 19:27:54 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define PIPE_ERROR 1
# define FORK_ERROR 2
# define EXECUTABLE_ERROR 3
# define OPEN_ERROR 4
# define DUP_ERROR 5
# define SPLIT_ERROR 6
# define EXEC_ERROR 7
# define ABSOLUT_PATH_ERROR 8

# define STDIN 0
# define STDOUT 1

void	error(int event, char *str, int fd1, int fd2);
void	write_error(char *str1, char *str2);
void	errno_exit(void);
void	ft_free(char **tab);
void	ft_close(int fd1, int fd2);

#endif