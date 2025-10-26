/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_front_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:47:38 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/26 14:52:15 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_front_wall(t_player *p, int *x_i, int *y_i, int *x_tmp)
{
	if (p->r.w_seen[X] == 0 && p->r.w_side == WE)
		(*x_i) = 0;
	else if (p->r.w_seen[X] == 0)
		(*x_i) = MINI_RES;
	else
		(*x_i) = p->r.w_seen[X] * MINI_RES;
	(*x_tmp) = (*x_i);
	if (p->r.w_seen[Y] == 0 && p->r.w_side == NO)
		(*y_i) = 0;
	else if (p->r.w_seen[Y] == 0)
		(*y_i) = MINI_RES;
	else
		(*y_i) = p->r.w_seen[Y] * MINI_RES;
}

void	draw_front_wall(t_image *map, t_player *p)
{
	int	x_i;
	int x_tmp;
	int	y_i;
	int i;

	init_front_wall(p, &x_i, &y_i, &x_tmp);
	i = -1;
	while (++i < MINI_RES)
	{
		my_mlx_pixel_put(map, x_i, y_i, 0xFFFFFF);
		my_mlx_pixel_put(map, x_i++, y_i + MINI_RES, 0xFFFFFF);
	}
	x_i = x_tmp;
	i = -1;
	while (++i < MINI_RES)
	{
		my_mlx_pixel_put(map, x_i, y_i, 0xFFFFFF);
		my_mlx_pixel_put(map, x_i + MINI_RES, y_i++, 0xFFFFFF);
	}
}