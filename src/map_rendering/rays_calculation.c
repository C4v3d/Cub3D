/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:13:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/16 15:06:45 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	main_ray(t_player *p, t_map *m)
{
	(void)m;
	//double	del_dist_x;	// delta distance
	//double	del_dist_y;	// delta distance
	//double	nxt_nter_x;	// next intersection
	//double	nxt_nter_y;	// next intersection

	//del_dist_x = get_delta(p->dir[X]);
	//del_dist_y = get_delta(p->dir[Y]);
	//fprintf(stderr, "get_main_ray_len | del_dist_x: %lf | del_dist_x: %lf\n", del_dist_x, del_dist_y);
	p->r.del_x = get_delta(p->dir[X]);
	p->r.del_y = get_delta(p->dir[Y]);
	fprintf(stderr, "get_main_ray_len | del_dist_x: %lf | del_dist_x: %lf\n", p->r.del_x, p->r.del_y);
	return (0);
}

int	rays_calculation(t_player *p, t_map *m)
{
	(void)m;
	//double	f_pos_x;
	//double	f_pos_y;
	//double	hyp;
	//float	quadrant;

	//quadrant = get_quadrant(p->aov);
	//hyp += get_hypotenus(f_pos_x, f_pos_y);
	//hyp = 0.0;
	//f_pos_x = extract_double(p->pos[X]);
	//f_pos_y = extract_double(p->pos[Y]);
	//fprintf(stderr, "get_main_ray_len | pos[X]: %lf | pos[Y]:%lf | dir[X]: %lf | dir[Y]:%lf\n", p->pos[X], p->pos[Y], p->dir[X], p->dir[Y]);
	//fprintf(stderr, "get_main_ray_len | quadrant: %f | f_pos_x: %lf | f_pos_y:%lf | hyp: %lf | \n", quadrant, f_pos_x, f_pos_y, hyp);

	main_ray(p, m);

	return (0);
}
