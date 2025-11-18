/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/18 16:44:21 by emonacho         ###   ########.fr       */
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

static void	update_aov(double *aov, float max_angle, double rot_speed, int kc)
{
	if (kc == LA && *(aov) + rot_speed >= max_angle - rot_speed)
		*(aov) = 0;
	else if (kc == LA)
		*(aov) += rot_speed;
	else if (kc == RA && *(aov) - rot_speed <= 0)
		*(aov) = max_angle - rot_speed;
	else if (kc == RA)
		*(aov) -= rot_speed;
}

//v2 work but not so smooth
//int	update_plyr_vision(t_player *p, int	kc)
//{
//	//❌ sur map_test: bug d'affichage lorsque le joueur avance tout droit sans bouger l'angle de vision
//	if (kc == LA || kc == RA)
//		update_aov(&p->aov, AOV_MAX, p->cub->pr.rot_speed, kc);
//	else if (kc == I || kc == O)
//		update_fov(p, &p->cub->r, kc);
//	if (kc == LA)
//		rotate(p->dir, p->cub->r.plane, p->cub->pr.rot_speed);
//	else if (kc == RA)
//		rotate(p->dir, p->cub->r.plane, -p->cub->pr.rot_speed);
//	return (0);
//}

//v1
int	update_plyr_vision(t_player *p, int	kc)
{
	//❌ sur map_test: bug d'affichage lorsque le joueur avance tout droit sans bouger l'angle de vision
	if (kc == LA || kc == RA)
		update_aov(&p->aov, AOV_MAX, VIS_MOVE_UNIT, kc);
	else if (kc == I || kc == O)
		update_fov(p, &p->cub->r, kc);
	if (kc == LA)
		rotate(p->dir, p->cub->r.plane, VIS_MOVE_UNIT);
	else if (kc == RA)
		rotate(p->dir, p->cub->r.plane, -VIS_MOVE_UNIT);
	return (0);
}
