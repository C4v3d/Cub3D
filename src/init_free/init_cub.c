/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/18 11:33:55 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	init_program_data(t_prog *pr, t_main *cub)
{
	pr->cub = cub;
	pr->parser = malloc(sizeof(t_parser));
	if (!pr->parser)
		return (ft_perror(pr->cub, errno, CRITICAL));
	pr->parser->data_scene = malloc(sizeof(t_scene));
	if (!pr->parser->data_scene)
		return (ft_perror(pr->cub, errno, CRITICAL));
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
	int i;

	map->cub = cub;
	map->grid = malloc(sizeof(int *) * map->height);
	if (!map->grid)
		return (ft_perror(map->cub, ENOMEM, CRITICAL));
	i = -1;
	while (++i < map->height)
	{
		map->grid[i] = ft_calloc(map->width, sizeof(int));
		if (!map->grid[i])
			return (ft_perror(map->cub, ENOMEM, CRITICAL));
	}
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
	gfx->rgb = malloc(sizeof(int *) * gfx->rgb_s);
	if (!gfx->rgb)
		return (ft_perror(gfx->cub, ENOMEM, CRITICAL));
	i = -1;
	while (++i < gfx->rgb_s)
	{
		gfx->rgb[i] = malloc(sizeof(int) * 3);
		if (!gfx->rgb[i])
			return (ft_perror(gfx->cub, ENOMEM, CRITICAL));
		gfx->rgb[i][R] = 0;
		gfx->rgb[i][G] = 0;
		gfx->rgb[i][B] = 0;
	}
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
