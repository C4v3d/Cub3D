/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/19 12:36:43 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	init_player_data(t_player *plyr, t_main *cub)
{
	plyr->cub = cub;
	plyr->pos = malloc(sizeof(int) * 2);
	if (!plyr->pos)
		return (ft_perror(plyr->cub, ENOMEM, CRITICAL));
	plyr->pos[X] = 0;
	plyr->pos[Y] = 0;
	plyr->aov = 0;
	return (0);
}


static int	init_map_data(t_map *map, t_main *cub)
{
	map->cub = cub;
	map->plyr_start_pos = malloc(sizeof(int) * 2);
	if (!map->plyr_start_pos)
		return (ft_perror(map->cub, ENOMEM, CRITICAL));
	map->plyr_start_pos[X] = 0;
	map->plyr_start_pos[Y] = 0;
	return (0);
}

static int	init_graphic_data(t_graphic *gfx, t_main *cub)
{
	gfx->cub = cub;
	gfx->txtr_s = 4; // 4 for: N,S,W,E (adapt if necessary)
	gfx->txtr = malloc(sizeof(void *) * gfx->txtr_s);
	if (!gfx->txtr)
		return (ft_perror(gfx->cub, ENOMEM, CRITICAL));
	gfx->colors[0] = malloc(sizeof(t_color));
	if (!gfx->colors)
		return (ft_perror(gfx->cub, ENOMEM, CRITICAL));
	return (0);
}

void	init_cub(t_main *cub)
{
	init_graphic_data(&cub->gfx, cub);
	init_map_data(&cub->map, cub);
	init_player_data(&cub->plyr, cub);
	init_display(&cub->dspl, cub);
	init_user_inputs(&cub->ctrl, cub);
}
