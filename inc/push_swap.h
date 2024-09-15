/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:32:23 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 17:03:59 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				ind;
	struct s_list	*next;
}				t_list;

typedef struct s_stack
{
	int		len;
	t_list	*first;
}				t_stack;

void	push_swap(int argc, char **argv);
int		ft_atoi(const char *nptr);
t_list	*ft_lstnew(int value);
void	fill_stack_a(t_stack *a, int argc, char **argv);
void	swap_aux(t_stack *st);
void	swap(t_stack *a, t_stack *b, char stack);
t_list	*ft_lstlast(t_stack st);
void	push_aux(t_stack *st1, t_stack *st2);
void	push(t_stack *a, t_stack *b, char stack);
void	rotate_aux(t_stack *st);
void	rotate(t_stack *a, t_stack *b, char stack);
void	reverse_rotate_aux(t_stack *st);
void	reverse_rotate(t_stack *a, t_stack *b, char stack);
void	error(t_stack *a, t_stack *b, char *str);
void	dupl_check(t_stack a);
void	arg_check(int argc, char **argv);
void	fill_stack_b(t_stack *a, t_stack *b, int chunk_cnt);
void	fill_a_ordered(t_stack *a, t_stack *b);
int		pos_in_stack(int ind, t_stack st);
void	solve_small_case(int cnt, t_stack *a, t_stack *b);
void	clear_stack(t_stack *st);
void	ordered_check(t_stack *a);
void	num_check(char *s);

#endif
