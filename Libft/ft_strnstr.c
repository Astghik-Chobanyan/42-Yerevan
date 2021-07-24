/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:37:31 by achobany          #+#    #+#             */
/*   Updated: 2021/02/03 14:20:09 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && little[j] && (i + j) < len)
			j++;
		if (!little[j])
			return (char*)(&big[i]);
		j = 0;
		i++;
	}
	if (!little[0])
		return (char*)(&big[i]);
	return (NULL);
}
