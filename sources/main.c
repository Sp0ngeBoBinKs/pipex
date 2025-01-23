/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:57:25 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/23 21:18:01 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_arg(char *str)
{
	if (access(str, F_OK) == -1)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
	if (access(str, R_OK) == -1)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
}

int	command_arg(char *av)
{
	if (!av)
	{
		write(2, "Command not found\n", 18);
		exit(EXIT_FAILURE);
	}
	if (access(av, X_OK) == 0)
		return (1);
	return (0);
}

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	**get_path_from_env(char **env)
{
	char	**tab;
	char	*str;

	str = find_path(env);
	if (!str)
		return (NULL);
	tab = ft_split(str, ':');
	return (tab);
}

char	*find_executable(char **env, char *av)
{
	int		i;
	char	**tab;
	char	*str;
	char	*str2;

	tab = get_path_from_env(env);
	i = 0;
	while (tab[i])
	{
		str = ft_strjoin(tab[i++], "/");
		str2 = ft_strjoin(str, av);
		free(str);
		if (access(str2, X_OK) == 0)
		{
			ft_free(tab);
			return (str2);
		}
		free(str2);
	}
	ft_free(tab);
	return (NULL);
}

void	error(int event)
{
	if (event == PIPE_ERROR)
		perror("Error creating pipe");
	if (event == FORK_ERROR)
		perror("Error during fork");
	if (event == EXECUTABLE_ERROR)
		perror("Command not found");
	if (event == OPEN_ERROR)
		perror("Error opening file");
	if (event == DUP_ERROR)
		perror("Error duplicating the file descriptor");
	if (event == SPLIT_ERROR)
		perror("Error during split");
	if (event == EXEC_ERROR)
		perror("Error during execve");
	exit(EXIT_FAILURE);
}

char	**get_arg(char *command, char **env)
{
	char	**arg;
	char	*executable;

	arg = ft_split(command, ' ');
	if (!arg)
		error(SPLIT_ERROR);
	if (command_arg(arg[0]) == 0)
	{
		executable = find_executable(env, arg[0]);
		if (!executable)
		{
			ft_free(arg);
			error(EXECUTABLE_ERROR);
		}
		free(arg[0]);
		arg[0] = ft_strdup(executable);
		free(executable);
	}
	return (arg);
}

void	ft_close(int fd1, int fd2)
{
	if (fd1)
		close(fd1);
	if (fd2)
		close(fd2);
}

void	process1(int *fd_p, char *file, char *command, char **env)
{
	int		fd;
	char	**arg;

	close(fd_p[0]);
	first_arg(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error(OPEN_ERROR);
	arg = get_arg(command, env);
	if (dup2(fd, STDIN) == -1 || dup2(fd_p[1], STDOUT) == -1)
	{
		ft_free(arg);
		ft_close(fd, fd_p[1]);
		error(DUP_ERROR);
	}
	close(fd);
	close(fd_p[1]);
	if (execve(arg[0], arg, env) == -1)
	{
		ft_free(arg);
		error(EXEC_ERROR);
	}
}

void	process2(int *fd_p, char *command, char *file, char **env)
{
	int		fd;
	char	**arg;

	close(fd_p[1]);
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd == -1)
		error(OPEN_ERROR);
	arg = get_arg(command, env);
	if (dup2(fd, STDOUT) == -1 || dup2(fd_p[0], STDIN) == -1)
	{
		ft_free(arg);
		ft_close(fd, fd_p[0]);
		error(DUP_ERROR);
	}
	close(fd);
	close(fd_p[0]);
	if (execve(arg[0], arg, env) == -1)
	{
		ft_free(arg);
		error(EXEC_ERROR);
	}
}

void	pipex(char **av, char **env)
{
	int	fd_p[2];
	int	id1;
	int	id2;
	// int	status1;
	
	if (pipe(fd_p) == -1)
		error(PIPE_ERROR);
	id1 = fork();
	if (id1 == -1)
		error(FORK_ERROR);
	if (id1 == 0)
		process1(fd_p, av[1], av[2], env);
	id2 = fork();
	if (id2 == -1)
		error(FORK_ERROR);
	if (id2 == 0)
		process2(fd_p, av[3], av[4], env);
	close(fd_p[0]);
	close(fd_p[1]);
	waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
		return (write(2, "Error\nWrong number of arguments\n", 32));
	pipex(av, env);
	return (0);
}
