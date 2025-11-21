/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/21 12:43:36 by emonacho         ###   ########.fr       */
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

static bool	moved_through_walls(double old_pos[AXIS], double new_pos[AXIS], char **grid, double aov)
{
	int	op[AXIS];
	int	np[AXIS];

	op[X] = (int)old_pos[X];
	op[Y] = (int)old_pos[Y];
	np[X] = (int)new_pos[X];
	np[Y] = (int)new_pos[Y];
	if ((np[X] == op[X] && np[Y] == op[Y])
		|| (np[X] != op[X] && np[Y] == op[Y])
			|| (np[X] == op[X] && np[Y] != op[Y]))
		return (false);
	if ((aov >= 0 && aov < NO_RAD) && (grid[op[Y] - 1][op[X]] == '1'
		&& grid[op[Y]][op[X] + 1] == '1'))
		return (printf("1\n"), true);
	else if ((aov >= NO_RAD && aov < WE_RAD) && (grid[op[Y] - 1][op[X]] == '1'
		&& grid[op[Y]][op[X] - 1] == '1'))
		return (printf("2\n"), true);
	else if ((aov >= WE_RAD && aov < SO_RAD) && (grid[op[Y] + 1][op[X]] == '1'
		&& grid[op[Y]][op[X] - 1] == '1'))
		return (printf("3\n"), true);
	else if ((aov >= SO_RAD && aov < EA_RAD) && (grid[op[Y] + 1][op[X]] == '1'
		&& grid[op[Y]][op[X] + 1] == '1'))
		return (printf("4\n"), true);
	return (false);
}

static bool	check_new_pos(t_player *p, double last_pos[AXIS], char **grid, size_t *m_dim)
{
	if (!grid[(int)p->pos[Y]][(int)p->pos[X]]
		|| grid[(int)p->pos[Y]][(int)p->pos[X]] == '1')
		return (false);
	if (p->pos[X] <= 1.000001 || p->pos[X] >= (double)m_dim[X] - 1.000001
		|| p->pos[Y] <= 1.000001 || p->pos[Y] >= (double)m_dim[Y] - 1.000001)
		return (false);
	if (moved_through_walls(last_pos, p->pos, grid, p->aov))
		return (printf("check_new_pos | ⚠️ | p->aov: %lf | grid[Y][X]: %c\n", p->aov, grid[(int)p->pos[Y]][(int)p->pos[X]]), false);
	return (true);
}

bool	update_plyr_position(t_player *p, int kc)
{
	double	last_pos[AXIS];

	last_pos[X] = p->pos[X];
	last_pos[Y] = p->pos[Y];
	move(p, &p->cub->r, POS_MOVE_UNIT, kc);
	if (!check_new_pos(p, last_pos, p->cub->map.grid, p->cub->map.dim))
	{
		p->pos[X] = last_pos[X];
		p->pos[Y] = last_pos[Y];
		return (false);
	}
	return (true);
}
