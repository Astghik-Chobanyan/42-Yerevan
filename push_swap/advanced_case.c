/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:38:56 by achobany          #+#    #+#             */
/*   Updated: 2021/07/12 12:54:02 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_100(t_stack *A, t_stack *B, int *array, int start, int end, int mid)
{
	int	mid_index;
	int	mid_value;
	int	i;

	mid_index = (end - start) / 5 + mid;
	mid_value = array[mid_index];
	i = mid_index - start;
	if (A->size > 5)
	{
		while (i)
		{
			if (A->arr[0] < mid_value)
			{
				pa_pb(A, B, 0);
				i--;
			}
			else if (A->arr[A->size - 1] < mid_value)
			{
				rra(A, 0);
				pa_pb(A, B, 0);
				i--;
			}
			else if (A->arr[1] < mid_value)
			{
				sa(A, 0);
				pa_pb(A, B, 0);
				i--;
			}
			else
				ra(A, 0);
		}
		case_100(A, B, array, mid_index, end, mid_index);
	}
	else
		simple_case(A, B);
}

int	get_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 1;
	max = stack->arr[0];
	while (i < stack->size)
	{
		if (stack->arr[i] > max)
			max = stack->arr[i];
		i++;
	}
	return (max);
}

void	move_element(t_stack *stack, int element)
{
	int	index;

	index = get_index(stack, element);
	while (index != 0)
	{
		if (index == 1)
			sa(stack, 1);
		else if (index >= (stack->size / 2))
			rra(stack, 1);
		else if (index < (stack->size / 2))
			ra(stack, 1);
		index = get_index(stack, element);
	}
}

void	get_back(t_stack *A, t_stack *B)
{
	int	max;

	while (B->size > 2)
	{
		max = get_max(B);
		move_element(B, max);
		pa_pb(B, A, 1);
	}
	if (B->size == 2)
	{
		if (B->arr[0] > B->arr[1])
		{
			pa_pb(B, A, 1);
			pa_pb(B, A, 1);
		}
		else
		{
			sa(B, 1);
			pa_pb(B, A, 1);
			pa_pb(B, A, 1);
		}
	}
}

void	start_100(t_stack *A, t_stack *B, int *array, int start, int end, int mid)
{
	quick_sort(array, 0, A->size - 1);
	case_100(A, B, array, start, end, mid);
	get_back(A, B);
}
