/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:36:11 by achobany          #+#    #+#             */
/*   Updated: 2021/07/12 12:58:40 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 1 if is digit
int	ft_isdigit(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
	{
		if (num[i + 1] == '0')
			return (0);
		++i;
	}
	while (num[i])
	{
		if (num[i] >= '0' && num[i] <= '9')
			++i;
		else
			return (0);
	}
	return (1);
}

//returns 1 if there is duplicate parameter
int	check_duplications(int *arr)
{
	int	i;
	int	j;

	j = 0;
	while (arr[j] != '\0')
	{
		i = j + 1;
		while (arr[i] != '\0')
		{
			if (arr[j] == arr[i])
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

// returns 1 if there es error
int	check1(int argc, char **argv)
{
	while (argc != 1)
	{
		if (!ft_isdigit(argv[argc - 1]))
			return (1);
		argc--;
	}
	return (0);
}

//returns 1 if there is error
int	check2(int argc, char **argv)
{
	int	*array;

	array = init_array(argv, argc);
	if (check_duplications(array))
	{
		free(array);
		return (1);
	}
	free(array);
	return (0);
}
