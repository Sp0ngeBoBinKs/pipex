/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:45:43 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/26 17:46:05 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	handle_here_doc(char *lim, int *fd_p)
{
	char	*line;
	int		pipe_fd[2];
	char	*tmp;

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
