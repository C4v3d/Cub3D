/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:28:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/26 19:34:03 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	draw_background(t_main *cub, t_image *img)
{
	size_t	pos[DIMENSION];

	pos[X] = 0;
	pos[Y] = 0;
	paint(img, cub->dspl.win_dim, pos, cub->gfx.colors[1]->color);
	pos[X] = WINDOW_WIDTH / 2;
	pos[Y] = WINDOW_HEIGHT / 2;
	paint(img, cub->dspl.win_dim, pos, cub->gfx.colors[0]->color);
	return (0);
}

int	draw_scene(t_main *cub)
{
	draw_background(cub, &cub->gfx.map);
	return (0);
}
