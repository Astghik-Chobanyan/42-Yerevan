/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:02:01 by achobany          #+#    #+#             */
/*   Updated: 2021/07/19 18:16:39 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	call_child(char **argv, char **envp, int *pipe_fd)
{
	char	**cmd1;
	int		file_fd;

	cmd1 = ft_split(argv[2], ' ');
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	if (access(argv[1], R_OK) == -1)
	{
		ft_putstr_fd("pipex: no such file or directory", 2);
		exit(0);
	}
	file_fd = open(argv[1], O_RDONLY);
	dup2(file_fd, 0);
	if (execve(get_path(envp, cmd1[0]), cmd1, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found", 2);
		exit(0);
	}
	close(file_fd);
}

void	call_parent(char **argv, char **envp, int *pipe_fd)
{
	char	**cmd2;
	int		file_fd;

	cmd2 = ft_split(argv[3], ' ');
	wait(0);
	file_fd = open(argv[4], O_WRONLY | O_CREAT, 0777);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	dup2(file_fd, 1);
	if (execve(get_path(envp, cmd2[0]), cmd2, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found", 2);
		exit(0);
	}
	close(file_fd);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		pipe_res;
	pid_t	child_id;

	if (argc != 5)
	{
		ft_putstr_fd("pipex: pass arguments this way ./pipex file1 cmd1 cmd2 file2", 2);
		return (0);
	}
	pipe_res = pipe(pipe_fd);
	if (pipe_res == -1)
	{
		ft_putstr_fd("pipex: can't create pipe", 2);
		return (0);
	}
	child_id = fork();
	if (child_id == -1)
	{
		ft_putstr_fd("pipex: can't fork", 2);
		return (0);
	}
	if (child_id == 0)
		call_child(argv, envp, pipe_fd);
	else
		call_parent(argv, envp, pipe_fd);
	return (0);
}
