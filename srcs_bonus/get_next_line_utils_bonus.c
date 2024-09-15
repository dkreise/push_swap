/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:40:38 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 15:52:23 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len ++;
	return (len);
}

int	line_len(char *storage)
{
	int	i;

	i = 0;
	if (storage == NULL)
		return (0);
	while (storage[i] != '\0')
	{
		if (storage[i] == '\n')
			return (i + 1);
		i ++;
	}
	return (0);
}

static void	fill(size_t len, char *s, char **strjoin)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		**strjoin = s[i];
		*strjoin = *strjoin + 1;
		i ++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*strjoin;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (0);
		s1[0] = '\0';
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strjoin = (char *) malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (strjoin == NULL)
	{
		free(s1);
		return (NULL);
	}
	fill(len_s1, s1, &strjoin);
	fill(len_s2, s2, &strjoin);
	*strjoin = '\0';
	free(s1);
	return (strjoin - len_s1 - len_s2);
}
