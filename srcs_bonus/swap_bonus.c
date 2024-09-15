/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:35:46 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 15:55:44 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/checker_bonus.h"

void	swap_aux(t_stack *st)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (st->len > 1)
	{
		first = st->first;
		last = ft_lstlast(*st);
		second = first->next;
		st->first = second;
		if (st->len > 2)
		{
			first->next = second->next;
			second->next = first;
			last->next = second;
		}
	}
}

void	swap(t_stack *a, t_stack *b, char stack)
{
	if (stack == 'a')
	{
		swap_aux(a);
		write(1, "sa\n", 3);
	}
	if (stack == 'b')
	{
		swap_aux(b);
		write(1, "sb\n", 3);
	}
	if (stack == 's')
	{
		swap_aux(a);
		swap_aux(b);
		write(1, "ss\n", 3);
	}
}
