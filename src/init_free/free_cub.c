/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:51 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/17 11:08:26 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	free_program_data(t_prog *pr)
{
	(void)pr;
}

static void	free_player_data(t_player *pl)
{
	w_free((void**)pl->pos);
}

static void	free_map_data(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
		w_free((void**)map->grid[i]);
	w_free((void**)map->grid);
	w_free((void**)map->p_start_pos);
}


static void	free_graphic_data(t_graphic *gfx)
{
	int	i;

	i = -1;
	while (++i < gfx->rgb_s)
		w_free((void**)gfx->rgb[i]);
	w_free((void**)gfx->rgb);
	w_free((void**)gfx->txtr);
}

void	free_cub(t_main *cub)
{
	free_graphic_data(&cub->gfx);
	free_program_data(&cub->pr);
	free_player_data(&cub->pl);
	free_map_data(&cub->map);
	free(cub);
}
