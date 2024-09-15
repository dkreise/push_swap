/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:23:41 by dkreise           #+#    #+#             */
/*   Updated: 2023/11/28 15:51:52 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/get_next_line_bonus.h"

static char	*malloc_buff(void)
{
	char	*buff;

	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	buff[0] = '\0';
	return (buff);
}

static char	*fill_storage(int fd, char **storage, int num_bytes)
{
	char	*buffer;

	buffer = malloc_buff();
	if (buffer == NULL)
	{
		free(*storage);
		return (NULL);
	}
	while (num_bytes > 0 && line_len(buffer) == 0)
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes == -1)
		{
			free(buffer);
			free(*storage);
			return (NULL);
		}
		if (num_bytes > 0)
		{
			buffer[num_bytes] = '\0';
			*storage = ft_strjoin(*storage, buffer);
		}
	}
	free(buffer);
	return (*storage);
}

static char	*extract_line(char *storage)
{
	char	*line;
	int		len;
	int		i;

	if (!storage)
		return (NULL);
	len = line_len(storage);
	i = 0;
	if (len == 0)
		len = ft_strlen(storage);
	if (len == 0)
		return (NULL);
	line = (char *) malloc((len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (i < len)
	{
		line[i] = storage[i];
		i ++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_storage(char *storage, int len_line)
{
	char	*new_storage;
	int		len_new;
	int		i;

	len_new = ft_strlen(storage) - len_line;
	if (len_new == 0)
	{
		free(storage);
		return (NULL);
	}
	i = 0;
	new_storage = (char *) malloc((len_new + 1) * sizeof(char));
	if (new_storage == NULL)
	{
		free(storage);
		return (NULL);
	}
	while (storage[len_line + i] != '\0')
	{
		new_storage[i] = storage[len_line + i];
		i++;
	}
	new_storage[i] = '\0';
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage = NULL;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage || (storage && !line_len(storage)))
		storage = fill_storage(fd, &storage, 1);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (line == NULL)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = update_storage(storage, ft_strlen(line));
	return (line);
}

/*
int	main(void)
{
	int	file;

	file = open("test3", O_RDONLY);
	printf("LINE 1: %s\n", get_next_line(file));
	printf("LINE 2: %s\n", get_next_line(file));
	printf("LINE 3: %s\n", get_next_line(file));
	//printf("LINE 4: %s\n", get_next_line(file));
	//printf("LINE 5: %s\n", get_next_line(file));
	//printf("LINE 6: %s\n", get_next_line(file));
	return (0);
}*/
