/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:19:32 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/25 15:41:00 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
