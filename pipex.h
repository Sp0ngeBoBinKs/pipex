/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:06:19 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/26 17:52:12 by igrousso         ###   ########.fr       */
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
# define GNL_ERROR 9

# define STDIN 0
# define STDOUT 1

/* get command */

char	**get_arg(char *command, char **env, int fd1, int fd2);
int		command_arg(char **av, int fd1, int fd2);
char	*find_executable(char **env, char *av);
char	**get_path_from_env(char **env);
char	*find_path(char **env);

/* error */

void	error(int event, char *str, int fd1, int fd2);
void	write_error(char *str1, char *str2);
void	errno_exit(void);
void	error2(char **arg, char **env, int fd1, int fd2);
void	handle_error(char *av, int fd1, int fd2);

/* utils */

void	ft_free(char **tab);
void	ft_close(int fd1, int fd2);
int		ft_wait(int id1, int id2);

/* process */

void	first_arg(char *str, int *fd_p, int bonus);
void	process1(int *fd_p, char *file, char *command, char **env);
void	process2(int *fd_p, char *command, char *file, char **env);
int		pipex(char **av, char **env);

/* bonus */

void	handle_here_doc(char *lim, int *fd_p);
int		pipex_bonus(int ac, char **av, char **env);
int		cmd_extra(int ac, char **av, char **env, int *fd_p);
int		last_process(int *fd_p, int ac, char **av, char **env);
void	process_out(int *fd_p, char *cmd, char **env);
void	process(int *fd_p, char *cmd, char **env);

#endif