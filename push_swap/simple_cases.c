/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:39:26 by achobany          #+#    #+#             */
/*   Updated: 2021/07/12 13:20:35 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack)
{
	int	min;
	int	i;

	i = 1;
	min = stack->arr[0];
	while (i < stack->size)
	{
		if (stack->arr[i] < min)
			min = stack->arr[i];
		i++;
	}
	return (min);    
}

int	get_index(t_stack *stack, int value)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

void	simple_case_3(t_stack *A)
{
	int min;

	min = get_min(A);
	if (A->arr[0] == min)
	{
		sa(A, 0);
		ra(A, 0);
	}
	else if (A->arr[1] == min)
	{
		if (A->arr[0] > A->arr[2])
			ra(A, 0);
		else
			sa(A, 0);
	}
	else if (A->arr[2] == min)
	{
		if (A->arr[0] > A->arr[1])
			sa(A, 0);
		rra(A, 0);
	}
}

void	move_to_top(t_stack *stack)
{
	int	min;
	int	index;

	min = get_min(stack);
	index = get_index(stack, min);
	while (index != 0)
	{
		if (index == 1)
			sa(stack, 0);
		else if (index >= (stack->size / 2))
			rra(stack, 0);
		else if (index < (stack->size / 2))
			ra(stack, 0);
		index = get_index(stack, min);
	}
}

void	simple_case(t_stack *A, t_stack *B)
{
	int	tmp;

	tmp = 0;
	while (A->size != 3)
	{
		move_to_top(A);
		pa_pb(A, B, 0);
		tmp++;
	}
	if (!is_sorted(A))
		simple_case_3(A);
	while (tmp--)
		pa_pb(B, A, 1);
}
