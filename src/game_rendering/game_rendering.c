/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:36:11 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/01 19:16:16 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		draw_scene(t_main *cub, t_image *img)
{
	(void)img;
	get_current_ray(&cub->r, &cub->plyr, &cub->map);
	//while (get_current_ray(&cub->plyr, &cub->map))
	//{

	//}
	return (0);
}

int	draw_background(t_main *cub, t_image *img)
{
	//v1
	//size_t	pos[AXIS];

	//pos[X] = 0;
	//pos[Y] = 0;
	//paint(img, cub->dspl.win_dim, pos, cub->gfx.colors[1]->color);
	//pos[X] = WINDOW_WIDTH / 2;
	//pos[Y] = WINDOW_HEIGHT / 2;
	//paint(img, cub->dspl.win_dim, pos, cub->gfx.colors[0]->color);

	//v2
	paint(img, cub->dspl.win_dim,
		(size_t[]){0, 0}, cub->gfx.colors[1]->color);
	paint(img, cub->dspl.win_dim,
		(size_t[]){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2},
			cub->gfx.colors[0]->color);
	return (0);
}
