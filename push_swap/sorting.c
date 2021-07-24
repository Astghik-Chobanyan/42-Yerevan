/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:39:40 by achobany          #+#    #+#             */
/*   Updated: 2021/07/12 13:23:26 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *arr, int first, int last)
{
	int	i;
	int	j;

	i = first;
	j = first;
	while (j < last)
	{
		if (arr[j] < arr[last])
		{
			swap(&arr[j], &arr[i]);
			i++;
		}
		j++;
	}
	swap(&arr[i], &arr[last]);
	return (i);
}

void	quick_sort(int *arr, int first, int last)
{
	int	i;

	if (first < last)
	{
		i = partition(arr, first, last);
		quick_sort(arr, first, i - 1);
		quick_sort(arr, i + 1, last);
	}
}
