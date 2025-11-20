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

int	input_loop(int kc, void *param)
{
	t_main *cub;

	cub = (t_main *)param;
	//fprintf(stderr, "[key_in] kc: %d\n", kc);							// DEBUG
	if (kc == Q || kc == ESC)
	{
		cub->pr.close_program = true;
		return (0);
	}
	else if (kc == M)
		switch_bool(&cub->pr.show_minimap);
	else if (kc == W || kc == A || kc == S || kc == D
			|| kc == UA || kc == DA)
		update_plyr_position(&cub->plyr, kc);
	else if (kc == LA || kc == RA || kc == I || kc == O)
		update_plyr_vision(&cub->plyr, kc);
	return (0);
}

int	loop(t_main *cub)
{
	if (cub->pr.close_program == true)
		free_cub(cub);
	if (cub->gfx.map.img != NULL)
		safe_destroy_image(cub->mlx, cub->gfx.map.img);
	create_image(cub, &cub->gfx.map);
	draw_background(cub->gfx.floor->color, cub->gfx.ceiling->color, &cub->gfx.map);
	draw_scene(cub, &cub->r, &cub->plyr);
	draw_minimap(cub, &cub->gfx.map);
	draw_fps(cub, &cub->gfx.map); // USELESS
	mlx_put_image_to_window(cub->mlx, cub->dspl.win, cub->gfx.map.img, 0, 0);
	return (0);
}
