/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:14:50 by timmi             #+#    #+#             */
/*   Updated: 2025/11/25 10:42:57 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// static bool	is_tile_valid(int x, int y, char **m)
// {
// 	if (!m[y][x])
// 		return (true);
// 	if (!m[y][x + 1] || m[y][x + 1] == '\n')
// 		return (false);
// 	if (!m[y][x - 1] || m[y][x - 1] == '\n')
// 		return (false);
// 	if (m[y + 1])
// 		if (!m[y + 1][x] || m[y + 1][x] == '\n')
// 		 	return (false);
// 	if (m[y - 1])
// 		if (!m[y - 1][x] || m[y - 1][x] == '\n')
// 			return (false);
// 	return (true);
// }

void	map_validation(t_map *map)
{
	(void)map;
	// size_t	x_i;
	// size_t	y_i;

	// y_i = 0;
	// while (y_i < map->dim[Y])
	// {
	// 	x_i = 0;
	// 	while (x_i < map->dim[X])
	// 	{
	// 		printf("%c", map->grid[y_i][x_i]);
	// 	}
	// 	printf("\n");
	// 	y_i++;
	// }
}