/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/11 12:52:54 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_graphic_data(t_graphic *gfx, t_main *cub)
{
	t_color floor;
	t_color ceiling;
	
	gfx->cub = cub;
	ft_bzero(&gfx->txtr, sizeof(gfx->txtr));
	gfx->colors[FLOOR] = &floor;
	gfx->colors[CEILING] = &ceiling;
	gfx->el_counter = 0;
}

static void	init_map_data(t_map *map, t_main *cub)
{	
	map->cub = cub;
	map->grid = ft_calloc(1, sizeof(map->grid));
	if (!map->grid)
		ft_perror(map->cub, ENOMEM, CRITICAL);
	map->dim[X] = 0;
	map->dim[Y] = 0;
	ft_bzero(&map->plyr_pos, sizeof(t_vector));
	map->plyr_start_ori = 0;
}

static void	init_player_data(t_player *plyr, t_main *cub)
{
	t_vector	plyr_dir;
	
	plyr->cub = cub;
	plyr->pos = &cub->map.plyr_pos;
	plyr->dir = &plyr_dir;
}

void	init_cub(t_main *cub)
{
	ft_memset(cub, '\0', sizeof(cub)); /** Setting everything to null */
	init_graphic_data(&cub->gfx, cub);
	init_map_data(&cub->map, cub);
	init_player_data(&cub->plyr, cub);
	init_user_inputs(&cub->ctrl, cub);
	init_display(&cub->dspl, cub);
	init_hooks(cub);
}