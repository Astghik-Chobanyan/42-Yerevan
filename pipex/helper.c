/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:59:27 by achobany          #+#    #+#             */
/*   Updated: 2021/07/19 18:16:28 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_size;
	int		s2_size;
	int		i;
	char	*res;

	i = 0;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (!(res = (char *)malloc((s1_size + s2_size) * sizeof(char))))
		return (NULL);
	while (i < s1_size)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2_size--)
	{
		res[s1_size] = s2[i];
		i++;
		s1_size++;
	}
	res[s1_size] = '\0';
	return (res);
}

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
