/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:42:38 by timmi             #+#    #+#             */
/*   Updated: 2025/12/02 14:08:08 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	update_x_dimension(char *line, size_t *x)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > *x)
		*x = len;
}

static size_t	get_orientation(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N')
			return (i);
		if (line[i] == 'E')
			return (i);
		if (line[i] == 'S')
			return (i);
		if (line[i] == 'W')
			return (i);
		i++;
	}
	return (0);
}

/**
* fetch player position in the line (if it exist)
* and calc if the line is the biggest encountered yet
*/
static void	process_line(t_map *map, char *line)
{
	size_t	orientation;

	orientation = get_orientation(line);
	update_x_dimension(line, &map->dim[X]);
	if (orientation)
	{
		if (map->p_pos == true)
			ft_perror(map->cub, MAP_DUP_START, CRITICAL);
		map->p_pos = true;
		get_start_dir(map, map->cub->plyr.dir,
			&map->cub->plyr.aov, line[orientation]);
		map->plyr_start_pos[X] = orientation;
		map->plyr_start_pos[Y] = map->dim[Y];
	}
}

static char	*get_inline_map(t_map *map, int fd)
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
			break ;
		if (line[0] != '\n')
			map->dim[Y]++;
		process_line(map, line);
		fp = inline_map;
		inline_map = ft_strjoin(inline_map, line);
		w_free((void **)&fp);
		w_free((void **)&line);
		if (!inline_map)
			return (NULL);
	}
	return (inline_map);
}

void	parse_map(t_map *map)
{
	char	*inline_map;

	inline_map = get_inline_map(map, map->cub->pr.input_file_fd);
	if (!inline_map)
		ft_perror(map->cub, 0, CRITICAL);
	if (!is_line_valid(inline_map))
		ft_perror(map->cub, MAP_UNAUTH_CHAR, ERROR);
	map->grid = ft_split(inline_map, '\n');
	w_free((void **)&inline_map);
	if (map->cub->pr.fail)
	{
		free_cub(map->cub);
		exit(EXIT_FAILURE);
	}
	if (!map->grid)
		ft_perror(map->cub, 0, CRITICAL);
	if (!map->grid[0])
		ft_perror(map->cub, MAP_NOT_FOUND, CRITICAL);
	if (!map->p_pos)
		ft_perror(map->cub, MAP_NO_START, CRITICAL);
}
