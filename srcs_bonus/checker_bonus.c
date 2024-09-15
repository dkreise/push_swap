/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:46:22 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 16:45:09 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/checker_bonus.h"

void	do_movement2(char *movement, t_stack *a, t_stack *b)
{
	if (ft_strncmp(movement, "ra\n", 3) == 0)
		rotate_aux(a);
	else if (ft_strncmp(movement, "rb\n", 3) == 0)
		rotate_aux(b);
	else if (ft_strncmp(movement, "rr\n", 3) == 0)
	{
		rotate_aux(a);
		rotate_aux(b);
	}
	else if (ft_strncmp(movement, "rra\n", 4) == 0)
		reverse_rotate_aux(a);
	else if (ft_strncmp(movement, "rrb\n", 4) == 0)
		reverse_rotate_aux(b);
	else if (ft_strncmp(movement, "rrr\n", 4) == 0)
	{
		reverse_rotate_aux(a);
		reverse_rotate_aux(b);
	}
	else
		error(a, b, "Error: Movement does not exist\n");
}

void	do_movement1(char *movement, t_stack *a, t_stack *b)
{
	if (ft_strncmp(movement, "sa\n", 3) == 0)
		swap_aux(a);
	else if (ft_strncmp(movement, "sb\n", 3) == 0)
		swap_aux(b);
	else if (ft_strncmp(movement, "ss\n", 3) == 0)
	{
		swap_aux(a);
		swap_aux(b);
	}
	else if (ft_strncmp(movement, "pa\n", 3) == 0)
		push_aux(b, a);
	else if (ft_strncmp(movement, "pb\n", 3) == 0)
		push_aux(a, b);
	else
		do_movement2(movement, a, b);
}

void	checker(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*movement;

	a.len = argc - 1;
	a.first = NULL;
	b.len = 0;
	b.first = NULL;
	fill_stack_a(&a, argc, argv);
	dupl_check(a);
	movement = get_next_line(0);
	while (ft_strncmp(movement, "\n", 2) != 0)
	{
		do_movement1(movement, &a, &b);
		movement = get_next_line(0);
	}
	sorted_check(&a, &b);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	arg_check_checker(argc, argv);
	checker(argc, argv);
	return (0);
}
