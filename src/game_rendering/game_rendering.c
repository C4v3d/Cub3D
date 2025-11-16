/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:36:11 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/16 17:43:00 by emonacho         ###   ########.fr       */
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
	//pixel = t->addr + (y * t->s_line + x * (t->bpp / 32));	// EFFET DE GLITCH INTERESSANT
	return (*(int *)pixel);
}

static void	draw_texture(t_main *cub, t_draw *tex, t_image *t, int x)
{
	int	y;
	int	color;

	y = tex->start - 1;
	while (++y <= tex->end)
	{
		tex->y = (int)tex->pos & (t->height - 1);
		tex->pos += tex->step;
		color = get_texture_color(t, tex->x, tex->y);
		my_mlx_pixel_put(&cub->gfx.map, x, y, color);
	}
}
		//............POUR LE FUN.............................................................
		//r->y = (int)r->pos & tex->height - 1;			// EFFET DE GLITCH INTERESSANT
		//r->pos += r->step;								// EFFET DE GLITCH INTERESSANT
		//color = tex->addr[tex->height * r->y + r->x];	// EFFET DE GLITCH INTERESSANT
		//my_mlx_pixel_put(&cub->gfx.map, x, y, color);			// EFFET DE GLITCH INTERESSANT


static void	init_draw(t_main *cub, t_rays *r, t_draw *tex, t_player *p)
{
	tex->num = check_wall_side(r->wall_side, p->pos, r->map, p->aov);
	if (r->wall_side == 0)	// calculate exaclty where the wall was hit
		tex->wall_x = p->pos[Y] + r->wall_dist * r->dir[Y];
	else
		tex->wall_x = p->pos[X] + r->wall_dist * r->dir[X];
	tex->wall_x -=floor(tex->wall_x);
	tex->x = (int)(tex->wall_x * (double)cub->gfx.txtr[tex->num].width);
	if (r->wall_side == 0 && r->dir[X] > 0)	// mirroring textures
		tex->x = cub->gfx.txtr[tex->num].width - tex->x - 1;
	if (r->wall_side == 1 && r->dir[Y] < 0)
		tex->x = cub->gfx.txtr[tex->num].width - tex->x - 1;
	tex->step = 1.0 * cub->gfx.txtr[tex->num].height / r->wall_height;
	tex->pos = (tex->start - WINDOW_HEIGHT / 2 + r->wall_height / 2) * tex->step;
}

static void	calculate_dist_height(t_rays *r, t_draw *tex)
{
	if (r->wall_side == 0)
		r->wall_dist = (r->dist[X] - r->delta[X]);
	else
		r->wall_dist = (r->dist[Y] - r->delta[Y]);
	r->wall_height = (int)(WINDOW_HEIGHT / r->wall_dist);
	tex->start = -r->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (tex->start < 0)
		tex->start = 0;
	tex->end = r->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (tex->end >= WINDOW_HEIGHT)
		tex->end = WINDOW_HEIGHT - 1;
}

int		draw_scene(t_main *cub, t_rays *r, t_player *p)
{
	t_draw	tex;
	int		x;

	x = -1;
	while (++x <= WINDOW_WIDTH)
	{
		init_dda(r, p, x);
		dda(r, cub->map.grid);	//❌ calcul des distances pour les visions en ligne droite fixé dans init_dda
		calculate_dist_height(r, &tex);
		init_draw(cub, r, &tex, p);
		draw_texture(cub, &tex, &cub->gfx.txtr[tex.num], x);
	}
	return (0);
}
