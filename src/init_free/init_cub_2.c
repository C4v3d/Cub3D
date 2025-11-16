/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:38:41 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/16 18:35:17 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		init_parsed_data(t_main *cub)
{
	cub->plyr.pos[X] = (double)cub->map.plyr_start_pos[X];
	cub->plyr.pos[Y] = (double)cub->map.plyr_start_pos[Y];
	cub->r.plane[Y] = -cub->plyr.dir[X] * tan(cub->plyr.fov / 2.0);
	cub->r.plane[X] =  cub->plyr.dir[Y] * tan(cub->plyr.fov / 2.0);
	update_plyr_vision(&cub->plyr, LA); // TRICKS POUR LANCER LA MACHINE	-> sans ça manque calcul du plane
	update_plyr_vision(&cub->plyr, RA); // TRICKS POUR LANCER LA MACHINE	-> sans ça manque calcul du plane
	update_plyr_position(&cub->plyr, W); // TRICKS POUR LANCER LA MACHINE	-> sans ça CRASH
	update_plyr_position(&cub->plyr, D); // TRICKS POUR LANCER LA MACHINE	-> sans ça CRASH
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
	dspl->win_dim[X] = WINDOW_WIDTH;
	dspl->win_dim[Y] = WINDOW_HEIGHT;
	dspl->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	return (0);
}
