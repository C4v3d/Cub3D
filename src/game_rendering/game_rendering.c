/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:36:11 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/14 14:33:20 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_background(t_main *cub, t_image *img)
{
	(void)cub;
	size_t	pos[AXIS];
	size_t	dim[AXIS];

	pos[X] = 0;
	pos[Y] = 0;
	dim[X] = 1280;
	dim[Y] = WINDOW_HEIGHT / 2;
	//draw(img, dim, pos, cub->gfx.colors[1]->color);	//❌ BUG avec cub->gfx.colors[]->color
	draw(img, dim, pos, 0xA8FFFA);
	pos[Y] = WINDOW_HEIGHT / 2;
	dim[Y] = WINDOW_HEIGHT;
	//draw(img, dim, pos, cub->gfx.colors[0]->color);	//❌ BUG avec cub->gfx.colors[]->color
	draw(img, dim, pos, 0xC2FFA8);
}

//❌ untextured
static void	draw_untextured_line(t_image *img, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y <= end)
		my_mlx_pixel_put(img, x, y++, color);
}

static void	draw_textured_line(t_main *cub, t_image *img, t_image *t, int x)
{
	int	y;

	y = cub->r.tex_st - 1;
	while (++y <= cub->r.tex_nd)
		my_mlx_pixel_put(img, x, y, t->addr[y * t->width + x]);
	//fprintf(stderr, "draw_textured | t->addr: %p | &t->add[10]: %s | bpp: %d | s_line: %d\n", t->addr, &t->addr[10], t->bpp, t->s_line);
}

static void	draw_texture(t_main *cub, t_rays *r, t_image *img, int x)
{
	// ⚠️ CURRENTLY NOT WORKING ⚠️
	if (r->wall_side == NO)
		draw_textured_line(cub, img, &cub->gfx.txtr[r->tex_num], x);
	//else if (r->wall_side == SO)
	//	draw_textured_line(cub, img, &cub->gfx.txtr[SO], x);
	//else if (r->wall_side == EA)
	//	draw_textured_line(cub, img, &cub->gfx.txtr[EA], x);
	//else
	//	draw_textured_line(cub, img, &cub->gfx.txtr[WE], x);
	// ⚠️ CURRENTLY NOT WORKING ⚠️
	else if (r->wall_side == SO)
		draw_untextured_line(img, x, r->tex_st, r->tex_nd, 0xFDE8F8);
	else if (r->wall_side == EA)
		draw_untextured_line(img, x, r->tex_st, r->tex_nd, 0xF693DD);
	else
		draw_untextured_line(img, x, r->tex_st, r->tex_nd, 0xEE3FC2);
}

//v2 must adapt loading image to workm with a buffer
//static void	init_draw(t_rays *r, t_player *p)
//{
//	// DIST AND WALL SIZE CALCULATION.........................
//	if (r->wall_side == 0)
//		r->wall_dist = (r->dist[X] - r->delta[X]);
//	else
//		r->wall_dist = (r->dist[Y] - r->delta[Y]);
//	r->wall_height = (int)(WINDOW_HEIGHT / r->wall_dist);
//	r->tex_st = -r->wall_height / 2 + WINDOW_HEIGHT / 2 + r->pitch;
//	if (r->tex_st < 0)
//	r->tex_st = 0;
//	r->tex_nd = r->wall_height / 2 + WINDOW_HEIGHT / 2 + r->pitch;
//	if (r->tex_nd >= WINDOW_HEIGHT)
//	r->tex_nd = WINDOW_HEIGHT - 1;
//	r->tex_num = check_wall_side(r->wall_side, p->pos, r->map, p->aov);
//	if (r->wall_side == 0)	// calculate exaclty where the wall was hit
//		r->wall_x = p->pos[Y] + r->wall_dist * r->dir[Y];
//	else
//		r->wall_x = p->pos[X] + r->wall_dist * r->dir[X];
//	r->wall_x -= floor(r->wall_x);
//	r->wall_side = check_wall_side(r->wall_side, p->pos, r->map, p->aov);
//	// TEXTURE CALCULATION....................................
//	//r->tex_x = (int)(r->wall_x * (double)r->cub->gfx.txtr_res);
//	//if (r->wall_side == 0 && r->dir[X] > 0)	// mirroring textures
//	//	r->tex_x = r->cub->gfx.txtr_res - r->tex_x - 1;
//	//if (r->wall_side == 1 && r->dir[Y] < 0)
//	//	r->tex_x = r->cub->gfx.txtr_res - r->tex_x - 1;
//	//r->step = 1.0 * r->cub->gfx.txtr_res / r->wall_height;
//	//r->tex_pos = (r->tex_st - r->pitch - WINDOW_HEIGHT / 2 + r->wall_height / 2) * r->step;
//}

//v1
static void	init_draw(t_rays *r, t_player *p)
{
	if (r->wall_side == 0)
		r->wall_dist = (r->dist[X] - r->delta[X]);
	else
		r->wall_dist = (r->dist[Y] - r->delta[Y]);
	r->wall_height = (int)(WINDOW_HEIGHT / r->wall_dist);
	r->wall_side = check_wall_side(r->wall_side, p->pos, r->map, p->aov);
	r->tex_st = -r->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (r->tex_st < 0)
		r->tex_st = 0;
	r->tex_nd = r->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (r->tex_nd >= WINDOW_HEIGHT)
		r->tex_nd = WINDOW_HEIGHT - 1;
}

int		draw_scene(t_main *cub, t_rays *r, t_player *p, t_image *img)
{
	int	x;

	x = -1;
	while (++x <= WINDOW_WIDTH)
	{
		init_dda(r, p, x);
		dda(r, cub->map.grid);	//❌ calcul des distances pour les visions en ligne droite fixé dans init_dda
		init_draw(r, p);
		draw_texture(cub, r, img, x);
	}
	return (0);
}
