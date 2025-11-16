/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_cal_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:05:16 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/16 18:11:25 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_ray_calculation(t_rays *r, t_player *p)
{
	if (r->dir[X] < 0)
	{
		r->steps[X] = -1;
		r->dist[X] = (p->pos[X] - r->map[X]) * r->delta[X];
	}
	else
	{
		r->steps[X] = 1;
		r->dist[X] = (r->map[X] + 1.0 - p->pos[X]) * r->delta[X];
	}
	if (r->dir[Y] < 0)
	{
		r->steps[Y] = 1;
		r->dist[Y] = (r->map[Y] + 1.0 - p->pos[Y]) * r->delta[Y];
	}
	else
	{
		r->steps[Y] = -1;
		r->dist[Y] = (p->pos[Y] - r->map[Y]) * r->delta[Y];
	}
}

void	init_dda(t_rays *r, t_player *p, int x)
{
	r->cam_x = 2 * (double)x / (double)WINDOW_WIDTH - 1;
	r->dir[X] = p->dir[X] + r->plane[X] * r->cam_x;
	r->dir[Y] = p->dir[Y] + r->plane[Y] * r->cam_x;
	//if (x == WINDOW_WIDTH / 2 && p->aov == EA_RAD || p->aov == NO_RAD
	//	|| p->aov == WE_RAD || p->aov == SO_RAD)
	if (x == WINDOW_WIDTH / 2)
	{
		r->dir[X] += 0.000001; //fix temporaire (ou def?) pour les visions en ligne droite
		r->dir[Y] += 0.000001; //fix temporaire (ou def?) pour les visions en ligne droite
	}
	r->map[X] = (int)p->pos[X];
	r->map[Y] = (int)p->pos[Y];
	r->delta[X] = get_delta(r->dir[X]);
	r->delta[Y] = get_delta(r->dir[Y]);
	r->wall_side = -1;
	init_ray_calculation(r, p);
}
