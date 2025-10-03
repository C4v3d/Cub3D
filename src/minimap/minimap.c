/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:12:43 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/03 14:53:28 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"




void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	draw_minimap(t_main *cub)
{
	t_data	mini;

	mini.img = mlx_new_image(cub->mlx, WINDOW_WIDTH / 8, WINDOW_HEIGHT / 8);
	mini.addr = mlx_get_data_addr(mini.img, &mini.bits_per_pixel, &mini.line_length,
								&mini.endian);

	size_t	x_i;
	size_t	y_i;

	y_i = 0;
	while (y_i++ < 16)
	{
		x_i = 0;
		while (x_i++ < 8)
			my_mlx_pixel_put(&mini, 5 + x_i, 5 + y_i, 0x00DFE2);
	}
	mlx_put_image_to_window(cub->mlx, cub->dspl.win, mini.img, 0, 0);
	return (0);
}
