/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/02 13:12:02 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//v1
//static void rotate(double dir[2], double plane[2], double rot_speed)
//{
//	double old_dir_x;
//	double old_plane_x;

//	old_dir_x = dir[X];
//	dir[X] = dir[X] * cos(rot_speed) - dir[Y] * sin(rot_speed);
//	dir[Y] = old_dir_x * sin(rot_speed) + dir[Y] * cos(rot_speed);
//	old_plane_x = plane[X];
//	plane[X] = plane[X] * cos(rot_speed) - plane[Y] * sin(rot_speed);
//	plane[Y] = old_plane_x * sin(rot_speed) + plane[Y] * cos(rot_speed);
//}

//v2
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

static void	update_aov(double *aov, float max_angle, int kc)
{
	if (!(kc == A || kc == D))
		return ;
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
	if (!(kc == A || kc == D || kc == I || kc == O))
		return (0);
	update_aov(&p->aov, AOV_MAX, kc);
	//get_cos_sin(p);
	//if (kc == A)
	//	rotate(p->dir, p->cub->r.plane, -p->cub->pr.rot_speed);
	//else
	//	rotate(p->dir, p->cub->r.plane, p->cub->pr.rot_speed);
	if (kc == A)
		rotate(p->dir, p->cub->r.plane, VIS_MOVE_UNIT);
	else
		rotate(p->dir, p->cub->r.plane, -VIS_MOVE_UNIT);
	fprintf(stderr, "updt_p_vis | aov: %lf | dir[X]: %lf | dir[Y]: %lf\n", p->aov, p->dir[X], p->dir[Y]);
	return (0);
}
