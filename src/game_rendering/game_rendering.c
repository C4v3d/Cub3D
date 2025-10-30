/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:36:11 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/30 17:43:08 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int render_game(t_main *cub)
{
	draw_background(cub, cub->gfx.map.img);
	//while (1)
	//{
		rays_calculation(&cub->plyr, &cub->map);
	//	draw_scene(cub);
	//}
	draw_minimap(cub);
	return (0);
}
