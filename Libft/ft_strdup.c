/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:37:25 by achobany          #+#    #+#             */
/*   Updated: 2021/02/05 12:01:25 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*helper;
	size_t	s_size;
	size_t	i;

	i = 0;
	s_size = ft_strlen(str) + 1;
	if (!(helper = (char*)malloc(s_size * sizeof(char))))
		return (NULL);
	while (i < s_size)
	{
		helper[i] = str[i];
		++i;
	}
	helper[i] = '\0';
	return (helper);
}
