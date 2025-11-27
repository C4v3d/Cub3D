/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/27 09:51:51 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_gfx_map_data(t_graphic *gfx, t_map *map, t_main *cub)
{
	gfx->ceiling = ft_calloc(1, sizeof(t_color));
	gfx->floor = ft_calloc(1, sizeof(t_color));
	map->grid = NULL;
	if (!gfx->ceiling || !gfx->floor)
		ft_perror(map->cub, 0, CRITICAL);
	gfx->cub = cub;
	ft_bzero(&gfx->txtr_ptr, sizeof(gfx->txtr_ptr));
	gfx->el_counter = 0;
	gfx->map.img = NULL;
	gfx->txtr_res = -1;
	ft_bzero(map->plyr_start_pos, sizeof(map->plyr_start_pos));
	map->no_rad = M_PI / 2;
	map->so_rad = M_PI + (M_PI / 2);
	map->we_rad = M_PI;
	map->ea_rad = M_PI * 2;
	gfx->cub = cub;
	gfx->el_counter = 0;
	gfx->scene.img = NULL;
	ft_bzero(&map->r_mini, sizeof(map->r_mini));
	map->cub = cub;
	map->dim[X] = 0;
	map->dim[Y] = 0;
}

static void	init_plyr_rays_data(t_player *p, t_rays *r, t_main *cub)
{
	ft_memset(p, '\0', sizeof(t_player));
	ft_memset(r, '\0', sizeof(t_rays));
	p->cub = cub;
	r->cub = cub;
	p->fov = 1.4;
}

// static void	init_plyr_rays_data(t_player *p, t_rays *r, t_main *cub)
// {
// 	/**
// 	 * FT_BZERO MON GARS
// 	 */
// 	p->cub = cub;
// 	r->cub = cub;
// 	r->delta[X] = 0.0;
// 	r->delta[Y] = 0.0;
// 	r->dir[X] = 0.0;
// 	r->dir[Y] = 0.0;
// 	r->dist[X] = 0.0;
// 	r->dist[Y] = 0.0;
// 	r->map[X] = 0;
// 	r->map[Y] = 0;
// 	r->steps[X] = 0.0;
// 	r->steps[Y] = 0.0;
// 	r->cam_x = 0.0;
// 	r->wall_side = 0;
// 	r->wall_dist = 0;
// 	r->wall_height = 0;
// 	p->aov = 0;
// 	p->fov = 1.4;
// }

static void	init_display(t_main *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		ft_perror(cub, errno, CRITICAL);
	cub->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	if (!cub->win)
		ft_perror(cub, MLX_FAIL, CRITICAL);
	mlx_hook(cub->win, 02, 1L << 0, input_loop, cub);
	mlx_hook(cub->win, 17, 0L, free_cub, cub);
	mlx_loop_hook(cub->mlx, loop, cub);
}

void	init_cub(t_main *cub)
{
	ft_memset(cub, '\0', sizeof(cub));
	cub->pr.close_program = false;
	cub->pr.show_minimap = false;
	init_gfx_map_data(&cub->gfx, &cub->map, cub);
	init_plyr_rays_data(&cub->plyr, &cub->r, cub);
	init_display(cub);
}

int	init_parsed_data(t_main *cub)
{
	cub->plyr.pos[X] = (double)cub->map.plyr_start_pos[X] + 0.5;
	cub->plyr.pos[Y] = (double)cub->map.plyr_start_pos[Y] - 0.5;
	cub->r.plane[Y] = -cub->plyr.dir[X] * tan(cub->plyr.fov / 2.0);
	cub->r.plane[X] = cub->plyr.dir[Y] * tan(cub->plyr.fov / 2.0);
	update_plyr_vision(&cub->plyr, LA);
	update_plyr_vision(&cub->plyr, RA);
	update_plyr_position(&cub->plyr, W);
	update_plyr_position(&cub->plyr, D);
	return (0);
}
