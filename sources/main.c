/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:57:25 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/25 15:40:16 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_arg(char *str, int *fd_p)
{
	if (access(str, F_OK) == -1)
	{
		close(fd_p[1]);
		write_error("no such file or directory: ", str);
		errno_exit();
	}
	if (access(str, R_OK) == -1)
	{
		close(fd_p[1]);
		write_error("permission denied: ", str);
		exit(0);
	}
}

void	process1(int *fd_p, char *file, char *command, char **env)
{
	int		fd;
	char	**arg;

	close(fd_p[0]);
	first_arg(file, fd_p);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error(OPEN_ERROR, NULL, fd_p[1], -1);
	arg = get_arg(command, env, fd, fd_p[1]);
	if (dup2(fd, STDIN) == -1 || dup2(fd_p[1], STDOUT) == -1)
	{
		ft_free(arg);
		ft_close(fd, fd_p[1]);
		error(DUP_ERROR, NULL, -1, -1);
	}
	close(fd);
	close(fd_p[1]);
	if (execve(arg[0], arg, env) == -1)
	{
		ft_free(arg);
		error(EXEC_ERROR, NULL, -1, -1);
	}
}

void	process2(int *fd_p, char *command, char *file, char **env)
{
	int		fd;
	char	**arg;

	close(fd_p[1]);
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd == -1)
		error(OPEN_ERROR, NULL, fd_p[0], -1);
	arg = get_arg(command, env, fd, fd_p[0]);
	if (dup2(fd, STDOUT) == -1 || dup2(fd_p[0], STDIN) == -1)
	{
		ft_free(arg);
		ft_close(fd, fd_p[0]);
		error(DUP_ERROR, NULL, -1, -1);
	}
	close(fd);
	close(fd_p[0]);
	if (execve(arg[0], arg, env) == -1)
	{
		ft_free(arg);
		error(EXEC_ERROR, NULL, -1, -1);
	}
}

int	pipex(char **av, char **env)
{
	int	fd_p[2];
	int	id1;
	int	id2;

	if (pipe(fd_p) == -1)
		error(PIPE_ERROR, NULL, -1, -1);
	id1 = fork();
	if (id1 == -1)
		error(FORK_ERROR, NULL, fd_p[0], fd_p[1]);
	if (id1 == 0)
		process1(fd_p, av[1], av[2], env);
	id2 = fork();
	if (id2 == -1)
		error(FORK_ERROR, NULL, fd_p[0], fd_p[1]);
	if (id2 == 0)
		process2(fd_p, av[3], av[4], env);
	ft_close(fd_p[0], fd_p[1]);
	return (ft_wait(id1, id2));
}

int	main(int ac, char **av, char **env)
{
	int	i;

	if (ac != 5)
		return (write(2, "Error\nWrong number of arguments\n", 32));
	i = pipex(av, env);
	return (i);
}
