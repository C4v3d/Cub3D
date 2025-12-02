/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .v1vision_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/12/02 07:13:49 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void rotate(double dir[2], double plane[2], double rot_speed)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = dir[X];
	dir[X] = dir[X] * cos(rot_speed) - dir[Y] * sin(rot_speed);
	dir[Y] = old_dir_x * sin(rot_speed) + dir[Y] * cos(rot_speed);
	old_plane_x = plane[X];
	plane[X] = plane[X] * cos(rot_speed) - plane[Y] * sin(rot_speed);
	plane[Y] = old_plane_x * sin(rot_speed) + plane[Y] * cos(rot_speed);
}

static void	update_aov(double *aov, float max_angle, double rot_speed, int kc)
{
	if (kc == LA_KC && *(aov) + rot_speed >= max_angle - rot_speed)
		*(aov) = 0;
	else if (kc == LA_KC)
		*(aov) += rot_speed;
	else if (kc == RA_KC && *(aov) - rot_speed <= 0)
		*(aov) = max_angle - rot_speed;
	else if (kc == RA_KC)
		*(aov) -= rot_speed;
}

void	update_plyr_vision(t_player *p, int	kc)
{
	if (kc == LA_KC || kc == RA_KC)
		update_aov(&p->aov, AOV_MAX, VIS_MOVE_UNIT, kc);
	if (kc == LA_KC)
		rotate(p->dir, p->cub->r.plane, VIS_MOVE_UNIT);
	else if (kc == RA_KC)
		rotate(p->dir, p->cub->r.plane, -VIS_MOVE_UNIT);
}
