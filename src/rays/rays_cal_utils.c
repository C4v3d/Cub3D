/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_cal_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:48:05 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/26 14:55:40 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	wall_is_on_axis(t_player *p, char **grid)
{
	if (!(p->aov == 0 || p->aov == EA_RAD || p->aov == NO_RAD
			|| p->aov == WE_RAD || p->aov == SO_RAD))
		return (false);
	p->r.w_seen[X] = p->pos[X];
	p->r.w_seen[Y] = p->pos[Y];
	if (p->aov == 0)
		while (grid[p->r.w_seen[Y]][++p->r.w_seen[X]] != '1')
			p->ray_len++;
	if (p->aov == NO_RAD)
		while (grid[--p->r.w_seen[Y]][p->r.w_seen[X]] != '1')
			p->ray_len++;
	if (p->aov == WE_RAD)
		while (grid[p->r.w_seen[Y]][--p->r.w_seen[X]] != '1')
			p->ray_len++;
	if (p->aov == SO_RAD)
		while (grid[++p->r.w_seen[Y]][p->r.w_seen[X]] != '1')
			p->ray_len++;
	p->ray_len++;
	if (p->aov == 0 || p->aov == WE_RAD)
		p->ray_len += p->tile_pos[X];
	if (p->aov == NO_RAD || p->aov == SO_RAD)
		p->ray_len += p->tile_pos[Y];
	return (true);
}

double	calculate_ray_len(t_player *p, double x, double y)
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

void	dda(t_player *p, char **grid)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		if (p->r.dist_next_tile[X] < p->r.dist_next_tile[Y])
		{
			p->r.dist_next_tile[X] += p->r.delta[X];
			p->r.w_seen[X] += p->r.steps[X];
			p->r.w_side = 0;
		}
		else
		{
			p->r.dist_next_tile[Y] += p->r.delta[Y];
			p->r.w_seen[Y] += p->r.steps[Y];
			p->r.w_side = 1;
		}
		if (grid[p->r.w_seen[Y]][p->r.w_seen[X]] == '1')
			hit = true;
	}
}



//v1
void	init_main_ray_calculation(t_player *p)
{
	p->r.delta[X] = get_delta(p->dir[X]);
	p->r.delta[Y] = get_delta(p->dir[Y]);
	p->r.w_seen[X] = p->pos[X];
	p->r.w_seen[Y] = p->pos[Y];
	p->r.w_side = -1;
	if (p->dir[X] < 0)
	{
		p->r.steps[X] = -1;
		p->r.dist_next_tile[X] = (p->pos[X] - p->r.w_seen[X]) * p->r.delta[X];
	}
	else
	{
		p->r.steps[X] = 1;
		p->r.dist_next_tile[X] = (p->r.w_seen[X] + 1 - p->pos[X]) * p->r.delta[X];
	}
	if (p->dir[Y] < 0)
	{
		p->r.steps[Y] = 1;
		p->r.dist_next_tile[Y] = (p->r.w_seen[Y] + 1 - p->pos[Y]) * p->r.delta[Y];
	}
	else
	{
		p->r.steps[Y] = -1;
		p->r.dist_next_tile[Y] = (p->pos[Y] - p->r.w_seen[Y]) * p->r.delta[Y];
	}
}
