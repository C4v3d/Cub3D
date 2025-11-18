/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/18 19:42:22 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	move(t_player *p, t_rays *r, double move_speed, int kc)
{
	if (kc == W || kc == UA)
	{
		p->pos[X] += p->dir[X] * move_speed;
		p->pos[Y] -= p->dir[Y] * move_speed;
	}
	else if (kc == S || kc == DA)
	{
		p->pos[X] -= p->dir[X] * move_speed;
		p->pos[Y] += p->dir[Y] * move_speed;
	}
	else if (kc == A)
	{
		p->pos[X] -= r->plane[X] * move_speed;
		p->pos[Y] += r->plane[Y] * move_speed;

	}
	else if (kc == D)
	{
		p->pos[X] += r->plane[X] * move_speed;
		p->pos[Y] -= r->plane[Y] * move_speed;
	}
}

static bool	check_new_pos(double *p, char **grid, size_t *m_dim)
{
	if (!grid[(int)p[Y]][(int)p[X]] || grid[(int)p[Y]][(int)p[X]] == '1')
		return (false);
	//if (p[X] <= 0 || p[X] >= m_dim[X] || p[Y] <= 0 || p[Y] >= m_dim[Y])
	if (p[X] <= 1.000001 || p[X] >= (double)m_dim[X] - 1.000001
		|| p[Y] <= 1.000001 || p[Y] >= (double)m_dim[Y] - 1.000001)
		return (false);
	return (true);
}

static bool	new_pos(t_player *p, double move_speed, int kc)
{
	double	last_pos[AXIS];

	last_pos[X] = p->pos[X];
	last_pos[Y] = p->pos[Y];
	move(p, &p->cub->r, move_speed, kc);
	if (!check_new_pos(p->pos, p->cub->map.grid, p->cub->map.dim))
	{
		p->pos[X] = last_pos[X];
		p->pos[Y] = last_pos[Y];
		return (false);
	}
	return (true);
}

int	update_plyr_position(t_player *p, int kc)
{
	//if (!new_pos(p, p->cub->pr.move_speed, kc))	// ❌ move_speed: marche pas
	//	return (0);
	if (!new_pos(p, POS_MOVE_UNIT, kc))
		return (0);
	return (0);
}
