/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:13:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/02 00:17:35 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_main_ray(t_rays *r, t_player *p, t_map *m)
{
	get_cos_sin(p);
	init_ray_calculation(r, p);
	if (!wall_is_on_axis(r, p, m->grid))
	{
		dda(r, m->grid); // DDA gives localisation of the encountered wall
		p->ray_len = calculate_ray_len(p, r->w_seen[X], r->w_seen[Y]);
	}
	r->w_side = check_w_side(r->w_side, p->pos, r->w_seen, p->aov);
	if (r->w_side == 0 || r->w_side == 1)
		r->p_w_dist = (r->dist[X] - r->delta[X]);
	else
		r->p_w_dist = (r->dist[Y] - r->delta[Y]);
	r->line_h = (int)(WINDOW_HEIGHT / r->p_w_dist);
	return (0);
}

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
		if (r->dist[X] < r->dist[Y])
		{
			r->dist[X] += r->delta[X];
			r->w_seen[X] += r->steps[X];
			r->w_side = 0;
		}
		else
		{
			r->dist[Y] += r->delta[Y];
			r->w_seen[Y] += r->steps[Y];
			r->w_side = 1;
		}
		if (grid[r->w_seen[Y]][r->w_seen[X]] == '1')
			hit = true;
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

