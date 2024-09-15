/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:04:42 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 16:44:08 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line_bonus.h"

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
void	arg_check_checker(int argc, char **argv);
void	fill_stack_b(t_stack *a, t_stack *b, int chunk_cnt);
void	fill_a_ordered(t_stack *a, t_stack *b);
int		pos_in_stack(int ind, t_stack st);
void	clear_stack(t_stack *st);
void	b_not_empty(t_stack *a, t_stack *b);
void	sorted_check(t_stack *a, t_stack *b);
void	num_check(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
