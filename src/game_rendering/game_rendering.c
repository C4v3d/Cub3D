/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:36:11 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/13 20:04:34 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//❌ untextured
//static void	draw_untextured_line(t_image *img, int x, int start, int end, int col)
//{
//	int	y_i;

//	y_i = start;
//	while (y_i <= end)
//		my_mlx_pixel_put(img, x, y_i++, col);
//}

////❌ untextured
//static void	draw_untextured(t_main *cub, t_rays *r, t_image *img, int x)
//{
//	int	col1 = 0xFDE8F8;
//	int	col2 = 0xF693DD;
//	int	col3 = 0xEE3FC2;
//	int	col0 = 0xC01194;
//	(void)cub;

//	int	start;
//	int	end;

//	start = -r->wall_height / 2 + WINDOW_HEIGHT / 2;
//	if (start < 0)
//		start = 0;
//	end = r->wall_height / 2 + WINDOW_HEIGHT / 2;
//	if (end >= WINDOW_HEIGHT)
//		end = WINDOW_HEIGHT - 1;
//	if (r->wall_side == 0)
//		draw_untextured_line(img, x, start, end, col0);
//	else if (r->wall_side == 2)
//		draw_untextured_line(img, x, start, end, col2);
//	else if (r->wall_side == 3)
//		draw_untextured_line(img, x, start, end, col3);
//	else
//		draw_untextured_line(img, x, start, end, col1);
//}

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

static void	draw_textured_line(t_main *cub, t_image *img, t_image *t, int x)
{
	int	y_i;

	y_i = cub->gfx.start - 1;
	while (++y_i <= cub->gfx.end)
		my_mlx_pixel_put(img, x, y_i, t->addr[y_i * t->width + x]);
}

static void	draw_texture(t_main *cub, t_rays *r, t_image *img, int x)
{
	if (r->wall_side == NO)
		draw_textured_line(cub, img, &cub->gfx.txtr[NO], x);
	else if (r->wall_side == SO)
		draw_textured_line(cub, img, &cub->gfx.txtr[SO], x);
	else if (r->wall_side == EA)
		draw_textured_line(cub, img, &cub->gfx.txtr[EA], x);
	else
		draw_textured_line(cub, img, &cub->gfx.txtr[WE], x);
}

static void	init_draw(t_main *cub, t_rays *r, t_player *p)
{
	if (r->wall_side == 0)
		r->wall_dist = (r->dist[X] - r->delta[X]);
	else
		r->wall_dist = (r->dist[Y] - r->delta[Y]);
	r->wall_height = (int)(WINDOW_HEIGHT / r->wall_dist);
	r->wall_side = check_wall_side(r->wall_side, p->pos, r->map, p->aov);
	cub->gfx.start = -r->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (cub->gfx.start < 0)
		cub->gfx.start = 0;
	cub->gfx.end = r->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (cub->gfx.end >= WINDOW_HEIGHT)
		cub->gfx.end = WINDOW_HEIGHT - 1;
}

int		draw_scene(t_main *cub, t_rays *r, t_player *p, t_image *img)
{
	int	x;

	x = -1;
	while (++x <= WINDOW_WIDTH)
	{
		init_dda(r, p, x);
		dda(r, cub->map.grid);	//❌repenser le calcul des distances pour les visions en ligne droite? (BUG quand aov == 0/90/180/270)
		init_draw(cub, r, p);
		draw_texture(cub, r, img, x);
	}
	return (0);
}
