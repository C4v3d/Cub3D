/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:14:50 by timmi             #+#    #+#             */
/*   Updated: 2025/11/25 13:46:29 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	is_tile_valid(t_map *m, int x, int y)
{
	if (y == 0) /* If a Zero is present on the first line -> No line above can close the map*/
		return (false);
	else if (m->grid[y - 1][x] == '\0' || m->grid[y - 1][x] == ' ' || m->grid[y - 1][x] == '\n')
		return (false);
	if (y == (int)m->dim[Y] - 1)
		return (false);
	else if (m->grid[y + 1][x] == '\0' || m->grid[y + 1][x] == ' ' || m->grid[y + 1][x] == '\n')
		return (false);	
	if (m->grid[y][x + 1] == '\0' || m->grid[y][x + 1] == '\n')
		return (false);
	if (m->grid[y][ x - 1] == '\0' || m->grid[y][x - 1] == '\n')
		return (false);
	return (true);
}

void	map_validation(t_map *map)
{
	size_t	x_i;
	size_t	y_i;

	y_i = 0;
	log_map(map->cub);
	printf("\n");
	while (y_i < map->dim[Y])
	{
		x_i = 0;
		while (map->grid[y_i][x_i])
		{
			if (map->grid[y_i][x_i] == '0')
			{
				if (!is_tile_valid(map, x_i, y_i))
				{
					printf("map is open on x:%ld y:%ld\nWith char %c\n", x_i, y_i, map->grid[y_i][x_i]);
					exit(1);
				}	
			}
		x_i++;
		}
		y_i++;
	}
}