/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:12:43 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/21 11:38:53 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_untextured(t_image *img, t_player *p)
{
	my_mlx_pixel_put(img, (p->pos[X] + p->dir[X]) * MINI_RES, (p->pos[Y] - p->dir[Y]) * MINI_RES, 0xFFFFFF);
}

static void	draw_tile(t_image *img, size_t x_pos, size_t y_pos, int color)
{
	size_t	x_i;
	size_t	y_i;

	y_i = -1;
	while (++y_i < MINI_RES)
	{
		if (y_i >= WINDOW_HEIGHT)
			break ;
		x_i = -1;
		while (++x_i < MINI_RES)
		{
			if (x_i >= WINDOW_WIDTH)
				break ;
			my_mlx_pixel_put(img, (x_pos + x_i), (y_pos + y_i), color);
		}
	}
}

static void	draw_plyr(t_image *img, double pos_x, double pos_y, int color)
{
	size_t	x_i;
	size_t	y_i;

	y_i = -1;
	while (++y_i < MINI_RES)
	{
		if (y_i >= WINDOW_HEIGHT)
			break ;
		x_i = -1;
		while (++x_i < MINI_RES)
		{
			if (x_i >= WINDOW_WIDTH)
				break ;
			my_mlx_pixel_put(img, ((pos_x - 8) + x_i), ((pos_y - 8) + y_i), color);
		}
	}
}

void	draw_minimap(t_main *cub, t_image *img)
{
	size_t	x_i;
	size_t	y_i;

	if (cub->pr.show_minimap == false)
		return ;
	y_i = -1;
	while (++y_i < cub->map.dim[Y])
	{
		if (y_i >= WINDOW_HEIGHT)
			break ;
		x_i = -1;
		while (cub->map.grid[y_i][++x_i])
		{
			if (cub->map.grid[y_i][x_i] == '1')
				draw_tile(img, x_i * MINI_RES, y_i * MINI_RES, cub->gfx.ceiling->color / 4);
		}
		draw_plyr(img, cub->plyr.pos[X] * MINI_RES, cub->plyr.pos[Y] * MINI_RES, cub->gfx.floor->color / 4);
		draw_untextured(img, &cub->plyr);
	}
	mark_minimap(img, &cub->plyr);
}
