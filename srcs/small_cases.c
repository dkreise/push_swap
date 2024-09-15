/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:33:47 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 15:28:19 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	case_two(t_stack *a, t_stack *b)
{
	t_list	*first;

	first = a->first;
	if (first->ind > first->next->ind)
		swap(a, b, 'a');
}

static void	case_three(t_stack *a, t_stack *b)
{
	if (pos_in_stack(3, *a) == 1)
	{
		if (pos_in_stack(2, *a) == 2)
		{
			swap(a, b, 'a');
			reverse_rotate(a, b, 'a');
		}
		else
			rotate(a, b, 'a');
	}
	else if (pos_in_stack(3, *a) == 2)
	{
		if (pos_in_stack(1, *a) == 1)
		{
			swap(a, b, 'a');
			rotate(a, b, 'a');
		}
		else
			reverse_rotate(a, b, 'a');
	}
	else if (pos_in_stack(1, *a) == 2)
		swap(a, b, 'a');
}

static void	case_four(t_stack *a, t_stack *b)
{
	while (a->first->ind != 4)
	{
		if (pos_in_stack(4, *a) < 3)
			rotate(a, b, 'a');
		else
			reverse_rotate(a, b, 'a');
	}
	push(a, b, 'b');
	case_three(a, b);
	push(a, b, 'a');
	rotate(a, b, 'a');
}

static void	case_five(t_stack *a, t_stack *b)
{
	while (a->first->ind != 5)
	{
		if (pos_in_stack(5, *a) <= 3)
			rotate(a, b, 'a');
		else
			reverse_rotate(a, b, 'a');
	}
	push(a, b, 'b');
	case_four(a, b);
	push(a, b, 'a');
	rotate(a, b, 'a');
}

void	solve_small_case(int cnt, t_stack *a, t_stack *b)
{
	if (cnt == 2)
		case_two(a, b);
	if (cnt == 3)
		case_three(a, b);
	if (cnt == 4)
		case_four(a, b);
	if (cnt == 5)
		case_five(a, b);
}
