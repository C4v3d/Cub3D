/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/16 18:35:20 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_g_m_data(t_graphic *g, t_map *m, t_main *cub)
{
	t_color floor;
	t_color ceiling;

	g->cub = cub;
	ft_bzero(&g->txtr_ptr, sizeof(g->txtr_ptr));
	g->colors[FLOOR] = &floor;
	g->colors[CEILING] = &ceiling;
	g->el_counter = 0;
	g->map.img = NULL;
	g->txtr_res = -1;
	m->cub = cub;
	m->grid = ft_calloc(1, sizeof(m->grid));
	if (!m->grid)
		ft_perror(m->cub, ENOMEM, CRITICAL);
	m->dim[X] = 0;
	m->dim[Y] = 0;
	ft_bzero(m->plyr_start_pos, sizeof(m->plyr_start_pos));
	m->plyr_start_ori = 0;
}

static void	init_p_r_data(t_player *p, t_rays *r, t_main *cub)
{
	p->cub = cub;
	r->cub = cub;
	r->delta[X] = 0.0;
	r->delta[Y] = 0.0;
	r->dir[X] = 0.0;
	r->dir[Y] = 0.0;
	r->dist[X] = 0.0;
	r->dist[Y] = 0.0;
	r->map[X] = 0;
	r->map[Y] = 0;
	r->steps[X] = 0.0;
	r->steps[Y] = 0.0;
	r->cam_x = 0.0;
	r->wall_side = 0;
	r->wall_dist = 0;
	r->wall_height = 0;
	p->aov = 0;
	p->fov = 1.4;
	p->ray_len = 0;
}

static int	init_display(t_display *dspl, t_main *cub)
{
	dspl->cub = cub;
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (ft_perror(dspl->cub, errno, CRITICAL));
	dspl->win_dim[X] = WINDOW_WIDTH;
	dspl->win_dim[Y] = WINDOW_HEIGHT;
	dspl->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	mlx_hook(cub->dspl.win, 02, 1L<<0, input_loop, cub);
	mlx_loop_hook(cub->mlx, loop, cub);
	return (0);
}

void	init_cub(t_main *cub)
{
	cub->pr.last_time = 0;
	ft_memset(cub, '\0', sizeof(cub)); /** Setting everything to null */
	cub->pr.close_program = false;
	cub->pr.show_minimap = true;
	init_g_m_data(&cub->gfx, &cub->map, cub);
	init_p_r_data(&cub->plyr, &cub->r, cub);
	init_display(&cub->dspl, cub);
}

int		init_parsed_data(t_main *cub)
{
	cub->plyr.pos[X] = (double)cub->map.plyr_start_pos[X];
	cub->plyr.pos[Y] = (double)cub->map.plyr_start_pos[Y];
	cub->r.plane[Y] = -cub->plyr.dir[X] * tan(cub->plyr.fov / 2.0);
	cub->r.plane[X] =  cub->plyr.dir[Y] * tan(cub->plyr.fov / 2.0);
	update_plyr_vision(&cub->plyr, LA); // TRICKS POUR LANCER LA MACHINE	-> sans ça manque calcul du plane
	update_plyr_vision(&cub->plyr, RA); // TRICKS POUR LANCER LA MACHINE	-> sans ça manque calcul du plane
	update_plyr_position(&cub->plyr, W); // TRICKS POUR LANCER LA MACHINE	-> sans ça CRASH
	update_plyr_position(&cub->plyr, D); // TRICKS POUR LANCER LA MACHINE	-> sans ça CRASH
	return (0);
}
