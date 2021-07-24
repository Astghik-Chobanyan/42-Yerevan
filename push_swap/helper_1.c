/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:39:09 by achobany          #+#    #+#             */
/*   Updated: 2021/07/12 13:02:28 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_command(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_atoi(char *num)
{
	long	res;
	int		sign;
	int		i;

	sign = 1;
	res = 0;
	i = 0;
	if (num[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		res = res * 10 + num[i] - '0';
		i++;
	}
	if (sign * res < -2147483648 || sign * res > 2147483647)
	{
		write_command("Error");
		exit(1);
	}
	return (sign * res);
}

int	*init_array(char **argv, int argc)
{
	int	*arr;

	arr = (int *)malloc(argc * sizeof(int));
	if (!arr)
		return (NULL);
	arr[argc - 1] = '\0';
	while (argc != 1)
	{
		arr[argc - 2] = ft_atoi(argv[argc - 1]);
		argc--;
	}
	return (arr);
}

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
