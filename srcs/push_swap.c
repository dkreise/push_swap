/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:30:09 by dkreise           #+#    #+#             */
/*   Updated: 2023/12/07 14:14:23 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.len = argc - 1;
	a.first = NULL;
	b.len = 0;
	b.first = NULL;
	fill_stack_a(&a, argc, argv);
	dupl_check(a);
	if (a.len <= 5)
		solve_small_case(a.len, &a, &b);
	else if (a.len > 5 && a.len < 250)
		fill_stack_b(&a, &b, 4);
	else
		fill_stack_b(&a, &b, 8);
	fill_a_ordered(&a, &b);
	clear_stack(&a);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	arg_check(argc, argv);
	push_swap(argc, argv);
	return (0);
}
