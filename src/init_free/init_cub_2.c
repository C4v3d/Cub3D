/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:38:41 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/03 11:14:04 by emonacho         ###   ########.fr       */
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
	cub->plyr.tile_pos[X] = cub->plyr.pos[X];
	cub->plyr.tile_pos[Y] = cub->plyr.pos[Y];
	update_plyr_vision(&cub->plyr, A); // TRICKS POUR LANCER LA MACHINE
	return (0);
}

int		init_hooks(t_main *cub)
{
	mlx_hook(cub->dspl.win, 02, 1L<<0, input_loop, cub);
	mlx_loop_hook(cub->mlx, loop, cub);
	return (0);
}

int		init_display(t_display *dspl, t_main *cub)
{
	dspl->cub = cub;
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (ft_perror(dspl->cub, errno, CRITICAL));
	//dspl->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	dspl->win_dim[X] = WINDOW_WIDTH;
	dspl->win_dim[Y] = WINDOW_HEIGHT;
	dspl->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	return (0);
}
