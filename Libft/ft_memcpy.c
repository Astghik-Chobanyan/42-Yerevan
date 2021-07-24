/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:54:11 by achobany          #+#    #+#             */
/*   Updated: 2021/02/03 12:30:09 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *tmp1;
	char *tmp2;

	tmp1 = (char*)dest;
	tmp2 = (char*)src;
	while (n--)
		*tmp1++ = *tmp2++;
	return (dest);
}
