/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:57:25 by igrousso          #+#    #+#             */
/*   Updated: 2025/01/21 20:56:03 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_arg(char *str)
{
    if (access(str, F_OK) == -1)
    {
        perror("First argument ");
        exit(EXIT_FAILURE);
    }
    if (access(str, R_OK) == -1)
    {
        perror("First argument ");
        exit(EXIT_FAILURE);
    }
}

void	fourth_arg(char *str)
{
    if (access(str, F_OK) == -1)
    {
        perror("Fourth argument ");
        exit(EXIT_FAILURE);
    }
    if (access(str, W_OK) == -1)
    {
        perror("Fourth argument ");
        exit(EXIT_FAILURE);
    }
}

int	first_check(char **av)
{
	int i;

	i = 0;
	first_arg(av[1]);
	fourth_arg(av[4]);
    i += second_arg(av[2]);
	i += third_arg(av[3]);
	return (i);
}

char *find_path(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char **get_path_from_env(char **env)
{

	char **tab;
	char *str;

	str = find_path(env);
	tab = ft_split(str, ':');
	return (tab);
}

void ft_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char *test(char **tab, char *av)
{
	int i;
	int count;
	char *str;
	char *str2;

	i = 0;
	count = 0;
	while (tab[i])
	{
		str = ft_strjoin(tab[i++], "/");
		str2 = ft_strjoin(str, av);
		free(str);
		if (access(str2, X_OK) == 0)
			return (str2);
		free(str2);
	}
	return (NULL);
}

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
		return (write(2, "Error\nWrong number of arguments\n", 32));
	char **tab;
	int count_check;

	count_check = first_check(av);
	if (count_check == 0)
		tab = get_path_from_env(env);
	if (!tab)
		return (1);

	ft_free(tab);
	return (0);
}

/*
int	main(int ac, char **av)
{
	int	id;
	int	fd[2];
	char buff[6];
	int id2;

	id2 = 5;
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (1);
	if (id == 0)
	{
		close(fd[0]);
		ft_putnbr_fd(15, fd[1]);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0], buff, 5);
		buff[2] = '\0';
		close(fd[0]);
		wait(NULL);
		printf("%s\n", buff);
		fflush(stdout);
	}
	printf("%d\n", id);
	fflush(stdout);
	return (0);
}*/
