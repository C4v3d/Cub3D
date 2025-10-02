/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:42:38 by timmi             #+#    #+#             */
/*   Updated: 2025/10/02 11:46:10 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*get_inline_map(int fd)
{
	char	*line;
	char	*inline_map;
	char	*fp;

	inline_map = calloc(1, sizeof(char));
	if (!inline_map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (line[0] != '\n')
		{
			fp = inline_map;
			inline_map = ft_strjoin(inline_map, line);
			w_free((void **)&fp);
		}
		w_free((void **)&line);
		if (!inline_map)
			return (NULL);
	}
	return (inline_map);
}

static size_t	calc_xs(char *s)
{
	size_t	xs;

	xs = 0;
	while (*s)
	{
		if (*s == '\n')
			xs++;
		s++;
	}
	return (xs);
}

static size_t	get_line_len(char *s)
{
	size_t	len;

	len = 0;
	while (*s && *s != '\n')
	{
		len++;
		s++;
	}
	return (len);
}

int	**creat_matrix(char *map, size_t xs)
{
	int	**grid;
	int	grid_i;

	grid = malloc((sizeof(char *) * xs) + 1);
	if (!grid)
		return (1);
	grid_i = 0;
	while (grid_i < xs)
	{
		grid[grid_i] = ft_substr(map, 0, get_line_len(map));
		if (!grid[grid_i])
		{
			/**
			 * Need to free the matrix
			 */
			return (NULL);
		}
	}	
}

void	parse_map(t_map *map)
{
	char	*inline_map;
	size_t	xs;
	(void)map;
	inline_map = get_inline_map(map->cub->pr.input_file_fd);
	if (!inline_map)
		ft_perror(map->cub, errno, CRITICAL);
	xs = calc_xs(inline_map);
	exit (1);
}
