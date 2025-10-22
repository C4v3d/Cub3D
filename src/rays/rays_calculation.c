/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:13:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/22 15:15:32 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	main_ray(t_player *p, t_map *m)
{
	int	x_wall;
	int	y_wall;

	init_main_ray_calculation(p, &x_wall, &y_wall);
	if (!wall_is_on_axis(p, m->grid))
	{
		dda(p, p->cub->map.grid, &x_wall, &y_wall); // DDA gives localisation of the encountered wall
		p->ray_len = calculate_ray_len(p, x_wall, y_wall);
		fprintf(stderr, "%smain_ray........| see wall grid[Y]%d[X]%d | dist: %lf%s\n", BLU, y_wall, x_wall, p->ray_len, RESET);
	}
	return (0);
}

int	rays_calculation(t_player *p, t_map *m)
{
	(void)m;
	main_ray(p, m);

	return (0);
}
