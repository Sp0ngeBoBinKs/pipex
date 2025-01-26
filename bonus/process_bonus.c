/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:44:23 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/26 17:45:34 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	process(int *fd_p, char *cmd, char **env)
{
	char	**arg;

	close(fd_p[0]);
	arg = get_arg(cmd, env, fd_p[1], fd_p[2]);
	if (dup2(fd_p[2], STDIN) == -1 || dup2(fd_p[1], STDOUT) == -1)
	{
		ft_free(arg);
		ft_close(fd_p[2], fd_p[1]);
		error(DUP_ERROR, NULL, -1, -1);
	}
	ft_close(fd_p[1], fd_p[2]);
	execve(arg[0], arg, env);
	ft_free(arg);
	exit(127);
}

void	process_out(int *fd_p, char *cmd, char **env)
{
	char	**arg;

	arg = get_arg(cmd, env, fd_p[0], fd_p[2]);
	if (dup2(fd_p[2], STDOUT) == -1 || dup2(fd_p[0], STDIN) == -1)
	{
		ft_free(arg);
		ft_close(fd_p[0], fd_p[2]);
		error(DUP_ERROR, NULL, -1, -1);
	}
	ft_close(fd_p[0], fd_p[2]);
	execve(arg[0], arg, env);
	ft_free(arg);
	exit(127);
}

int	last_process(int *fd_p, int ac, char **av, char **env)
{
	int	status;
	int	id;
	int	j;

	j = 0;
	close(fd_p[1]);
	fd_p[0] = fd_p[2];
	if (ft_strncmp(av[0], "here_doc", 8) == 0)
		fd_p[2] = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		fd_p[2] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd_p[2] == -1)
		error(OPEN_ERROR, NULL, fd_p[0], -1);
	id = fork();
	if (id == -1)
		error(FORK_ERROR, NULL, fd_p[0], fd_p[2]);
	if (!id)
		process_out(fd_p, av[ac - 2], env);
	ft_close(fd_p[2], fd_p[0]);
	while (j++ < (ac - 3))
		waitpid(id, &status, 0);
	waitpid(id, &status, 0);
	return (WEXITSTATUS(status));
}

int	cmd_extra(int ac, char **av, char **env, int *fd_p)
{
	int	id;
	int	i;
	int	count;

	i = 2;
	count = ac - 4;
	while (count--)
	{
		if (pipe(fd_p) == -1)
			error(PIPE_ERROR, NULL, fd_p[2], -1);
		id = fork();
		if (id == -1)
		{
			ft_close(fd_p[0], fd_p[1]);
			error(PIPE_ERROR, NULL, fd_p[2], -1);
		}
		if (!id)
			process(fd_p, av[i], env);
		ft_close(fd_p[1], fd_p[2]);
		fd_p[2] = fd_p[0];
		i++;
	}
	return (last_process(fd_p, ac, av, env));
}

int	pipex_bonus(int ac, char **av, char **env)
{
	int	fd_p[3];

	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			return (write(2, "Wrong number of arguments\n", 26));
		handle_here_doc(av[2], fd_p);
		return (cmd_extra(ac - 1, av + 1, env, fd_p));
	}
	if (ac == 5)
		return (pipex(av, env));
	else
	{
		first_arg(av[1], fd_p, 1);
		fd_p[2] = open(av[1], O_RDONLY);
		if (fd_p[2] == -1)
			error(OPEN_ERROR, NULL, -1, -1);
		return (cmd_extra(ac, av, env, fd_p));
	}
}
