/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:02:47 by achobany          #+#    #+#             */
/*   Updated: 2021/07/12 13:08:36 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**first_check(char **argv)
{
	int		arg_count;
	char	**helper;

	arg_count = ft_countword(argv[1], ' ');
	if (arg_count == 1 && ft_isdigit(argv[1]))
		return (0);
	helper = ft_split(argv[1], ' ');
	return (helper);
}

void	start_first(int argc, char **argv, int argc1, int *helper, t_stack *A, t_stack *B)
{
	char	**fake_argv;

	fake_argv = first_check(argv);
	argc = argc1 + 1;
	if (check1(argc, fake_argv) || check2(argc, fake_argv))
	{
		write_command("Error");
		return ;
	}
	else
	{
		init_A(A, fake_argv, argc);
		if (is_sorted(A))
		{
			free(A->arr);
			return ;
		}
		init_B(B, argc - 1);
		if (argc == 3)
			sa(A, 0);
		else if (argc <= 6)
			simple_case(A, B);
		else 
		{
			helper = init_array(fake_argv, argc);
			start_100(A, B, helper, 0, A->size, 0);
			free(helper);
			free(A->arr);
			free(B->arr);
		}
	}
}
