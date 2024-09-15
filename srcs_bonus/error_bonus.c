/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:23:23 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 16:38:19 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/checker_bonus.h"

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*ptr1 != '\0' && *ptr2 != '\0' && i < n - 1)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1 ++;
		ptr2 ++;
		i ++;
	}
	return (*ptr1 - *ptr2);
}
