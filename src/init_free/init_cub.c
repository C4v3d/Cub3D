/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/12/03 16:58:20 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_gfx_map_data(t_graphic *gfx, t_map *map, t_main *cub)
{
	gfx->ceiling = ft_calloc(1, sizeof(t_color));
	gfx->floor = ft_calloc(1, sizeof(t_color));
	if (!gfx->ceiling || !gfx->floor)
		ft_perror(map->cub, 0, CRITICAL);
	ft_bzero(&gfx->txtr_ptr, sizeof(gfx->txtr_ptr));
	gfx->cub = cub;
	gfx->floor->color = -1;
	gfx->ceiling->color = -1;
	gfx->scene.img = NULL;
	gfx->txtr[NO].img = NULL;
	gfx->txtr[SO].img = NULL;
	gfx->txtr[WE].img = NULL;
	gfx->txtr[EA].img = NULL;
	gfx->el_counter = 0;
	gfx->map.img = NULL;
	ft_bzero(map->plyr_start_pos, sizeof(map->plyr_start_pos));
	ft_bzero(&map->r_mini, sizeof(map->r_mini));
	map->grid = NULL;
	map->no_rad = M_PI / 2;
	map->so_rad = M_PI + (M_PI / 2);
	map->we_rad = M_PI;
	map->ea_rad = M_PI * 2;
	map->cub = cub;
	map->dim[X] = 0;
	map->dim[Y] = 0;
}

static void	init_plyr_rays_prog_data(t_player *pl, t_rays *r, t_main *cub, t_prog *pr)
{
	ft_memset(r, '\0', sizeof(t_rays));
	ft_bzero(pr, sizeof(pr));
	pr->move_speed = 0.01;
	pr->rot_speed = 0.01;
	ft_memset(pl, '\0', sizeof(t_player));
	pl->cub = cub;
	pl->old_pos[X] = -1;
	pl->old_pos[Y] = -1;
	r->cub = cub;
	pl->fov = 1.4;
}

static void	init_display(t_main *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		ft_perror(cub, 0, CRITICAL);
	cub->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	if (!cub->win)
		ft_perror(cub, MLX_FAIL, CRITICAL);
	//mlx_hook(cub->win, 02, 1L << 0, input_loop, cub); //v1
	mlx_hook(cub->win, 02, 1L<<0, key_press, cub);		//v2
	mlx_hook(cub->win, 03, 1L<<1, key_release, cub);	//v2
	mlx_hook(cub->win, 17, 0L, close_cub3d, cub);
	mlx_loop_hook(cub->mlx, loop, cub);
}

void	init_cub(t_main *cub)
{
	ft_memset(cub, '\0', sizeof(cub));
	ft_bzero(cub->pr.key_on, sizeof(cub->pr.key_on));
	cub->pr.close_program = false;
	cub->pr.show_minimap = false;
	cub->map.p_pos = false;
	cub->pr.fail = false;
	init_gfx_map_data(&cub->gfx, &cub->map, cub);
	init_plyr_rays_prog_data(&cub->plyr, &cub->r, cub, &cub->pr);
	init_display(cub);
}

int	init_parsed_data(t_main *cub)
{
	cub->plyr.pos[X] = (double)cub->map.plyr_start_pos[X] + 0.5;
	cub->plyr.pos[Y] = (double)cub->map.plyr_start_pos[Y] - 0.5;
	cub->r.plane[Y] = -cub->plyr.dir[X] * tan(cub->plyr.fov / 2.0);
	cub->r.plane[X] = cub->plyr.dir[Y] * tan(cub->plyr.fov / 2.0);
	//update_plyr_vision(&cub->plyr, LA_KC);
	//update_plyr_vision(&cub->plyr, RA_KC);
	//update_plyr_position(&cub->plyr, W_KC);
	//update_plyr_position(&cub->plyr, D_KC);

	// les lignes qui suivent sont facultatives sur 42
	//cub->pr.key_on[LA] = true;
	//update_plyr_vision(&cub->plyr, cub->pr.key_on); // TRICKS POUR LANCER LA MACHINE	-> sans ça manque calcul du plane
	//cub->pr.key_on[LA] = false;
	//cub->pr.key_on[RA] = true;
	//update_plyr_vision(&cub->plyr, cub->pr.key_on); // TRICKS POUR LANCER LA MACHINE	-> sans ça manque calcul du plane
	//cub->pr.key_on[RA] = false;
	//cub->pr.key_on[W] = true;
	//update_plyr_position(&cub->plyr, cub->pr.key_on); // TRICKS POUR LANCER LA MACHINE	-> sans ça CRASH
	//cub->pr.key_on[W] = false;
	//cub->pr.key_on[D] = true;
	//update_plyr_position(&cub->plyr, cub->pr.key_on); // TRICKS POUR LANCER LA MACHINE	-> sans ça CRASH
	//cub->pr.key_on[D] = false;
	return (0);
}
