/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:13:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/12 19:14:30 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_main_ray_len(t_player *p, t_map *m)
{
	(void)m;
	double	f_pos_x;
	double	f_pos_y;
	double	hyp;

	hyp = 0.0;
	f_pos_x = extract_double(p->pos[X]);
	f_pos_y = extract_double(p->pos[Y]);
	hyp += get_hypotenus(f_pos_x, f_pos_y);
	fprintf(stderr, "get_main_ray_len | pos[X]: %lf | pos[Y]:%lf | dir[X]: %lf | dir[Y]:%lf\n", p->pos[X], p->pos[Y], p->dir[X], p->dir[Y]);
	fprintf(stderr, "get_main_ray_len | f_pos_x: %lf | f_pos_y:%lf | hyp: %lf | \n", f_pos_x, f_pos_y, hyp);
	//while (true)
	//{
	//}
	return (0);
}
