/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/26 14:44:34 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_graphic_data(t_graphic *gfx, t_main *cub)
{
	t_color floor;
	t_color ceiling;
	
	gfx->cub = cub;
	gfx->colors[FLOOR] = &floor;
	gfx->colors[CEILING] = &ceiling;
}

static void	init_map_data(t_map *map, t_main *cub)
{
	map->cub = cub;
	map->plyr_start_pos = malloc(sizeof(size_t) * 2);
	if (!map->plyr_start_pos)
		ft_perror(map->cub, ENOMEM, CRITICAL);
	map->dim = malloc(sizeof(size_t) * 2);
	if (!map->dim)
		ft_perror(map->cub, ENOMEM, CRITICAL);
}

static void	init_player_data(t_player *plyr, t_main *cub)
{
	plyr->cub = cub;
	plyr->pos_mp = malloc(sizeof(size_t) * 2);
	if (!plyr->pos_mp)
		ft_perror(plyr->cub, ENOMEM, CRITICAL);
	plyr->pos_ti = malloc(sizeof(size_t) * 2);
	if (!plyr->pos_ti)
		ft_perror(plyr->cub, ENOMEM, CRITICAL);
	plyr->fov = malloc(sizeof(size_t) * 2);
	if (!plyr->fov)
		ft_perror(plyr->cub, ENOMEM, CRITICAL);
	plyr->aov = 0;
}

void	init_cub(t_main *cub)
{
	ft_memset(cub, '\0', sizeof(cub)); /** Setting everything to null */
	init_graphic_data(&cub->gfx, cub);
	fprintf(stderr, "gfx data Initialized !\n");
	init_map_data(&cub->map, cub);
	fprintf(stderr, "map data Initialized !\n");
	init_player_data(&cub->plyr, cub);
	fprintf(stderr, "player data Initialized !\n");
	init_user_inputs(&cub->ctrl, cub);
	fprintf(stderr, "unser input Initialized !\n");
	init_display(&cub->dspl, cub);
	fprintf(stderr, "display Initialized !\n");
	init_hooks(cub);
	fprintf(stderr, "hooks Initialized !\n");
}
