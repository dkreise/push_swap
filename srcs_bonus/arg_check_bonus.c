/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:59:43 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 17:07:17 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/checker_bonus.h"

void	num_check(char *s)
{
	if (*s == '-' || *s == '+')
		s ++;
	if (*s == '\0')
		error(NULL, NULL, "Invalid Argument Error\n");
	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			error(NULL, NULL, "Invalid Argument Error: Not a Number\n");
		s ++;
	}
}

void	dupl_check(t_stack a)
{
	t_list	*first;
	t_list	*i;
	t_list	*j;

	first = a.first;
	i = first;
	while (i->next != first)
	{
		j = i->next;
		while (j != first)
		{
			if (i->value == j->value)
				error(&a, NULL, "Invalid Argument Error: Duplicates\n");
			j = j->next;
		}
		i = i->next;
	}
}

void	b_not_empty(t_stack *a, t_stack *b)
{
	clear_stack(b);
	write(1, "KO\n", 3);
	if (a->first != NULL)
		clear_stack(a);
	exit(0);
}

void	sorted_check(t_stack *a, t_stack *b)
{
	t_list	*l1;
	t_list	*l2;

	if (b->len == 0 && b->first == NULL)
	{
		l1 = a->first;
		l2 = l1->next;
		while (l2 != a->first)
		{
			if (l1->ind > l2->ind)
			{
				clear_stack(a);
				write(1, "KO\n", 3);
				exit(0);
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		clear_stack(a);
		write(1, "OK\n", 3);
		exit(0);
	}
	else
		b_not_empty(a, b);
}

void	arg_check_checker(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		num_check(argv[i]);
		ft_atoi(argv[i]);
		i ++;
	}
}
