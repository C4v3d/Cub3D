/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:38:41 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/21 13:25:53 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		init_parsed_data(t_main *cub)
{
	//.............................⚠️TESTS
	fprintf(stderr, "%s⚠️ init_parsed_data | initialising tests values%s\n", YEL, RESET);
	cub->gfx.txtr_res = 8;
	cub->map.dim[X] = 10;
	cub->map.dim[Y] = 10;
	cub->map.plyr_start_ori = cub->gfx.txtr_res * 2;
	cub->map.plyr_start_pos[X] = cub->map.dim[X] / 2;
	cub->map.plyr_start_pos[Y] = cub->map.dim[Y] / 2;
	fprintf(stderr, "%scub->gfx.txtr_res..........: %d\ncub->map.dim[X]............: %ld\ncub->map.dim[Y]............: %ld%s\n", YEL, cub->gfx.txtr_res, cub->map.dim[X], cub->map.dim[Y], RESET);
	fprintf(stderr, "%scub->map.plyr_start_ori....: %ld\ncub->map.plyr_start_pos[X].: %ld\ncub->map.plyr_start_pos[Y].: %ld%s\n", YEL, cub->map.plyr_start_ori, cub->map.plyr_start_pos[X], cub->map.plyr_start_pos[Y], RESET);
	cub->map.grid = init_2d_array(cub->map.dim[X], cub->map.dim[Y]);
	//.............................⚠️TESTS
	cub->plyr.pos_mp[X] = cub->map.plyr_start_pos[X];
	cub->plyr.pos_mp[Y] = cub->map.plyr_start_pos[Y];
	cub->plyr.pos_ti[X] = cub->gfx.txtr_res / 2;
	cub->plyr.pos_ti[Y] = cub->gfx.txtr_res / 2;
	cub->plyr.fov_max = cub->gfx.txtr_res * 4;
	cub->plyr.fov_val = cub->gfx.txtr_res / 2;
	cub->plyr.aov = cub->map.plyr_start_ori;
	calculate_fov(cub->plyr.fov, cub->plyr.fov_val,
			cub->plyr.fov_max, cub->plyr.aov);
	return (0);
}

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
	if (!cub->mlx)
		return (ft_perror(dspl->cub, errno, CRITICAL));
	dspl->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	return (0);
}
