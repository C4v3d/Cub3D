/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:49:27 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/07 16:11:24 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	paint_line(t_image *img, int x, int start, int end, int col)
{
	int	y_i;

	y_i = start;
	while (y_i < end)
		my_mlx_pixel_put(img, x, y_i++, col);
}

void	paint(t_image *img, size_t dim[AXIS], size_t pos[AXIS], int color)
{
	size_t	x_i;
	size_t	y_i;

	y_i = dim[Y];
	while (y_i > pos[Y])
	{
		x_i = dim[X];
		while (x_i > pos[X])
		{
			my_mlx_pixel_put(img, x_i, y_i, color);
			x_i--;
		}
		y_i--;
	}
}

int	create_image(t_main *cub, t_image *img)
{
	img->img = mlx_new_image(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (0);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
