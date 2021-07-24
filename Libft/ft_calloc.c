/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:37:48 by achobany          #+#    #+#             */
/*   Updated: 2021/02/05 12:04:05 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*tmp;
	size_t	i;

	i = num * size;
	if (!(tmp = (char*)malloc(i)))
		return (NULL);
	ft_memset(tmp, 0, i);
	return (tmp);
}
