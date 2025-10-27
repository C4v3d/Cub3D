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

int	loop(int keycode, void *param)
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
	process_moves(cub, keycode);
	rays_calculation(&cub->plyr, &cub->map);
	render_game(cub);
	fprintf(stderr, "loop\n");
	return (0);
}
