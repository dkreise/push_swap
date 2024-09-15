/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:09:17 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 15:55:23 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/checker_bonus.h"

void	rotate_aux(t_stack *st)
{
	t_list	*first;

	first = st->first;
	if (first != NULL)
		st->first = first->next;
}

void	rotate(t_stack *a, t_stack *b, char stack)
{
	if (stack == 'a')
	{
		rotate_aux(a);
		write(1, "ra\n", 3);
	}
	if (stack == 'b')
	{
		rotate_aux(b);
		write(1, "rb\n", 3);
	}
	if (stack == 'r')
	{
		rotate_aux(a);
		rotate_aux(b);
		write(1, "rr\n", 3);
	}
}
