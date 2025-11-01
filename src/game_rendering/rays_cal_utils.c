/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_cal_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:48:05 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/01 18:35:24 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_w_side(int side, double *p_pos, int *w_pos, double aov)
{
	if ((side == 1 && (int)p_pos[Y] > w_pos[Y])
		|| (side == -1 && aov == NO_RAD))
		return (NO);
	else if ((side == 1 && (int)p_pos[Y] < w_pos[Y])
		|| (side == -1 && aov == SO_RAD))
		return (SO);
	if ((side == 0 && (int)p_pos[X] > w_pos[X])
		|| (side == -1 && aov == WE_RAD))
		return (WE);
	else if ((side == 0 && (int)p_pos[X] < w_pos[X])
		|| (side == -1 && aov == EA_RAD))
		return (EA);
	return (-1);
}

bool	wall_is_on_axis(t_rays *r, t_player *p, char **grid)
{
	if (!(p->aov == 0 || p->aov == EA_RAD || p->aov == NO_RAD
			|| p->aov == WE_RAD || p->aov == SO_RAD))
		return (false);
	r->w_seen[X] = p->pos[X];
	r->w_seen[Y] = p->pos[Y];
	if (p->aov == 0)
		while (grid[r->w_seen[Y]][++r->w_seen[X]] != '1')
			p->ray_len++;
	if (p->aov == NO_RAD)
		while (grid[--r->w_seen[Y]][r->w_seen[X]] != '1')
			p->ray_len++;
	if (p->aov == WE_RAD)
		while (grid[r->w_seen[Y]][--r->w_seen[X]] != '1')
			p->ray_len++;
	if (p->aov == SO_RAD)
		while (grid[++r->w_seen[Y]][r->w_seen[X]] != '1')
			p->ray_len++;
	p->ray_len++;
	if (p->aov == 0 || p->aov == WE_RAD)
		p->ray_len += p->tile_pos[X];
	if (p->aov == NO_RAD || p->aov == SO_RAD)
		p->ray_len += p->tile_pos[Y];
	return (true);
}

void	dda(t_rays *r, char **grid)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		if (r->dist_next_tile[X] < r->dist_next_tile[Y])
		{
			r->dist_next_tile[X] += r->delta[X];
			r->w_seen[X] += r->steps[X];
			r->w_side = 0;
		}
		else
		{
			r->dist_next_tile[Y] += r->delta[Y];
			r->w_seen[Y] += r->steps[Y];
			r->w_side = 1;
		}
		if (grid[r->w_seen[Y]][r->w_seen[X]] == '1')
			hit = true;
	}
}

void	init_main_ray_calculation(t_rays *r, t_player *p)
{
	r->delta[X] = get_delta(p->dir[X]);
	r->delta[Y] = get_delta(p->dir[Y]);
	r->w_seen[X] = p->pos[X];
	r->w_seen[Y] = p->pos[Y];
	r->w_side = -1;
	if (p->dir[X] < 0)
	{
		r->steps[X] = -1;
		r->dist_next_tile[X] = (p->pos[X] - r->w_seen[X]) * r->delta[X];
	}
	else
	{
		r->steps[X] = 1;
		r->dist_next_tile[X] = (r->w_seen[X] + 1 - p->pos[X]) * r->delta[X];
	}
	if (p->dir[Y] < 0)
	{
		r->steps[Y] = 1;
		r->dist_next_tile[Y] = (r->w_seen[Y] + 1 - p->pos[Y]) * r->delta[Y];
	}
	else
	{
		r->steps[Y] = -1;
		r->dist_next_tile[Y] = (p->pos[Y] - r->w_seen[Y]) * r->delta[Y];
	}
}

double	calculate_ray_len(t_player *p, double x, double y)	// USELESS???
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
