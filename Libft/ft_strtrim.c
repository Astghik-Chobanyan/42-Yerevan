/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:48:27 by achobany          #+#    #+#             */
/*   Updated: 2021/02/03 17:49:45 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		f_strchr(const char *str, char c)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	size_t		s1_size;
	char		*res;

	i = 0;
	while (s1[i] && f_strchr(set, s1[i]))
		i++;
	s1_size = ft_strlen(s1);
	while (s1_size > i && f_strchr(set, s1[s1_size - 1]))
		s1_size--;
	if (!(res = (char *)malloc(s1_size - i + 1)))
		return (NULL);
	j = 0;
	while (i < s1_size)
		res[j++] = s1[i++];
	res[j] = '\0';
	return (res);
}
