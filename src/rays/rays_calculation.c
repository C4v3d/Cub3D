/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:13:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/26 16:47:35 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_w_side(int side, double *p_pos, int *w_pos, double aov)
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

static int	main_ray(t_player *p, t_map *m)
{
	init_main_ray_calculation(p);
	if (!wall_is_on_axis(p, m->grid))
	{
		dda(p, p->cub->map.grid); // DDA gives localisation of the encountered wall
		p->ray_len = calculate_ray_len(p, p->r.w_seen[X], p->r.w_seen[Y]);
	}
	p->r.w_side = check_w_side(p->r.w_side, p->pos, p->r.w_seen, p->aov);
	if (p->r.w_side == 0 || p->r.w_side == 1)
		p->r.p_w_dist = (p->r.dist_next_tile[X] - p->r.delta[X]);
	else
		p->r.p_w_dist = (p->r.dist_next_tile[Y] - p->r.delta[Y]);
	return (0);
}

int	rays_calculation(t_player *p, t_map *m)
{
	(void)m;
	main_ray(p, m);
	return (0);
}
