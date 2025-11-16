/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:36:11 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/16 16:29:44 by emonacho         ###   ########.fr       */
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

static int	get_texture_color(t_image *tex, int x, int y)
{
	char	*pixel;

	if (x < 0)
		x = 0;
	if (x >= tex->width)
		x = tex->width - 1;
	if (y < 0)
		y = 0;
	if (y >= tex->height)
		y = tex->height - 1;
	pixel = tex->addr + (y * tex->s_line + x * (tex->bpp / 8));
	return (*(int *)pixel);
}

static void	draw_textured_line(t_main *cub, t_rays *r, t_image *tex, int x)
{
	int			y;
	int	color;

	y = r->tex_start - 1;
	while (++y <= cub->r.tex_end)
	{
		r->tex_y = (int)r->tex_pos & (tex->height - 1);
		r->tex_pos += r->step;
		color = get_texture_color(tex, r->tex_x, r->tex_y);
		my_mlx_pixel_put(&cub->gfx.map, x, y, color);
	}
}
		//............POUR LE FUN.............................................................
		//r->tex_y = (int)r->tex_pos & tex->height - 1;			// EFFET DE GLITCH INTERESSANT
		//r->tex_pos += r->step;								// EFFET DE GLITCH INTERESSANT
		//color = tex->addr[tex->height * r->tex_y + r->tex_x];	// EFFET DE GLITCH INTERESSANT
		//my_mlx_pixel_put(&cub->gfx.map, x, y, color);			// EFFET DE GLITCH INTERESSANT


static void	draw_texture(t_main *cub, t_rays *r, int x)
{
	draw_textured_line(cub, r, &cub->gfx.txtr[r->tex_num], x);

}

static void	init_draw(t_rays *r, t_player *p)
{
	r->tex_num = check_wall_side(r->wall_side, p->pos, r->map, p->aov);
	if (r->wall_side == 0)	// calculate exaclty where the wall was hit
		r->wall_x = p->pos[Y] + r->wall_dist * r->dir[Y];
	else
		r->wall_x = p->pos[X] + r->wall_dist * r->dir[X];
	r->wall_x -=floor(r->wall_x);
	r->tex_x = (int)(r->wall_x * (double)r->cub->gfx.txtr_res);
	if ((r->wall_side == 0 && r->dir[X] > 0) || (r->wall_side == 1 && r->dir[Y] < 0))	// mirroring textures
		r->tex_x = r->cub->gfx.txtr_res - r->tex_x - 1;
	r->step = 1.0 * r->cub->gfx.txtr_res / r->wall_height;
	r->tex_pos = (r->tex_start - WINDOW_HEIGHT / 2 + r->wall_height / 2) * r->step;
	//r->tex_pos = (r->tex_start - r->pitch - WINDOW_HEIGHT / 2 + r->wall_height / 2) * r->step;
}

static void	calculate_dist_height(t_rays *r)
{
	if (r->wall_side == 0)
		r->wall_dist = (r->dist[X] - r->delta[X]);
	else
		r->wall_dist = (r->dist[Y] - r->delta[Y]);
	r->wall_height = (int)(WINDOW_HEIGHT / r->wall_dist);
	r->tex_start = -r->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (r->tex_start < 0)
		r->tex_start = 0;
	r->tex_end = r->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (r->tex_end >= WINDOW_HEIGHT)
		r->tex_end = WINDOW_HEIGHT - 1;
}

int		draw_scene(t_main *cub, t_rays *r, t_player *p, t_image *img)
{
	(void)img;
	int	x;

	x = -1;
	while (++x <= WINDOW_WIDTH)
	{
		init_dda(r, p, x);
		dda(r, cub->map.grid);	//❌ calcul des distances pour les visions en ligne droite fixé dans init_dda
		calculate_dist_height(r);
		init_draw(r, p);
		draw_texture(cub, r, x);
	}
	return (0);
}
