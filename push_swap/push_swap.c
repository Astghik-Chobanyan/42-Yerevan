/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:23:36 by achobany          #+#    #+#             */
/*   Updated: 2021/07/12 13:13:41 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	A;
	t_stack	B;
	int		*helper;
	int		argc1;

	if (argc == 1)
		return (0);
	helper = NULL;
	argc1 = ft_countword(argv[1], ' ');
	if (argc == 2 && argc1 > 1)
		start_first(argc, argv, argc1, helper, &A, &B);
	else if (argc > 1)
	{
		if (check1(argc, argv) || check2(argc, argv))
		{
			write_command("Error");
			return (0);
		}
		else
		{
			init_A(&A, argv, argc);
			if (is_sorted(&A))
			{
				free(A.arr);
				return (0);
			}
			init_B(&B, argc - 1);
			if (argc == 3)
				sa(&A, 0);
			else if (argc <= 6)
				simple_case(&A, &B);
			else 
			{
				helper = init_array(argv, argc);
				start_100(&A, &B, helper, 0, A.size, 0);
				free(helper);
				free(A.arr);
				free(B.arr);
			}
		}
	}
	return (0);
}
