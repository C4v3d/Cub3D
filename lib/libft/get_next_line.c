/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:12:10 by Timmi             #+#    #+#             */
/*   Updated: 2025/09/12 15:14:16 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*dupnewline(char *str)
{
	int		i;
	char	*newline;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	newline = malloc(i + 2);
	if (!newline)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		newline[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		newline[i++] = '\n';
	newline[i] = '\0';
	return (newline);
}

static char	*conc(char *stach, char *buffer)
{
	int		i;
	int		j;
	char	*ptr;
	int		stach_len;
	int		buffer_len;

	i = -1;
	j = 0;
	stach_len = ft_strlen(stach);
	buffer_len = ft_strlen(buffer);
	if (!stach || !buffer)
		return (NULL);
	ptr = malloc((stach_len + buffer_len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (stach)
		while (stach[++i] != '\0')
			ptr[i] = stach[i];
	while (buffer[j] != '\0')
		ptr[i++] = buffer[j++];
	ptr[stach_len + buffer_len] = '\0';
	free(stach);
	return (ptr);
}

static char	*ft_trim(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
	{
		free(str);
		return (NULL);
	}
	new_str = malloc((ft_strlen(str) - i + 1));
	if (!new_str)
		return (NULL);
	i++;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

static char	*fill_stach(int fd, char *stach)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stach, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stach);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stach = conc(stach, buffer);
		if (!stach)
			return (NULL);
	}
	free(buffer);
	return (stach);
}

char	*get_next_line(int fd)
{
	char			*newline;
	static char		*stach;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!stach)
	{
		stach = malloc(1 * sizeof(char));
		if (!stach)
			return (NULL);
		stach[0] = '\0';
	}
	stach = fill_stach(fd, stach);
	if (!stach)
		return (NULL);
	newline = dupnewline(stach);
	stach = ft_trim(stach);
	return (newline);
}
