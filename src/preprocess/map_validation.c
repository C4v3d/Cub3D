/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:14:50 by timmi             #+#    #+#             */
/*   Updated: 2025/11/27 15:03:37 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	y_check(t_map *m, int x, int y)
{
	if (y == 0)
		return (false);
	else if (m->grid[y - 1][x] == '\0'
		|| m->grid[y - 1][x] == ' ' || m->grid[y - 1][x] == '\n')
			return (false);
	if (y == (int)m->dim[Y] - 1)
		return (false);
	else if (m->grid[y + 1][x] == '\0' || m->grid[y + 1][x] == ' '
		|| m->grid[y + 1][x] == '\n')
		return (false);
	return (true);
}

static bool	x_check(t_map *m, int x, int y)
{
	if (x == 0)
		return (false);
	else if (m->grid[y][x - 1] == '\0'
		|| m->grid[y][x - 1] == ' ' || m->grid[y][x - 1] == '\n')
		return (false);
	if (x == (int)ft_strlen(m->grid[y]))
		return (false);
	else if (m->grid[y][x + 1] == '\0'
		|| m->grid[y][x + 1] == ' ' || m->grid[y][x + 1] == '\n')
		return (false);
	return (true);
}

static inline bool	is_tile_valid(t_map *m, int x, int y)
{
	return (y_check(m, x, y) && x_check(m, x, y));
}

void	map_validation(t_map *map)
{
	size_t	x_i;
	size_t	y_i;

	log_map(map->cub);
	y_i = 0;
	while (y_i < map->dim[Y])
	{
		x_i = 0;
		while (map->grid[y_i][x_i])
		{
			if (map->grid[y_i][x_i] != '1' && map->grid[y_i][x_i] != ' ')
				if (!is_tile_valid(map, x_i, y_i))
				{
					printf("x :%ld\ny :%ld\n", x_i, y_i);
					printf("char: %c\n", map->grid[y_i][x_i]);
					exit (ft_perror(map->cub, MAP_OPEN, WARNING));
				}
			x_i++;
		}
		y_i++;
	}
}
