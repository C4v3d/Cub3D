/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:13:47 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/12 17:28:29 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_main_ray_len(t_player *p, t_map *m)
{
	(void)m;
	fprintf(stderr, "get_main_ray_len | pos[X]: %lf | pos[Y]:%lf | dir[X]: %lf | dir[Y]:%lf\n", p->pos[X], p->pos[Y], p->dir[X], p->dir[Y]);
	return (0);
}
