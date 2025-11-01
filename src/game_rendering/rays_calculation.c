/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:13:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/01 19:27:36 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_main_ray(t_rays *r, t_player *p, t_map *m)
{
	get_cos_sin(p);
	init_main_ray_calculation(r, p);
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

bool	get_current_ray(t_rays *r, t_player *p, t_map *m)
{
	get_cos_sin(p);
	init_main_ray_calculation(r, p);
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
	return (true);
}
