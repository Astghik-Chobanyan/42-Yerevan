/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:52:01 by achobany          #+#    #+#             */
/*   Updated: 2021/03/12 16:03:35 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int size;

	size = 0;
	if (!str)
		return (0);
	while (str[size] != '\0')
		++size;
	return (size);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	size_t	size;
	char	*res;

	if (!s1 && !s2)
		return (0);
	s1_size = ft_strlen((char *)s1);
	s2_size = ft_strlen((char *)s2);
	size = s1_size + s2_size + 1;
	if (!(res = malloc(sizeof(char) * size)))
		return (0);
	ft_memmove(res, s1, s1_size);
	ft_memmove(res + s1_size, s2, s2_size);
	res[size - 1] = '\0';
	free((char *)s1);
	return (res);
}

int		check_nline(char *arr)
{
	int i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
	{
		if (arr[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}
