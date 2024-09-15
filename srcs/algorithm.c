/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:25:41 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 15:27:21 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	fill_b_aux(t_stack *a, t_stack *b, int i, int j)
{
	push(a, b, 'b');
	if (i <= j)
		rotate(a, b, 'b');
}

void	fill_stack_b(t_stack *a, t_stack *b, int chunk_cnt)
{
	int		chunk_size;
	int		act_max_ind;
	t_list	*cur;

	chunk_size = a->len / chunk_cnt;
	act_max_ind = chunk_size;
	cur = a->first;
	while (a->first)
	{
		if (cur->ind <= act_max_ind)
			fill_b_aux(a, b, cur->ind, act_max_ind - (chunk_size / 2));
		else
			rotate(a, b, 'a');
		cur = a->first;
		if (b->len == act_max_ind)
		{
			if (a->len < chunk_size + chunk_size / 2)
				act_max_ind += a->len;
			else
				act_max_ind += chunk_size;
		}
	}
}

int	pos_in_stack(int ind, t_stack st)
{
	int		i;
	t_list	*cur;

	i = 1;
	cur = st.first;
	while (cur->ind != ind)
	{
		i ++;
		cur = cur->next;
	}
	return (i);
}

void	push_and_swap_a(t_stack *a, t_stack *b)
{
	push(a, b, 'a');
	swap(a, b, 'a');
}

void	fill_a_ordered(t_stack *a, t_stack *b)
{
	int	flg;

	flg = 0;
	while (b->first)
	{
		if (flg == 0 && b->first->ind == b->len - 1)
		{
			push(a, b, 'a');
			flg = 1;
		}
		else if (flg == 0 && b->first->ind == b->len)
			push(a, b, 'a');
		else if (flg == 1 && b->first->ind == b->len + 1)
		{
			push_and_swap_a(a, b);
			flg = 0;
		}
		else
		{
			if (pos_in_stack(b->len + flg, *b) < b->len / 2 + 1)
				rotate(a, b, 'b');
			else
				reverse_rotate(a, b, 'b');
		}
	}
}
