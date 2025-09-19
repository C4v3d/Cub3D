/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_usr_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:17:18 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/19 14:07:21 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	keyboard_inputs(int keycode, void *param)
{
	t_main *cub;

	cub = (t_main *)param;
	if (keycode == Q || keycode == ESC)
		cub->pr.close_program = true;
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		update_plyr_pos(&cub->plyr, keycode);
	return (0);
}

//int	mouse_inputs(t_main *cub)
//{
//	mlx_hook(cub->dspl.win, 17, 0L, free_cub, cub);
//	return (0);
//}

