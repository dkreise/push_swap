/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:13:50 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 16:32:19 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/checker_bonus.h"

int	ft_atoi(const char *nptr)
{
	long int	n;
	int			sign;

	n = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\r'
		|| *nptr == '\f' || *nptr == '\v')
		nptr ++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr ++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + (*nptr - 48);
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && (-n) < INT_MIN))
			error(NULL, NULL, "Invalid Argument Error: Not an Integer\n");
		nptr ++;
	}
	return (n * sign);
}

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->value = value;
	new->ind = 0;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_stack st)
{
	t_list	*first;
	t_list	*cur;
	t_list	*last;

	first = st.first;
	cur = first;
	while (cur->next != first)
	{
		last = cur->next;
		cur = last;
	}
	return (cur);
}

static void	set_indices(t_stack a)
{
	t_list	*first;
	t_list	*i;
	t_list	*j;
	int		ind;

	first = a.first;
	i = first;
	while (i->ind == 0)
	{
		j = i->next;
		ind = 0;
		while (j != i)
		{
			if (i->value > j->value)
				ind ++;
			j = j->next;
		}
		i->ind = ind + 1;
		i = i->next;
	}
}

void	fill_stack_a(t_stack *a, int argc, char **argv)
{
	t_list	*temp1;
	t_list	*temp2;
	int		i;

	temp1 = ft_lstnew(ft_atoi(argv[1]));
	if (!temp1)
		error(NULL, NULL, "Malloc Error\n");
	a->first = temp1;
	i = 2;
	while (i < argc)
	{
		temp2 = ft_lstnew(ft_atoi(argv[i]));
		if (!temp2)
			error(a, NULL, "Malloc Error\n");
		temp1->next = temp2;
		temp1 = temp2;
		i ++;
	}
	temp1->next = a->first;
	set_indices(*a);
}
