/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:49:27 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/23 16:41:54 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// V2
void	draw_background(int floor_c, int ceiling_c, t_image *img)
{
	size_t	pos[AXIS];
	size_t	dim[AXIS];

	printf("floor_c :%x\nceiling_c :%x\n", floor_c, ceiling_c);
	pos[X] = 0;
	pos[Y] = 0;
	dim[X] = 1280;
	dim[Y] = WINDOW_HEIGHT / 2;
	draw(img, dim, pos, ceiling_c); // Is it Floor or Ceiling ?
	pos[Y] = WINDOW_HEIGHT / 2;
	dim[Y] = WINDOW_HEIGHT;
	draw(img, dim, pos, floor_c); // Is it Floor or Ceiling ?
}


// V1
// void	draw_background(t_image *img)
// {
// 	size_t	pos[AXIS];
// 	size_t	dim[AXIS];

// 	pos[X] = 0;
// 	pos[Y] = 0;
// 	dim[X] = 1280;
// 	dim[Y] = WINDOW_HEIGHT / 2;
// 	//draw(img, dim, pos, cub->gfx.colors[1]->color);	//❌ BUG avec cub->gfx.colors[]->color
// 	draw(img, dim, pos, 0x0000FA);
// 	pos[Y] = WINDOW_HEIGHT / 2;
// 	dim[Y] = WINDOW_HEIGHT;
// 	//draw(img, dim, pos, cub->gfx.colors[0]->color);	//❌ BUG avec cub->gfx.colors[]->color
// 	draw(img, dim, pos, 0xC2FFA8);
// }

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
			my_mlx_pixel_put(img, x_i, y_i, color);
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

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->s_line + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
