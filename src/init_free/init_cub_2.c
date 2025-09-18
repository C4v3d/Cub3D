/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:38:41 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/18 13:33:33 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		init_user_inputs(t_usr_ctrl_in *ctrl, t_main *cub)
{
	int	simultaneous_handled_controls;
	int	i;

	ctrl->cub = cub;
	simultaneous_handled_controls = 4;
	ctrl->key_in = malloc(sizeof(int) * simultaneous_handled_controls);
	if (!ctrl->key_in)
		return (1);
	i = -1;
	while (++i < simultaneous_handled_controls)
		ctrl->key_in[i] = -1;
	return (0);
}

int		init_display(t_display *dspl, t_main *cub)
{
	dspl->cub = cub;
	//dspl->init = mlx_init();
	dspl->win_w = 500;
	dspl->win_h = 400;
	//dspl->win = mlx_new_window(dspl->init, dspl->win_w, dspl->win_h);
	return (0);
}
