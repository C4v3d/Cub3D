/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:42:38 by timmi             #+#    #+#             */
/*   Updated: 2025/10/02 13:07:50 by timmi            ###   ########.fr       */
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

/**
 * CHECK MATRIX
 * STORES A SINGLE INT NOT A STRING
 */
void	parse_map(t_map *map)
{
	char	*inline_map;
	inline_map = get_inline_map(map->cub->pr.input_file_fd);
	if (!inline_map)
		ft_perror(map->cub, errno, CRITICAL);
	map->grid = ft_split(inline_map, '\n');
	if (!map->grid)
		ft_perror(map->cub, errno, CRITICAL);
}
