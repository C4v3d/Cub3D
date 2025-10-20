/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:13:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/20 13:01:02 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	main_ray(t_player *p, t_map *m)
{
	int	x_wall;
	int	y_wall;

	p->r.delta[X] = get_delta(p->dir[X]);
	p->r.delta[Y] = get_delta(p->dir[Y]);
	p->ray_len = 0;
	x_wall = (int)p->pos[X];
	y_wall = (int)p->pos[Y];
	init_steps_dist_next_tile(p, x_wall, y_wall);
	if (!wall_is_on_axis(p, m->grid))
	{
		dda(p, p->cub->map.grid, &x_wall, &y_wall); // DDA gives localisation of the encountered wall
		p->ray_len = calculate_ray_len(p, x_wall, y_wall);
		fprintf(stderr, "main_ray | see wall at grid[Y]%d[X]%d | dist to wall: %lf\n", y_wall, x_wall, p->ray_len);
	}
	fprintf(stderr, "main_ray | p.pos[Y]%lf[X]%lf\n", p->pos[Y], p->pos[X]);
	//fprintf(stderr, "get_main_ray_len | del_dist_x: %lf | del_dist_x: %lf\n", p->r.delta[X], p->r.delta[Y]);
	return (0);
}

int	rays_calculation(t_player *p, t_map *m)
{
	(void)m;
	main_ray(p, m);

	return (0);
}
