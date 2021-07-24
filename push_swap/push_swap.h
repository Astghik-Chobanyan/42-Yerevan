/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:43:32 by achobany          #+#    #+#             */
/*   Updated: 2021/07/12 13:14:51 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*arr;
	int	size;
}				t_stack;

// helper_1.c
void			write_command(char *s);
int				ft_atoi(char *num);
int				*init_array(char **argv, int argc);
void			swap(int *x, int *y);

//split.c
int				ft_countword(char *s, char c);
int		        ft_wordlen(char *s, char c);
char	        **ft_free(char **a);
char	        *ft_strncpy(char *dest, const char *src, size_t n);
char	        **ft_split(char const *s, char c);

// error_checker.c
int             ft_isdigit(char *num);
int             check_duplications(int *arr);
int             check1(int argc, char **argv);
int             check2(int argc, char **argv);

// stack.c
void            init_B(t_stack *B, int size);
void            init_A(t_stack *A, char **argv, int argc);
int             is_sorted(t_stack* stack);

// stack_operations.c
void            sa(t_stack *stack, int value);
void            ra(t_stack *stack, int value);
void            rra(t_stack *stack, int value);
void            pa_pb(t_stack *from, t_stack *to, int value);

// simple_case.c
int             get_min(t_stack *stack);//, int start, int end);
int             get_index(t_stack *stack, int value);
void            simple_case_3(t_stack *A);
void            simple_case(t_stack *A, t_stack *B);
void            move_to_top(t_stack *stack);//, int index, int min);

//sorting.c
int             partition(int *arr, int first, int last);
void            quick_sort(int *arr,int first, int last);

//advanced_case.c
void			start_100(t_stack *A, t_stack *B, int *array, int start, int end, int mid);
void			case_100(t_stack *A, t_stack *B, int *array, int start, int end, int mid);
int				get_max(t_stack *arr);
void			move_element(t_stack *stack, int element);
void			get_back(t_stack *A, t_stack *B);

//helper_2.c
char            **first_check(char **argv);
void            start_first(int argc, char **argv, int argc1, int *helper, t_stack *A, t_stack *B);

#endif
