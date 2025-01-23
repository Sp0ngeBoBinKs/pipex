/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:06:19 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/23 21:13:13 by igrousso         ###   ########.fr       */
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

# define STDIN 0
# define STDOUT 1

void	error(int event);

void	ft_free(char **tab);

#endif