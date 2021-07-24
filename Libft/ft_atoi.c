/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:44:16 by achobany          #+#    #+#             */
/*   Updated: 2021/02/02 13:50:01 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_space(char str)
{
	if (str == ' ' || str == '\t' || str == '\n' || str == '\v' ||
			str == '\f' || str == '\r')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int i;
	int res;
	int sign;

	sign = 1;
	res = 0;
	i = 0;
	while (is_space(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}
