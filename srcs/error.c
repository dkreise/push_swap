/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:23:23 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 15:26:47 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	clear_stack(t_stack *st)
{
	t_list	*first;
	t_list	*cur;
	t_list	*new;

	first = st->first;
	new = first->next;
	while (new->next != first)
	{
		cur = new;
		new = cur->next;
		free(cur);
	}
	if (new != first)
		free(new);
	free(first);
	st->first = NULL;
}

static void	ft_putstr_fd(int fd, char *s)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s ++;
	}
}

void	error(t_stack *a, t_stack *b, char *str)
{
	if (a && a->first)
		clear_stack(a);
	if (b && b->first)
		clear_stack(b);
	if (str)
		ft_putstr_fd(2, str);
	else
		write(2, "Error\n", 6);
	exit(1);
}
