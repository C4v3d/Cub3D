/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/09/30 11:48:48 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

static void	destroy_display(t_display *dspl)
{
	mlx_destroy_window(dspl->cub->mlx, dspl->win);
	mlx_destroy_display(dspl->cub->mlx);
}

static void	free_user_inputs(t_usr_ctrl_in *ctrl)
{
	w_free((void**)&ctrl->kc); // ⚠️ Besoin et possible de gerer plusieurs inputs?
}

static void	free_program_data(t_prog *pr)
{
	if (w_close(pr->input_file_fd) == -1)
		ft_perror(pr->cub, errno, WARNING);
}

static void	free_player_data(t_player *plyr)
{
	w_free((void**)&plyr->pos_mp);
	w_free((void**)&plyr->pos_ti);
	w_free((void**)&plyr->fov);
}

static void	free_map_data(t_map *map)
{
	size_t	i;

	i = -1;
	while (++i < map->dim[Y])
		w_free((void**)&map->grid[i]);
	w_free((void**)&map->grid);
	w_free((void**)&map->dim);
	w_free((void**)&map->plyr_start_pos);
}


static void	free_graphic_data(t_graphic *gfx)
{
	w_free((void **)&gfx->colors[CEILING]);
	w_free((void **)&gfx->colors[FLOOR]);
	w_free((void**)&gfx->txtr);
}

int	free_cub(t_main *cub)
{
	destroy_display(&cub->dspl);
	free_graphic_data(&cub->gfx);
	free_program_data(&cub->pr);
	free_player_data(&cub->plyr);
	free_map_data(&cub->map);
	free_user_inputs(&cub->ctrl);
	return (0);
}
