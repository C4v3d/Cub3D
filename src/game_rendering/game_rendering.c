/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:36:11 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/02 00:16:31 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_background(t_main *cub, t_image *img)
{
	size_t	pos[AXIS];

	pos[X] = 0;
	pos[Y] = 0;
	paint(img, cub->dspl.win_dim, pos, cub->gfx.colors[1]->color);
	pos[X] = WINDOW_WIDTH / 2;
	pos[Y] = WINDOW_HEIGHT / 2;
	paint(img, cub->dspl.win_dim, pos, cub->gfx.colors[0]->color);
}




void	draw_line(t_main *cub, t_rays *r, t_image *img, int x)
{
	int	col1 = 0xFDE8F8;
	int	col2 = 0xFAC5ED;
	int	col3 = 0xF693DD;
	int	col0 = 0xF269D0;
	(void)cub;

	int	start;
	int	end;

	start = -r->line_h / 2 + WINDOW_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = r->line_h / 2 + WINDOW_HEIGHT / 2;
	if (end >= WINDOW_HEIGHT)
		end = WINDOW_HEIGHT - 1;
	if (r->w_side == 1)
		paint_line(img, x, start, end, col1);
	if (r->w_side == 2)
		paint_line(img, x, start, end, col2);
	if (r->w_side == 3)
		paint_line(img, x, start, end, col3);
	if (r->w_side == 0)
		paint_line(img, x, start, end, col0);
}

void	init_ray_calculation(t_rays *r, t_player *p)
{
	r->delta[X] = get_delta(p->dir[X]);
	r->delta[Y] = get_delta(p->dir[Y]);
	r->w_seen[X] = (int)p->pos[X];
	r->w_seen[Y] = (int)p->pos[Y];
	r->w_side = -1;
	if (p->dir[X] < 0)
	{
		r->steps[X] = -1;
		r->dist[X] = (p->pos[X] - r->w_seen[X]) * r->delta[X];
	}
	else
	{
		r->steps[X] = 1;
		r->dist[X] = (r->w_seen[X] + 1.0 - p->pos[X]) * r->delta[X];
	}
	if (p->dir[Y] < 0)
	{
		r->steps[Y] = 1;
		r->dist[Y] = (r->w_seen[Y] + 1.0 - p->pos[Y]) * r->delta[Y];
	}
	else
	{
		r->steps[Y] = -1;
		r->dist[Y] = (p->pos[Y] - r->w_seen[Y]) * r->delta[Y];
	}
}

static void	init_draw_scene(t_rays *r, t_player *p, size_t x)
{
	//get_cos_sin(p);
	init_ray_calculation(r, p);
	r->cam_x = 2 * x / (double)WINDOW_WIDTH - 1;
	r->dir[X] = p->dir[X] + r->plane[X] * r->cam_x;
	r->dir[Y] = p->dir[Y] + r->plane[Y] * r->cam_x;
	r->w_seen[X] = (int)p->pos[X];
	r->w_seen[Y] = (int)p->pos[Y];
}

int		draw_scene(t_main *cub, t_rays *r, t_player *p, t_image *img)
{
	size_t	x;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		init_draw_scene(r, p, x);
		//if (!wall_is_on_axis(r, p, cub->map.grid))
		dda(r, cub->map.grid); // DDA gives localisation of the encountered wall
		r->w_side = check_w_side(r->w_side, p->pos, r->w_seen, p->aov);
		if (r->w_side == 0 || r->w_side == 1)
			r->p_w_dist = (r->dist[X] - r->delta[X]);
		else
			r->p_w_dist = (r->dist[Y] - r->delta[Y]);
		r->line_h = (int)(WINDOW_HEIGHT / r->p_w_dist);
		draw_line(cub, r, img, x);
	}
	//get_current_ray(&cub->r, &cub->plyr, &cub->map);
	return (0);
}
