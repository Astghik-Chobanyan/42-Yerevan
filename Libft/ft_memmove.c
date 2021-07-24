/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:57:34 by achobany          #+#    #+#             */
/*   Updated: 2021/02/03 12:45:58 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *tmp1;
	unsigned char *tmp2;

	if (dest < src)
		ft_memcpy(dest, src, n);
	else if (dest > src)
	{
		tmp1 = (unsigned char*)dest;
		tmp2 = (unsigned char*)src;
		while (n--)
			tmp1[n] = tmp2[n];
	}
	return (dest);
}
