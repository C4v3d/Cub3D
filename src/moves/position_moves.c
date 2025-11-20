/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/20 18:19:35 by emonacho         ###   ########.fr       */
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

static bool	check_new_pos(t_player *p, double last_pos[AXIS], char **grid, size_t *m_dim)
{
	if (!grid[(int)p->pos[Y]][(int)p->pos[X]] || grid[(int)p->pos[Y]][(int)p->pos[X]] == '1')
		return (false);
	if (p->pos[X] <= 1.000001 || p->pos[X] >= (double)m_dim[X] - 1.000001
		|| p->pos[Y] <= 1.000001 || p->pos[Y] >= (double)m_dim[Y] - 1.000001)
		return (false);
	// check diagonal wall collision -> WIP
	(void)last_pos;
	//if (p->aov >= 0 && p->aov < NO_RAD )
	return (true);
}

static bool	new_pos(t_player *p, double move_speed, int kc)
{
	double	last_pos[AXIS];

	last_pos[X] = p->pos[X];
	last_pos[Y] = p->pos[Y];
	move(p, &p->cub->r, move_speed, kc);
	if (!check_new_pos(p, last_pos, p->cub->map.grid, p->cub->map.dim))
	{
		p->pos[X] = last_pos[X];
		p->pos[Y] = last_pos[Y];
		return (false);
	}
	return (true);
}

void	update_plyr_position(t_player *p, int kc)
{
	new_pos(p, POS_MOVE_UNIT, kc);
}
