/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_cal_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:48:05 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/17 18:05:37 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	calculate_ray_len(t_player *p, int x, int y)
{
	if (p->aov >= 0 && p->aov < Q1_2)
		return (get_hypotenus(p->pos[X] - x, y - p->pos[Y]));
	if (p->aov >= Q1_2 && p->aov < Q2_2)
		return (get_hypotenus(p->pos[X] - x, p->pos[Y]) - y);
	if (p->aov >= Q2_2 && p->aov < Q3_2)
		return (get_hypotenus(x - p->pos[X], p->pos[Y]) - y);
	//if (p->aov >= Q3_2 && p->aov < Q4_2)
	else
		return (get_hypotenus(x - p->pos[X], y - p->pos[Y]));
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
