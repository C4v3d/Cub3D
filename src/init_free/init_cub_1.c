/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/19 13:53:50 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	init_program_data(t_prog *pr, t_main *cub)
{
	pr->cub = cub;
	pr->close_program = false;
	pr->parser = malloc(sizeof(t_parser));
	if (!pr->parser)
		return (ft_perror(pr->cub, errno, CRITICAL));
	pr->parser->data_scene = malloc(sizeof(t_scene));
	if (!pr->parser->data_scene)
		return (ft_perror(pr->cub, errno, CRITICAL));
	return (0);
}


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
	if (init_player_data(&cub->plyr, cub) != 0)
		return (1);
	if (init_program_data(&cub->pr, cub) != 0)
		return (1);
	if (init_user_inputs(&cub->ctrl, cub) != 0)
		return (1);
	if (init_display(&cub->dspl, cub) != 0)
		return (1);
	if (init_hooks(cub) != 0)
		return (1);
	return (0);
}
