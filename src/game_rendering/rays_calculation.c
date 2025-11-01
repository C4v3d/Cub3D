/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:13:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/01 18:12:53 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_main_ray(t_player *p, t_map *m)
{
	get_cos_sin(p);
	init_main_ray_calculation(p);
	if (!wall_is_on_axis(p, m->grid))
	{
		dda(p, m->grid); // DDA gives localisation of the encountered wall
		p->ray_len = calculate_ray_len(p, p->r.w_seen[X], p->r.w_seen[Y]);
	}
	p->r.w_side = check_w_side(p->r.w_side, p->pos, p->r.w_seen, p->aov);
	if (p->r.w_side == 0 || p->r.w_side == 1)
		p->r.p_w_dist = (p->r.dist_next_tile[X] - p->r.delta[X]);
	else
		p->r.p_w_dist = (p->r.dist_next_tile[Y] - p->r.delta[Y]);
	p->r.line_h = (int)(WINDOW_HEIGHT / p->r.p_w_dist);
	return (0);
}

bool	get_current_ray(t_player *p, t_map *m)
{

	(void)p;
	(void)m;
	//main_ray(p, m);
	return (true);
}
