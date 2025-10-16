/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:13:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/16 18:44:37 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	dda(t_player *p, char **grid, int *x, int *y)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		if (p->r.dist_next_tile[X] < p->r.dist_next_tile[Y])
		{
			p->r.dist_next_tile[X] += p->r.delta[X];
			(*x) += p->r.steps[X];
		}
		else
		{
			p->r.dist_next_tile[Y] += p->r.delta[Y];
			(*y) += p->r.steps[Y];
		}
		if (grid[(*y)][(*x)] == '1')
			hit = true;
	}
}

void	init_steps_dist_next_tile(t_player *p, int map_x, int map_y)
{
	if (p->dir[X] < 0)
	{
		p->r.steps[X] = -1;
		p->r.dist_next_tile[X] = (p->pos[X] - map_x) * p->r.delta[X];
	}
	else
	{
		p->r.steps[X] = 1;
		p->r.dist_next_tile[X] = (map_x + 1 - p->pos[X]) * p->r.delta[X];
	}
	if (p->dir[Y] < 0)
	{
		p->r.steps[Y] = -1;
		p->r.dist_next_tile[Y] = (p->pos[Y] - map_y) * p->r.delta[Y];
	}
	else
	{
		p->r.steps[Y] = 1;
		p->r.dist_next_tile[Y] = (map_y + 1 - p->pos[Y]) * p->r.delta[Y];
	}
}

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
	dda(p, p->cub->map.grid, &map_x, &map_y);
	p->ray_len = get_hypotenus(map_x, map_y);
	fprintf(stderr, "dda | see wall at grid[Y]%d|[X]%d | distance to wall: %lf\n", map_y, map_x, p->ray_len);
	//fprintf(stderr, "get_main_ray_len | del_dist_x: %lf | del_dist_x: %lf\n", p->r.delta[X], p->r.delta[Y]);
	return (0);
}

int	rays_calculation(t_player *p, t_map *m)
{
	(void)m;
	main_ray(p, m);

	return (0);
}
