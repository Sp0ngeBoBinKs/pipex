/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:08:19 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/25 23:52:08 by igrousso         ###   ########.fr       */
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

void	handle_here_doc(char *lim, int *fd_p)
{
	char	*line;
	int		pipe_fd[2];
    char *tmp;

	if (pipe(pipe_fd) == -1)
		error(PIPE_ERROR, NULL, -1, -1);
	while (1)
	{
		write(1, "here_doc> ", 10);
		line = get_next_line(STDIN);
		if (!line)
			error(GNL_ERROR, NULL, pipe_fd[0], pipe_fd[1]);
        if (ft_strncmp(line, lim, ft_strlen(lim) + 1) == 0)
        	break ;
        tmp = ft_join(line, "\n");
        write(pipe_fd[1], tmp, ft_strlen(tmp));
		free(tmp);
	}
	free(line);
	close(pipe_fd[1]);
	fd_p[2] = pipe_fd[0];
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

void handle_error(char *arg, int fd1, int fd2)
{
    int i;
   
    i = 0;
    while (arg[i])
    {
        if (arg[i] == '\'' && arg[i + 1] == '\'')
        {
            ft_close(fd1, fd2);
            write_error("command not found: ", arg);
            exit(127);
        }
        i++;
    }
    return ;
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		return (write(2, "Wrong number of arguments\n", 26));
	return (pipex_bonus(ac, av, env));
}