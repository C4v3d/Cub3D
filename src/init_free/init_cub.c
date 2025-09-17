/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/17 17:33:26 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	init_program_data(t_prog *pr, t_main *cub)
{
	pr->cub = cub;
	return (0);
}


static int	init_player_data(t_player *pl, t_main *cub)
{
	pl->cub = cub;
	pl->pos = malloc(sizeof(int) * 2);
	if (!pl->pos)
		return (ft_perror(pl->cub, ENOMEM, CRITICAL));
	pl->pos[X] = 0;
	pl->pos[Y] = 0;
	pl->aov = 0;
	return (0);
}


static int	init_map_data(t_map *map, t_main *cub)
{
	map->cub = cub;
	map->p_start_pos = malloc(sizeof(int) * 2);
	if (!map->p_start_pos)
		return (ft_perror(map->cub, ENOMEM, CRITICAL));
	map->p_start_pos[X] = 0;
	map->p_start_pos[Y] = 0;
	return (0);
}

static int	init_graphic_data(t_graphic *gfx, t_main *cub)
{
	int	i;

	gfx->cub = cub;
	gfx->txtr_s = 4; // 4 for: N,S,W,E (adapt if necessary)
	gfx->txtr = malloc(sizeof(void *) * gfx->txtr_s);
	if (!gfx->txtr)
		return (ft_perror(gfx->cub, ENOMEM, CRITICAL));
	gfx->rgb_s = 2;	// 2 for: FLOOR and CEILING (adapt if necessary)
	gfx->rgb = init_2d_array(gfx->rgb_s, 3);
	if (!gfx->rgb)
		return (ft_perror(gfx->cub, ENOMEM, CRITICAL));
	return (0);
}

int	init_cub(t_main *cub)
{
	if (init_graphic_data(&cub->gfx, cub) != 0)
		return (1);
	if (init_map_data(&cub->map, cub) != 0)
		return (1);
	if (init_player_data(&cub->pl, cub) != 0)
		return (1);
	if (init_program_data(&cub->pr, cub) != 0)
		return (1);
	return (0);
}
