/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:49:27 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/28 09:44:33 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_background(int floor_c, int ceiling_c, t_image *img)
{
	size_t	pos[AXIS];
	size_t	dim[AXIS];

	pos[X] = 0;
	pos[Y] = 0;
	dim[X] = 1280;
	dim[Y] = WINDOW_HEIGHT / 2;
	draw(img, dim, pos, ceiling_c);
	pos[Y] = WINDOW_HEIGHT / 2;
	dim[Y] = WINDOW_HEIGHT;
	draw(img, dim, pos, floor_c);
}

void	draw(t_image *img, size_t dim[AXIS], size_t pos[AXIS], int color)
{
	size_t	x_i;
	size_t	y_i;

	y_i = dim[Y];
	while (y_i > pos[Y])
	{
		x_i = dim[X];
		while (x_i > pos[X])
		{
			put_p(img, x_i, y_i, color);
			x_i--;
		}
		y_i--;
	}
}

int	create_image(t_main *cub, t_image *img)
{
	img->img = mlx_new_image(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->s_line, &img->endian);
	return (0);
}

void	put_p(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->s_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
