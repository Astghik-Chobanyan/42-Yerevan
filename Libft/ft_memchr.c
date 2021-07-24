/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:35:07 by achobany          #+#    #+#             */
/*   Updated: 2021/02/01 12:34:13 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	unsigned char	*tmp;
	int				i;

	i = 0;
	tmp = (unsigned char*)ptr;
	while (count--)
	{
		if (tmp[i] == (unsigned char)ch)
			return (&tmp[i]);
		++i;
	}
	return (NULL);
}
