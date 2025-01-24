/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:57:25 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/24 23:05:05 by igrousso         ###   ########.fr       */
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

int	command_arg(char **av, int fd1, int fd2)
{
	int	i;

	i = 0;
	if (!av[0])
	{
		ft_free(av);
		ft_close(fd1, fd2);
		write(2, "command not found\n", 18);
		exit(127);
	}
	if (access(av[0], F_OK) == 0)
		i++;
	if (access(av[0], X_OK) == 0)
		i += 2;
	if (i == 1)
	{
		write_error("permission denied: ", av[0]);
		ft_free(av);
		ft_close(fd1, fd2);
		exit(126);
	}
	else if (i == 3)
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
	if (!tab)
		return (NULL);
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

void	write_error(char *str1, char *str2)
{
	char	*str3;
	char	*tmp;

	tmp = ft_strjoin(str1, str2);
	str3 = ft_strjoin(tmp, "\n");
	free(tmp);
	write(2, str3, ft_strlen(str3));
	free(str3);
}

void	errno_exit(void)
{
	if (errno == ENOENT)
		exit(127);
	else if (errno == EACCES)
		exit(126);
	else
		exit(EXIT_FAILURE);
}

void	error(int event, char *str, int fd1, int fd2)
{
	if (event == PIPE_ERROR)
		perror("Error creating pipe");
	if (event == FORK_ERROR)
		perror("Error during fork");
	if (event == SPLIT_ERROR)
		perror("Error during split");
	if (event == DUP_ERROR)
		perror("Error duplicating the file descriptor");
	if (event == OPEN_ERROR)
		perror("Error opening file");
	if (event == EXEC_ERROR)
		perror("Error during execve");
	if (event == ABSOLUT_PATH_ERROR)
	{
		write_error("no such file or directory: ", str);
		free(str);
	}
	if (event == EXECUTABLE_ERROR)
	{
		write_error("command not found: ", str);
		free(str);
	}
	ft_close(fd1, fd2);
	errno_exit();
}

void	error2(char **arg, char **env, int fd1, int fd2)
{
	char	*tmp;

	if (env[0] == 0)
	{
		ft_close(fd1, fd2);
		ft_free(arg);
		exit(127);
	}
	if (ft_strchr(arg[0], '/'))
	{
		ft_close(fd1, fd2);
		tmp = ft_strdup(arg[0]);
		ft_free(arg);
		error(ABSOLUT_PATH_ERROR, tmp, -1, -1);
	}
}

char	**get_arg(char *command, char **env, int fd1, int fd2)
{
	char	**arg;
	char	*executable;
	char	*tmp;

	arg = ft_split(command, ' ');
	if (!arg)
		error(SPLIT_ERROR, NULL, fd1, fd2);
	if (command_arg(arg, fd1, fd2) == 0)
	{
		error2(arg, env, fd1, fd2);
		executable = find_executable(env, arg[0]);
		if (!executable)
		{
			tmp = ft_strdup(arg[0]);
			ft_free(arg);
			error(EXECUTABLE_ERROR, tmp, fd1, fd2);
		}
		free(arg[0]);
		arg[0] = ft_strdup(executable);
		free(executable);
	}
	return (arg);
}

void	ft_close(int fd1, int fd2)
{
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
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

int ft_wait(int id1, int id2)
{
	int status2;

	waitpid(id1, NULL, 0);
	waitpid(id2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (0);
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
	// printf("%d\n", i);
	return (i);
}
