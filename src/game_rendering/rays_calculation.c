/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:13:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/03 11:28:24 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_main_ray(t_rays *r, t_player *p, t_map *m)
{
	init_dda(r, p, WINDOW_WIDTH / 2);
	if (!wall_is_on_axis(r, p, m->grid))
		dda(r, m->grid); // DDA gives localisation of the encountered wall
	r->w_side = check_w_side(r->w_side, p->pos, r->map, p->aov);
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
	r->map[X] = p->pos[X];
	r->map[Y] = p->pos[Y];
	if (p->aov == NO_RAD)
		while (grid[--r->map[Y]][r->map[X]] != '1')
			r->dist[Y]++;
	else if (p->aov == WE_RAD)
		while (grid[r->map[Y]][--r->map[X]] != '1')
			r->dist[X]++;
	else if (p->aov == SO_RAD)
		while (grid[++r->map[Y]][r->map[X]] != '1')
			r->dist[Y]++;
	else
		while (grid[r->map[Y]][++r->map[X]] != '1')
			r->dist[X]++;
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
			r->map[X] += r->steps[X];
			r->w_side = 0;
		}
		else
		{
			r->dist[Y] += r->delta[Y];
			r->map[Y] += r->steps[Y];
			r->w_side = 1;
		}
		if (grid[r->map[Y]][r->map[X]] == '1')
		{
			hit = true;
			//fprintf(stderr, "dda | HIT WALL! map[Y]: %d [X]:%d\n", r->map[Y], r->map[X]);
		}
	}
}
