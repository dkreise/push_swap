/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:02:22 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 15:27:49 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_aux2(t_list *elem, t_list *first2, t_stack *st1, t_stack *st2)
{
	t_list	*last1;
	t_list	*last2;

	last1 = ft_lstlast(*st1);
	if (st1->len == 1)
		st1->first = NULL;
	else
	{
		st1->first = elem->next;
		last1->next = st1->first;
	}
	if (first2 == NULL)
	{
		st2->first = elem;
		elem->next = elem;
	}
	else
	{
		last2 = ft_lstlast(*st2);
		st2->first = elem;
		elem->next = first2;
		last2->next = st2->first;
	}
}

//take the 1st elem of st1 and put it at the top of st2:
void	push_aux(t_stack *st1, t_stack *st2)
{
	t_list	*elem;
	t_list	*first2;

	if (st1->len > 0)
	{
		elem = st1->first;
		first2 = st2->first;
		push_aux2(elem, first2, st1, st2);
		st1->len = st1->len - 1;
		st2->len = st2->len + 1;
	}
}

void	push(t_stack *a, t_stack *b, char stack)
{
	if (stack == 'a')
	{
		push_aux(b, a);
		write(1, "pa\n", 3);
	}
	if (stack == 'b')
	{
		push_aux(a, b);
		write(1, "pb\n", 3);
	}
}
