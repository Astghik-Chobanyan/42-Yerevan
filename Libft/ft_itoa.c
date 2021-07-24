/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:51:15 by achobany          #+#    #+#             */
/*   Updated: 2021/02/03 14:45:34 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		size_of_n(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*r;
	int		i;
	long	num;

	num = n;
	i = size_of_n(num);
	if (!(r = (char *)malloc(i + 1)))
		return (NULL);
	r[i] = '\0';
	i--;
	if (num == 0)
		r[0] = '0';
	else if (num < 0)
	{
		r[0] = '-';
		num *= -1;
	}
	while (num != 0)
	{
		r[i] = (num % 10) + '0';
		num /= 10;
		--i;
	}
	return (r);
}
