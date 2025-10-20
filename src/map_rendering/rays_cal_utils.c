/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_cal_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:48:05 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/20 10:27:29 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	wall_is_on_axis(t_player *p, char **grid)
{
	int	dist;
	int	x_tmp;
	int	y_tmp;

	x_tmp = p->pos[X];
	y_tmp = p->pos[Y];
	if (p->aov != 0 && p->aov != EA_RAD && p->aov != NO_RAD
			&& p->aov != WE_RAD && p->aov != SO_RAD)
		return (false);
	dist = 0;
	if (p->aov == 0)
		while (grid[y_tmp][++x_tmp] != '1')
			dist++;
	if (p->aov == NO_RAD)
		while (grid[--y_tmp][x_tmp] != '1')
			dist++;
	if (p->aov == WE_RAD)
		while (grid[y_tmp][--x_tmp] != '1')
			dist++;
	if (p->aov == SO_RAD)
		while (grid[++y_tmp][x_tmp] != '1')
			dist++;
	p->ray_len = dist;
	fprintf(stderr, "wall_is_on_axis | see wall at grid[Y]%d[X]%d | dist to wall: %lf\n", y_tmp, x_tmp, p->ray_len);
	return (true);
}

int	calculate_ray_len(t_player *p, int x, int y)
{
	if (p->aov >= Q1_2 && p->aov < Q2_2)
		return (get_hypotenus(p->pos[X] - x, p->pos[Y]) - y);
	else if (p->aov >= Q2_2 && p->aov < Q3_2)
		return (get_hypotenus(x - p->pos[X], y - p->pos[Y]));
	else if (p->aov >= Q3_2 && p->aov <= Q4_2)
		return (get_hypotenus(p->pos[X] - x, y - p->pos[Y]));
	else
		return (get_hypotenus(x - p->pos[X], y - p->pos[Y])); //if (p->aov >= 0 && p->aov < Q1_2)
}

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
		p->r.steps[Y] = 1;
		p->r.dist_next_tile[Y] = (map_y + 1 - p->pos[Y]) * p->r.delta[Y];
	}
	else
	{
		p->r.steps[Y] = -1;
		p->r.dist_next_tile[Y] = (p->pos[Y] - map_y) * p->r.delta[Y];
	}
}
