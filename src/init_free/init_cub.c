/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/23 17:53:38 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_gfx_map_data(t_graphic *gfx, t_map *map, t_main *cub)
{
	gfx->ceiling = ft_calloc(1, sizeof(t_color));
	gfx->floor = ft_calloc(1, sizeof(t_color));
	map->grid = ft_calloc(1, sizeof(map->grid));
	if (!map->grid
		|| !gfx->ceiling
		|| !gfx->floor)
		ft_perror(map->cub, errno, CRITICAL);
	gfx->cub = cub;
	ft_bzero(&gfx->txtr_ptr, sizeof(gfx->txtr_ptr));
	gfx->el_counter = 0;
	gfx->map.img = NULL;
	gfx->txtr_res = -1;
	ft_bzero(map->plyr_start_pos, sizeof(map->plyr_start_pos));
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
	/**
	 * FT_BZERO MON GARS
	 */
	ft_bzero(p, sizeof(p));
	p->fov = 1.4;
	p->cub = cub;

	ft_bzero(r, sizeof(r));
	r->delta[X] = 0.0;
	r->delta[Y] = 0.0;
	r->dir[X] = 0.0;
	r->dir[Y] = 0.0;
	r->dist[X] = 0.0;
	r->dist[Y] = 0.0;
	r->plane[X] = 0.0;
	r->plane[Y] = 0.0;
	r->steps[X] = 0.0;
	r->steps[Y] = 0.0;
	r->map[X] = 0;
	r->map[Y] = 0;
	r->cam_x = 0.0;
	r->wall_side = 0;
	r->wall_dist = 0;
	r->wall_height = 0;
	r->cub = cub;
}

static void	init_display(t_main *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		ft_perror(cub, errno, CRITICAL);
	cub->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	if (!cub->win)
		ft_perror(cub, MLX_FAIL, CRITICAL);
	mlx_hook(cub->win, 02, 1L<<0, input_loop, cub);
	mlx_hook(cub->win, 17, 0L, free_cub, cub);
	mlx_loop_hook(cub->mlx, loop, cub);
}

void	init_cub(t_main *cub)
{
	ft_memset(cub, '\0', sizeof(cub));
	cub->pr.close_program = false;
	cub->pr.show_minimap = true;
	cub->pr.input_file_fd = -1;
	init_gfx_map_data(&cub->gfx, &cub->map, cub);
	init_plyr_rays_data(&cub->plyr, &cub->r, cub);
	init_display(cub);
}

int		init_parsed_data(t_main *cub)
{
	cub->plyr.pos[X] = (double)cub->map.plyr_start_pos[X] + 0.5;
	cub->plyr.pos[Y] = (double)cub->map.plyr_start_pos[Y] - 0.5;
	cub->r.plane[Y] = -cub->plyr.dir[X] * tan(cub->plyr.fov / 2.0);
	cub->r.plane[X] =  cub->plyr.dir[Y] * tan(cub->plyr.fov / 2.0);
	update_plyr_vision(&cub->plyr, LA); // TRICKS POUR LANCER LA MACHINE	-> sans ça manque calcul du plane
	update_plyr_vision(&cub->plyr, RA); // TRICKS POUR LANCER LA MACHINE	-> sans ça manque calcul du plane
	update_plyr_position(&cub->plyr, W); // TRICKS POUR LANCER LA MACHINE	-> sans ça CRASH
	update_plyr_position(&cub->plyr, D); // TRICKS POUR LANCER LA MACHINE	-> sans ça CRASH
	return (0);
}
