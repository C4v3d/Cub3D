/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:12:43 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/12 17:37:23 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	draw_tile(t_data *img, size_t x_pos, size_t y_pos, int color)
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

static void	draw_plyr(t_data *img, double pos_x, double pos_y, double dir[2], int color)
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

void	draw_minimap(int kc, t_main *cub)
{
	t_data	mini;
	size_t	x_i;
	size_t	y_i;

	y_i = 0;
	mini.img = mlx_new_image(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mini.addr = mlx_get_data_addr(mini.img, &mini.bits_per_pixel, &mini.line_length,
								&mini.endian);
	while (y_i < cub->map.dim[Y])
	{
		x_i = 0;
		while (cub->map.grid[y_i][x_i])
		{
			if (cub->map.grid[y_i][x_i] == '1')
				draw_tile(&mini, x_i * MINI_RES, y_i * MINI_RES, 200);
			x_i++;
		}
		draw_plyr(&mini, cub->plyr.pos[X] * MINI_RES, cub->plyr.pos[Y] * MINI_RES, cub->plyr.dir, 0xFF0000);
		if (kc == W)
			my_mlx_pixel_put(&mini, (cub->plyr.pos[X] + cub->plyr.dir[X]) * MINI_RES, (cub->plyr.pos[Y] - cub->plyr.dir[Y]) * MINI_RES, 0x00FF00);
		if (kc == S)
			my_mlx_pixel_put(&mini, (cub->plyr.pos[X] - cub->plyr.dir[X]) * MINI_RES, (cub->plyr.pos[Y] + cub->plyr.dir[Y]) * MINI_RES, 0x00FF00);
		y_i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->dspl.win, mini.img, 0, 0);
}
