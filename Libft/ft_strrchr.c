/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:44:37 by achobany          #+#    #+#             */
/*   Updated: 2021/02/03 14:28:14 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int size;

	size = ft_strlen(str);
	while (size > 0)
	{
		if (str[size] == (char)c)
			return (char *)str + size;
		size--;
	}
	if (str[size] == (char)c)
		return ((char *)str + size);
	return (NULL);
}
