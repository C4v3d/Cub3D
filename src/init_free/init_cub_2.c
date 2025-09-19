/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:38:41 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/19 13:42:15 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		init_hooks(t_main *cub)
{
	mlx_key_hook(cub->dspl.win, keyboard_inputs, cub);
	//mlx_key_hook(cub->dspl.win, mouse_inputs, cub);
	mlx_loop_hook(cub->mlx, to_close_program, cub);
	mlx_hook(cub->dspl.win, 17, 0L, free_cub, cub);
	return (0);
}

int		init_user_inputs(t_usr_ctrl_in *ctrl, t_main *cub)
{
	int	simultaneous_handled_controls;
	int	i;

	ctrl->cub = cub;
	simultaneous_handled_controls = 4;
	ctrl->kc = malloc(sizeof(int) * simultaneous_handled_controls);
	if (!ctrl->kc)
		return (1);
	i = -1;
	while (++i < simultaneous_handled_controls)
		ctrl->kc[i] = -1;
	return (0);
}

int		init_display(t_display *dspl, t_main *cub)
{
	dspl->cub = cub;
	cub->mlx = mlx_init();
	dspl->win_w = 500;
	dspl->win_h = 400;
	dspl->win = mlx_new_window(cub->mlx, dspl->win_w, dspl->win_h, "Cub3d");
	return (0);
}
