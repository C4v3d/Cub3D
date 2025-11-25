/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:36:11 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/25 17:44:11 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_texture_color(t_image *t, int x, int y)
{
	char	*pixel;

	if (x < 0)
		x = 0;
	if (x >= t->width)
		x = t->width - 1;
	if (y < 0)
		y = 0;
	if (y >= t->height)
		y = t->height - 1;
	pixel = t->addr + (y * t->s_line + x * (t->bpp / 8));
	return (*(int *)pixel);
}

static void	draw_texture(t_draw *d, t_image *t, t_image *scene, int x)
{
	int	y;
	int	color;

	y = d->start - 1;
	while (++y <= d->end)
	{
		d->y = (int)d->pos & (t->height - 1);
		d->pos += d->step;
		color = get_texture_color(t, d->x, d->y);
		put_p(scene, x, y, color);
	}
}

static void	init_draw(t_main *cub, t_rays *r, t_draw *d, t_player *p)
{
	d->num = check_wall_side(p, &cub->map, r->wall_side, r->map);
	if (r->wall_side == 0)
		d->wall_x = p->pos[Y] - r->wall_dist * r->dir[Y];
	else
		d->wall_x = p->pos[X] + r->wall_dist * r->dir[X];
	d->wall_x -= floor(d->wall_x);
	d->x = (int)(d->wall_x * (double)cub->gfx.txtr[d->num].width);
	d->step = 1.0 * cub->gfx.txtr[d->num].height / r->wall_height;
	d->pos = (d->start - WINDOW_HEIGHT / 2 + r->wall_height / 2) * d->step;
}

static void	init_dist_height(t_rays *r, t_draw *d)
{
	if (r->wall_side == 0)
		r->wall_dist = (r->dist[X] - r->delta[X]);
	else
		r->wall_dist = (r->dist[Y] - r->delta[Y]);
	r->wall_height = (int)(WINDOW_HEIGHT / r->wall_dist);
	d->start = -r->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (d->start < 0)
		d->start = 0;
	d->end = r->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (d->end >= WINDOW_HEIGHT)
		d->end = WINDOW_HEIGHT - 1;
}

void	draw_scene(t_main *cub, t_graphic *gfx, t_rays *r, t_player *p)
{
	t_draw	d;
	int		x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		init_dda(r, p, x);
		dda(r, cub->map.grid);
		init_dist_height(r, &d);
		init_draw(cub, r, &d, p);
		draw_texture(&d, &gfx->txtr[d.num], &gfx->scene, x);
		x++;
	}
}
