/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:14:50 by timmi             #+#    #+#             */
/*   Updated: 2025/11/27 11:07:33 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	is_tile_valid(t_map *m, int x, int y)
{
	printf("Checking :%c\n", m->grid[y][x]);
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
	if (m->grid[y][x + 1] == '\0' || m->grid[y][x + 1] == '\n')
		return (false);
	if (m->grid[y][x - 1] == '\0' || m->grid[y][x - 1] == '\n')
		return (false);
	return (true);
}

void	map_validation(t_map *map)
{
	size_t	x_i;
	size_t	y_i;

	y_i = 0;
	while (y_i < map->dim[Y])
	{
		x_i = 0;
		while (map->grid[y_i][x_i])
		{
			if (map->grid[y_i][x_i] == '0')
				if (!is_tile_valid(map, x_i, y_i))
					ft_perror(map->cub, MAP_OPEN, CRITICAL);
			x_i++;
		}
		y_i++;
	}
}
