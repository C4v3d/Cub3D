/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_usr_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:17:18 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/20 20:31:29 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	keyboard_inputs(int keycode, void *param)
{
	t_main *cub;

	cub = (t_main *)param;
	if (keycode != W && keycode != A && keycode != S && keycode != D				// DEBUG
			&& keycode != UA && keycode != LA && keycode != DA && keycode != RA)	// DEBUG
		fprintf(stderr, "[key_in] keycode: %d\n", keycode);							// DEBUG
	if (keycode == Q || keycode == ESC)
		cub->pr.close_program = true;
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		update_plyr_position(&cub->plyr, keycode);
	else if (keycode == UA || keycode == LA || keycode == DA || keycode == RA)
		update_plyr_vision(&cub->plyr, keycode);
	return (0);
}

//int	mouse_inputs(t_main *cub)
//{
//	mlx_hook(cub->dspl.win, 17, 0L, free_cub, cub);
//	return (0);
//}

