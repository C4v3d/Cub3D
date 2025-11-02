/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:47:38 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/26 15:00:56 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_mark_mini(t_rays *r, int *x_i, int *y_i)
{
	if (r->map[X] == 0 && r->w_side == WE)
		(*x_i) = 0;
	else if (r->map[X] == 0)
		(*x_i) = MINI_RES;
	else
		(*x_i) = r->map[X] * MINI_RES;
	if (r->map[Y] == 0 && r->w_side == NO)
		(*y_i) = 0;
	else if (r->map[Y] == 0)
		(*y_i) = MINI_RES;
	else
		(*y_i) = r->map[Y] * MINI_RES;
}

void	mark_minimap(t_image *img, t_player *p)
{
	int	x_i;
	int x_tmp;
	int	y_i;
	int i;

	get_main_ray(&p->cub->map.r_mini, p, &p->cub->map);
	init_mark_mini(&p->cub->map.r_mini, &x_i, &y_i);
	x_tmp = x_i;
	i = -1;
	while (++i <= MINI_RES)
	{
		if (x_i >= WINDOW_WIDTH)
			break ;
		my_mlx_pixel_put(img, x_i, y_i, 0xFFFFFF);
		my_mlx_pixel_put(img, x_i++, y_i + MINI_RES, p->cub->gfx.colors[0]->color / 2);
	}
	x_i = x_tmp;
	i = -1;
	while (++i <= MINI_RES)
	{
		if (y_i >= WINDOW_HEIGHT)
			break ;
		my_mlx_pixel_put(img, x_i, y_i, 0xFFFFFF);
		my_mlx_pixel_put(img, x_i + MINI_RES, y_i++, p->cub->gfx.colors[0]->color / 2);
	}
}
