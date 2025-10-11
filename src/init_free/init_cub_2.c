/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:38:41 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/11 14:30:03 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		init_parsed_data(t_main *cub)
{
	//.............................⚠️TESTS
	// fprintf(stderr, "%s⚠️ init_parsed_data | initialising tests values%s\n", YEL, RESET);
	 cub->gfx.txtr_res = 4;
	// cub->map.dim[X] = 5;
	// cub->map.dim[Y] = 3;
	//cub->map.plyr_start_ori = 0;
	//cub->map.plyr_start_pos[X] = 2;
	//cub->map.plyr_start_pos[Y] = 2;
	// fprintf(stderr, "%s⚠️ cub->gfx.txtr_res..........: %d\n⚠️ cub->map.dim[X]............: %ld\n⚠️ cub->map.dim[Y]............: %ld%s\n", YEL, cub->gfx.txtr_res, cub->map.dim[X], cub->map.dim[Y], RESET);
	// fprintf(stderr, "%s⚠️ cub->map.plyr_start_ori....: %lf\n⚠️ cub->map.plyr_start_pos[X].: %ld\n⚠️ cub->map.plyr_start_pos[Y].: %ld%s\n", YEL, cub->map.plyr_start_ori, cub->map.plyr_start_pos[X], cub->map.plyr_start_pos[Y], RESET);
	//cub->map.grid = init_2d_array(cub->map.dim[Y], cub->map.dim[X]);
	//.............................⚠️TESTS

	cub->plyr.pos[X] = (double)cub->map.plyr_start_pos[X];
	cub->plyr.pos[Y] = (double)cub->map.plyr_start_pos[Y];
	cub->plyr.aov = cub->map.plyr_start_ori;
	return (0);
}

int		init_hooks(t_main *cub)
{
	mlx_hook(cub->dspl.win, 02, 1L<<0, inputs_loop, cub);
	mlx_loop_hook(cub->mlx, to_close_program, cub);
	mlx_hook(cub->dspl.win, 17, 0L, free_cub, cub);
	return (0);
}

int		init_user_inputs(t_usr_ctrl_in *ctrl, t_main *cub)
{
	int	simultaneous_handled_controls; // ⚠️ Besoin et possible de gerer plusieurs inputs?
	int	i;

	ctrl->cub = cub;
	simultaneous_handled_controls = 4; // ⚠️ Besoin et possible de gerer plusieurs inputs?
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
	if (!cub->mlx)
		return (ft_perror(dspl->cub, errno, CRITICAL));
	dspl->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	return (0);
}