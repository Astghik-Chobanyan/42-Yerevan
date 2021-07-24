/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:06:25 by achobany          #+#    #+#             */
/*   Updated: 2021/07/19 18:16:47 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	path_index(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "PATH", 4)))
			return (i);
		i++;
	}
	return (0);
}

char	*get_path(char **envp, char *cmd)
{
	int		i;
	int		j;
	int		tmp_fd;
	char	*tmp;
	char	*path;
	char	**tmp_path;

	i = path_index(envp);
	if (cmd[0] == '/')
		return (cmd);
	else
	{
		tmp_path = ft_split(envp[i] + 5, ':');
		j = 0;
		while (tmp_path[j])
		{
			tmp = ft_strjoin(tmp_path[j], "/");
			path = ft_strjoin(tmp, cmd);
			tmp_fd = open(path, O_RDONLY);
			if (tmp_fd > -1)
			{
				close(tmp_fd);
				free(tmp);
				return (path);
			}
			free(tmp);
			j++;
		}
	}
	return (path);
}
