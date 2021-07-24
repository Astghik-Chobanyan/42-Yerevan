/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:46:01 by achobany          #+#    #+#             */
/*   Updated: 2021/02/01 12:36:03 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
