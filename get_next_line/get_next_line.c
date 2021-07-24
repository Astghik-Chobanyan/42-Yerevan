/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:51:56 by achobany          #+#    #+#             */
/*   Updated: 2021/03/12 16:03:44 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*write_in_line(char *arr)
{
	int		i;
	char	*line;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i] && arr[i] != '\n')
		++i;
	if (!(line = (char*)malloc((i + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (arr[i] && arr[i] != '\n')
	{
		line[i] = arr[i];
		++i;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *src)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	if (!src)
		return (0);
	while (src[i] && src[i] != '\n')
		i++;
	if (!src[i])
	{
		free(src);
		return (0);
	}
	if (!(rest = (char *)malloc((ft_strlen(src) - i + 1) * sizeof(char))))
		return (0);
	i = i + 1;
	while (src[i])
		rest[j++] = src[i++];
	rest[j] = '\0';
	free(src);
	return (rest);
}

int		get_next_line(int fd, char **line)
{
	static char		*rest;
	char			*buff;
	int				read_res;

	read_res = 1;
	if (!(buff = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while (read_res != 0 && !check_nline(rest))
	{
		if ((read_res = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[read_res] = '\0';
		rest = ft_strjoin(rest, buff);
	}
	free(buff);
	*line = write_in_line(rest);
	rest = get_rest(rest);
	if (read_res == 0)
		return (0);
	return (1);
}
