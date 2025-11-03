/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:17:18 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/03 16:22:23 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	input_loop(int keycode, void *param)
{
	t_main *cub;

	cub = (t_main *)param;
	//if (keycode != W && keycode != A && keycode != S && keycode != D
	//		 && keycode != I && keycode != O && keycode != UA && keycode != LA
	//		 	&& keycode != DA && keycode != RA)									// DEBUG
	//	fprintf(stderr, "[key_in] keycode: %d\n", keycode);							// DEBUG
	if (keycode == Q || keycode == ESC)
	{
		cub->pr.close_program = true;
		return (0);
	}
	if (keycode == M)
		cub->pr.show_minimap = true;
	if (keycode == N)
		cub->pr.show_minimap = false;
	update_plyr_position(&cub->plyr, keycode);
	update_plyr_vision(&cub->plyr, keycode);
	return (0);
}

int	loop(t_main *cub)
{
	if (cub->pr.close_program == true)
		free_cub(cub);
	if (cub->gfx.map.img != NULL)
		mlx_destroy_image(cub->mlx, cub->gfx.map.img);
	create_image(cub, &cub->gfx.map);
	draw_background(cub, &cub->gfx.map);
	draw_scene(cub, &cub->r, &cub->plyr, &cub->gfx.map);
	draw_minimap(cub, &cub->gfx.map);
	draw_fps(cub, &cub->gfx.map);
	mlx_put_image_to_window(cub->mlx, cub->dspl.win, cub->gfx.map.img, 0, 0);
	return (false);
}
