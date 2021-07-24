/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:30:22 by achobany          #+#    #+#             */
/*   Updated: 2021/07/06 12:35:56 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swaps top two elements
void	sa(t_stack *stack, int value)
{
	if (stack->size == 0 || stack->size == 1)
		return ;
	swap(&stack->arr[0], &stack->arr[1]);
	if (value == 0)
		write_command("sa");
	else if (value == 1)
		write_command("sb");
}

//The first element becomes the last one
void	ra(t_stack *stack, int value)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->arr[0];
	while (i < stack->size - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->size - 1] = tmp;
	if (value == 0)
		write_command("ra");
	else if (value == 1)
		write_command("rb");
}

//The last element becomes the first one.
void	rra(t_stack *stack, int value)
{
	int	i;
	int	tmp;

	i = stack->size - 1;
	tmp = stack->arr[i];
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = tmp;
	if (value == 0)
		write_command("rra");
	else if (value == 1)
		write_command("rrb");
}

void	pa_pb(t_stack *from, t_stack *to, int value)
{
	int	tmp;

	tmp = from->arr[0];
	ra(from, 2);
	from->arr[from->size - 1] = '\0';
	from->size--;
	++to->size;
	to->arr[to->size] = '\0';
	to->arr[to->size - 1] = tmp;
	rra(to, 3);
	if (value == 1)
		write_command("pa");
	else if (value == 0)
		write_command("pb");
}
