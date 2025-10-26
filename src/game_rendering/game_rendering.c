/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:36:11 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/26 19:52:25 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int render_game(t_main *cub)
{
	if (cub->gfx.map.img)
		mlx_destroy_image(cub->mlx, cub->gfx.map.img);
	create_image(cub, &cub->gfx.map);
	draw_scene(cub);
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->dspl.win, cub->gfx.map.img, 0, 0);
	return (0);
}
