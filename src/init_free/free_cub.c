/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:51 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/19 13:55:08 by emonacho         ###   ########.fr       */
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
	w_free((void**)&ctrl->kc);
}

static void	free_program_data(t_prog *pr)
{
	(void)pr;
}

static void	free_player_data(t_player *plyr)
{
	w_free((void**)&plyr->pos);
}

static void	free_map_data(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
		w_free((void**)&map->grid[i]);
	w_free((void**)&map->grid);
	w_free((void**)&map->plyr_start_pos);
}


static void	free_graphic_data(t_graphic *gfx)
{
	int	i;

	i = -1;
	while (++i < gfx->rgb_s)
		w_free((void**)&gfx->rgb[i]);
	w_free((void**)&gfx->rgb);
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
	free(cub->mlx);
	free(cub);
	exit(0);
}
