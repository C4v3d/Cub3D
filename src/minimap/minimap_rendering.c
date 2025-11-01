/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:12:43 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/01 19:15:25 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_line(t_image *img, t_player *p)
{
	my_mlx_pixel_put(img, (p->pos[X] + p->dir[X]) * MINI_RES, (p->pos[Y] - p->dir[Y]) * MINI_RES, 0xFFFFFF);
}

static void	draw_tile(t_image *img, size_t x_pos, size_t y_pos, int color)
{
	size_t	x_i;
	size_t	y_i;

	y_i = 0;

	while (y_i++ < MINI_RES)
	{
		x_i = 0;
		while (x_i++ < MINI_RES)
			my_mlx_pixel_put(img, (x_pos + x_i), (y_pos + y_i), color);
	}
}

static void	draw_plyr(t_image *img, double pos_x, double pos_y, double dir[2], int color)
{
	size_t	x_i;
	size_t	y_i;
	(void)dir;

	y_i = 0;
	while (y_i++ < MINI_RES)
	{
		x_i = 0;
		while (x_i++ < MINI_RES)
			my_mlx_pixel_put(img, ((pos_x - 8) + x_i), ((pos_y - 8) + y_i), color);
	}
}

void	draw_minimap(t_main *cub, t_image *img)
{
	size_t	x_i;
	size_t	y_i;

	y_i = 0;
	while (y_i < cub->map.dim[Y])
	{
		x_i = 0;
		while (cub->map.grid[y_i][x_i])
		{
			if (cub->map.grid[y_i][x_i] == '1')
				draw_tile(img, x_i * MINI_RES, y_i * MINI_RES, 200);
			x_i++;
		}
		draw_plyr(img, cub->plyr.pos[X] * MINI_RES, cub->plyr.pos[Y] * MINI_RES, cub->plyr.dir, 0xFF0000);
		draw_line(img, &cub->plyr);
		y_i++;
	}
	//mark_minimap(img, &cub->plyr);
}
