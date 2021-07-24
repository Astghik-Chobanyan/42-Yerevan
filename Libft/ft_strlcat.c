/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:58:11 by achobany          #+#    #+#             */
/*   Updated: 2021/02/03 13:10:58 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_size;
	size_t	s_size;
	size_t	j;

	s_size = 0;
	j = 0;
	d_size = 0;
	while (dst[d_size])
		++d_size;
	while (src[s_size])
		++s_size;
	if (size <= d_size)
		s_size += size;
	else
		s_size += d_size;
	while (src[j] && d_size + 1 < size)
	{
		dst[d_size] = src[j];
		d_size++;
		j++;
	}
	dst[d_size] = '\0';
	return (s_size);
}
