/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:13:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/16 16:15:10 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	dda(t_player *p, char **grid, int x, int y)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		if (p->r.nxt[X] < p->r.nxt[Y])
		{
			p->r.nxt[X] += p->r.del[X];
			x += p->r.stp[X];
		}
		else
		{
			p->r.nxt[Y] += p->r.del[Y];
			y += p->r.stp[Y];
		}
		if (grid[y][x] == '1')
			hit = true;
	}
	fprintf(stderr, "dda | player see wall at map.grid[X]: %d | map.grid[Y]: %d\n", x, y);
}

void	init_stp_nxt(t_player *p, int map_x, int map_y)
{
	if (p->dir[X] < 0)
	{
		p->r.stp[X] = -1;
		p->r.nxt[X] = (p->pos[X] - map_x) * p->r.del[X];
	}
	else
	{
		p->r.stp[X] = 1;
		p->r.nxt[X] = (map_x + 1 - p->pos[X]) * p->r.del[X];
	}
	if (p->dir[Y] < 0)
	{
		p->r.stp[Y] = -1;
		p->r.nxt[Y] = (p->pos[Y] - map_y) * p->r.del[Y];
	}
	else
	{
		p->r.stp[Y] = 1;
		p->r.nxt[Y] = (map_y + 1 - p->pos[Y]) * p->r.del[Y];
	}
}

static int	main_ray(t_player *p, t_map *m)
{
	(void)m;
	int	map_x;
	int	map_y;

	map_x = (int)p->pos[X];
	map_y = (int)p->pos[Y];
	p->r.del[X] = get_delta(p->dir[X]);
	p->r.del[Y] = get_delta(p->dir[Y]);
	init_stp_nxt(p, map_x, map_y);
	dda(p, p->cub->map.grid, map_x, map_y);
	fprintf(stderr, "get_main_ray_len | del_dist_x: %lf | del_dist_x: %lf\n", p->r.del[X], p->r.del[Y]);
	return (0);
}

int	rays_calculation(t_player *p, t_map *m)
{
	(void)m;
	//double	f_pos_x;
	//double	f_pos_y;
	//double	hyp;
	//float	quadrant;

	//quadrant = get_quadrant(p->aov);
	//hyp += get_hypotenus(f_pos_x, f_pos_y);
	//hyp = 0.0;
	//f_pos_x = extract_double(p->pos[X]);
	//f_pos_y = extract_double(p->pos[Y]);
	//fprintf(stderr, "get_main_ray_len | pos[X]: %lf | pos[Y]:%lf | dir[X]: %lf | dir[Y]:%lf\n", p->pos[X], p->pos[Y], p->dir[X], p->dir[Y]);
	//fprintf(stderr, "get_main_ray_len | quadrant: %f | f_pos_x: %lf | f_pos_y:%lf | hyp: %lf | \n", quadrant, f_pos_x, f_pos_y, hyp);

	main_ray(p, m);

	return (0);
}
