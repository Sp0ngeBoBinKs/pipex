/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:25:01 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/26 17:52:48 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

void	error(int event, char *str, int fd1, int fd2)
{
	if (event == PIPE_ERROR)
		perror("Error creating pipe");
	if (event == FORK_ERROR)
		perror("Error during fork");
	if (event == SPLIT_ERROR || event == GNL_ERROR)
		perror("Error");
	if (event == DUP_ERROR)
		perror("Error duplicating the file descriptor");
	if (event == OPEN_ERROR)
		perror("Error opening file");
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

void	handle_error(char *arg, int fd1, int fd2)
{
	int	i;

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
