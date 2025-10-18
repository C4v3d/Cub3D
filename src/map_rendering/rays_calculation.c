/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:13:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/18 12:18:02 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	main_ray(t_player *p, t_map *m)
{
	(void)m;
	int	map_x;
	int	map_y;

	map_x = (int)p->pos[X];
	map_y = (int)p->pos[Y];
	p->r.delta[X] = get_delta(p->dir[X]);
	p->r.delta[Y] = get_delta(p->dir[Y]);
	init_steps_dist_next_tile(p, map_x, map_y);
	if (!wall_is_on_axis(p, p->cub->map.grid, &map_x, &map_y))
		dda(p, p->cub->map.grid, &map_x, &map_y); // DDA gives localisation of the encountered wall
	p->ray_len = calculate_ray_len(p, map_x, map_y);
	fprintf(stderr, "main_ray | see wall at grid[Y]%d[X]%d | dist to wall: %lf\n", map_y, map_x, p->ray_len);
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
