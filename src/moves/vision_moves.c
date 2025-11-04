/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/04 12:51:01 by emonacho         ###   ########.fr       */
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

static void	update_fov(t_player *p, t_rays *r, int kc)
{
	double	unit;

	unit = 0.01;
	if (kc == I && p->fov - unit >= 0.01)
		p->fov -= unit;
	else if (kc == O && p->fov + unit <= 3.0)
		p->fov += unit;
	r->plane[Y] = -p->dir[X] * tan(p->fov / 2.0);
	r->plane[X] =  p->dir[Y] * tan(p->fov / 2.0);
}

static void	update_aov(double *aov, float max_angle, int kc)
{
	if (kc == A && *(aov) + VIS_MOVE_UNIT >= max_angle - VIS_MOVE_UNIT)
		*(aov) = 0;
	else if (kc == A)
		*(aov) += VIS_MOVE_UNIT;
	else if (kc == D && *(aov) - VIS_MOVE_UNIT <= 0)
		*(aov) = max_angle - VIS_MOVE_UNIT;
	else if (kc == D)
		*(aov) -= VIS_MOVE_UNIT;
}

int	update_plyr_vision(t_player *p, int	kc)
{
	if (kc == A || kc == D)
		update_aov(&p->aov, AOV_MAX, kc);
	else if (kc == I || kc == O)
		update_fov(p, &p->cub->r, kc);
	if (kc == A)
		rotate(p->dir, p->cub->r.plane, VIS_MOVE_UNIT);
	else if (kc == D)
		rotate(p->dir, p->cub->r.plane, -VIS_MOVE_UNIT);
	return (0);
}
