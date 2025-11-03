/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/03 11:44:07 by emonacho         ###   ########.fr       */
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
	gfx->map.img = NULL;
}

static void	init_map_data(t_map *map, t_main *cub)
{
	map->cub = cub;
	map->grid = ft_calloc(1, sizeof(map->grid));
	if (!map->grid)
		ft_perror(map->cub, ENOMEM, CRITICAL);
	map->dim[X] = 0;
	map->dim[Y] = 0;
	ft_bzero(map->plyr_start_pos, sizeof(map->plyr_start_pos));
	map->plyr_start_ori = 0;
}

static void	init_p_r_data(t_player *p, t_rays *r, t_main *cub)
{
	p->cub = cub;
	p->aov = 0;
	p->fov = 0.57735;
	p->ray_len = 0;
	r->cam_x = 0.0;
	r->delta[X] = 0.0;
	r->delta[Y] = 0.0;
	r->dir[X] = 0.0;
	r->dir[Y] = 0.0;
	r->dist[X] = 0.0;
	r->dist[Y] = 0.0;
	r->wall_x = 0.0;
	r->map[X] = 0;
	r->map[Y] = 0;
	r->w_side = 0;
	r->p_w_dist = 0;
	r->line_h = 0;
	r->steps[X] = 0.0;
	r->steps[Y] = 0.0;
}

void	init_cub(t_main *cub)
{
	cub->pr.last_time = 0;
	ft_memset(cub, '\0', sizeof(cub)); /** Setting everything to null */
	cub->pr.close_program = false;
	cub->pr.show_minimap = true;
	init_graphic_data(&cub->gfx, cub);
	init_map_data(&cub->map, cub);
	init_p_r_data(&cub->plyr, &cub->r, cub);
	init_display(&cub->dspl, cub);
	init_hooks(cub);
}
