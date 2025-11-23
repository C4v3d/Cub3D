/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:14:50 by timmi             #+#    #+#             */
/*   Updated: 2025/11/23 18:55:33 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	is_tile_valid(int x, int y, char **m)
{
	if (!m[y][x])
		return (true);
	if (!m[y][x + 1] || m[y][x + 1] == '\n')
		return (false);
	if (!m[y][x - 1] || m[y][x - 1] == '\n')
		return (false);
	if (m[y + 1])
		if (!m[y + 1][x] || m[y + 1][x] == '\n')
		 	return (false);
	if (m[y - 1])
		if (!m[y - 1][x] || m[y - 1][x] == '\n')
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
		printf("y :%c\n", map->grid[y_i][x_i]);
		while (x_i < map->dim[X])
		{
			if  (map->grid[y_i][x_i] != '\n')
			{
				printf("%c", map->grid[y_i][x_i]);
				if (map->grid[y_i][x_i] != '1')
					if (is_tile_valid(x_i, y_i, map->grid) == false)
						exit(1); // ft_perror();
			}
			x_i++;
		}
		printf("\n");
		y_i++;
	}
}