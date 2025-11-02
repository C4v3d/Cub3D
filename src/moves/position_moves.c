/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/02 12:16:16 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	check_new_pos(double *p, char **grid, size_t *m_dim)
{
	if ((p[X] <= 0 || p[X] >= m_dim[X]) || (p[Y] <= 0 || p[Y] >= m_dim[Y])
			|| grid[(int)p[Y]][(int)p[X]] == '1')
		return (false);
	return (true);
}

static bool	new_pos(t_player *p, double move_speed, int kc)
{
	(void)move_speed;
	double	last_pos[AXIS];

	last_pos[X] = p->pos[X];
	last_pos[Y] = p->pos[Y];
	//fprintf(stderr, "new_pos | move_speed: %lf | POS_MOVE_UNIT: %lf\n", move_speed, POS_MOVE_UNIT);
	if (kc == W)
	{
		//p->pos[X] += p->dir[X] * (int)move_speed;
		//p->pos[Y] += p->dir[Y] * (int)move_speed;
		p->pos[X] += p->dir[X] * POS_MOVE_UNIT;
		p->pos[Y] -= p->dir[Y] * POS_MOVE_UNIT;
	}
	if (kc == S)
	{
		//p->pos[X] -= p->dir[X] * (int)move_speed;
		//p->pos[Y] -= p->dir[Y] * (int)move_speed;
		p->pos[X] -= p->dir[X] * POS_MOVE_UNIT;
		p->pos[Y] += p->dir[Y] * POS_MOVE_UNIT;
	}
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
	int	ret;

	ret = 0;
	if (!(kc == W || kc == LA || kc == S || kc == RA))
		ret = 1;
	if (!ret && !new_pos(p, p->cub->pr.move_speed, kc))
		return (0);
	//p->tile_pos[X] = extract_double(p->pos[X]);
	//p->tile_pos[Y] = extract_double(p->pos[Y]);
	return (0);
}
