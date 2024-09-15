/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:19:23 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 15:28:06 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate_aux(t_stack *st)
{
	t_list	*last;

	if (st->first != NULL)
	{
		last = ft_lstlast(*st);
		st->first = last;
	}
}

void	reverse_rotate(t_stack *a, t_stack *b, char stack)
{
	if (stack == 'a')
	{
		reverse_rotate_aux(a);
		write(1, "rra\n", 4);
	}
	if (stack == 'b')
	{
		reverse_rotate_aux(b);
		write(1, "rrb\n", 4);
	}
	if (stack == 'r')
	{
		reverse_rotate_aux(a);
		reverse_rotate_aux(b);
		write(1, "rrr\n", 4);
	}
}
