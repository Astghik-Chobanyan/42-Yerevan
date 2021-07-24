/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:26:59 by achobany          #+#    #+#             */
/*   Updated: 2021/07/06 12:40:03 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_B(t_stack *B, int size)
{
	B->arr = (int *)malloc(size * sizeof(int));
	if (!B->arr)
		return ;
	B->size = 0;
}

void	init_A(t_stack *A, char **argv, int argc)
{
	A->arr = init_array(argv, argc);
	A->size = argc - 1;
}

//returns 1 if is sorted
int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i + 1 < stack->size)
	{
		if (stack->arr[i] < stack->arr[i + 1])
			++i;
		else
			return (0);
	}
	return (1);
}
