/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/12/04 11:53:03 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	move(t_player *p, t_rays *r, double move_speed, bool k[N_KEYS])
{
	if (k[W] || k[UA])
	{
		p->pos[X] += p->dir[X] * move_speed;
		p->pos[Y] -= p->dir[Y] * move_speed;
	}
	else if (k[S] || k[DA])
	{
		p->pos[X] -= p->dir[X] * move_speed;
		p->pos[Y] += p->dir[Y] * move_speed;
	}
	if (k[A])
	{
		p->pos[X] -= r->plane[X] * move_speed;
		p->pos[Y] += r->plane[Y] * move_speed;
	}
	else if (k[D])
	{
		p->pos[X] += r->plane[X] * move_speed;
		p->pos[Y] -= r->plane[Y] * move_speed;
	}
}

static bool	moved_through_walls(t_map *m, int op[AXIS],
	double aov, bool k[N_KEYS])
{
	int	i;

	if (k[W] || k[UA])
		i = 1;
	else
		i = -1;
	if ((aov >= 0 && aov < m->no_rad) && (m->grid[op[Y] - i][op[X]] == '1'
		&& m->grid[op[Y]][op[X] + i] == '1'))
		return (true);
	else if ((aov >= m->no_rad && aov < m->we_rad)
		&& (m->grid[op[Y] - i][op[X]] == '1'
		&& m->grid[op[Y]][op[X] - i] == '1'))
		return (true);
	else if ((aov >= m->we_rad && aov < m->so_rad)
		&& (m->grid[op[Y] + i][op[X]] == '1'
		&& m->grid[op[Y]][op[X] - i] == '1'))
		return (true);
	else if ((aov >= m->so_rad && aov < m->ea_rad)
		&& (m->grid[op[Y] + i][op[X]] == '1'
		&& m->grid[op[Y]][op[X] + i] == '1'))
		return (true);
	return (false);
}

static bool	check_new_pos(t_player *p, t_map *m, double old_pos[AXIS],
	bool k[N_KEYS])
{
	int	op[AXIS];
	int	np[AXIS];

	np[X] = (int)p->pos[X];
	np[Y] = (int)p->pos[Y];
	op[X] = (int)old_pos[X];
	op[Y] = (int)old_pos[Y];
	if (!m->grid[np[Y]][np[X]])
		return (false);
	if (m->grid[np[Y]][np[X]] == '1')
		return (false);
	if ((np[X] == op[X] && np[Y] == op[Y]) || (np[X] != op[X] && np[Y] == op[Y])
		|| (np[X] == op[X] && np[Y] != op[Y]))
		return (true);
	if (moved_through_walls(m, op, p->aov, k))
		return (false);
	return (true);
}

bool	update_plyr_position(t_player *p, bool k[N_KEYS])
{
	p->old_pos[X] = p->pos[X];
	p->old_pos[Y] = p->pos[Y];
	move(p, &p->cub->r, p->cub->pr.move_speed, k);
	if (!check_new_pos(p, &p->cub->map, p->old_pos, k))
	{
		p->pos[X] = p->old_pos[X];
		p->pos[Y] = p->old_pos[Y];
		return (false);
	}
	return (true);
}
