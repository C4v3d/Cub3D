/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/09 18:10:10 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	new_pos(t_player *p, int kc)
{
	double	last_pos_x;
	double	last_pos_y;

	last_pos_x = p->pos[X];
	last_pos_y = p->pos[Y];
	if (kc == W)
	{
		p->pos[X] -= p->trgo.cos_a * MOVE_UNIT;
		p->pos[Y] -= p->trgo.sin_a * MOVE_UNIT;
	}
	if (kc == S)
	{
		p->pos[X] += p->trgo.cos_a * MOVE_UNIT;
		p->pos[Y] += p->trgo.sin_a * MOVE_UNIT;
	}
	if ((p->pos[X] <= 0 || p->pos[X] >= p->cub->map.dim[X])
		|| (p->pos[Y] <= 0 || p->pos[Y] >= p->cub->map.dim[Y])
			|| p->cub->map.grid[(int)p->pos[Y]][(int)p->pos[X]] == '1')
	{
		p->pos[X] = last_pos_x;
		p->pos[Y] = last_pos_y;
		return (false);
	}
	return (true);
}

int	update_plyr_position(t_player *p, int kc)
{
	if (!(kc == W || kc == LA || kc == S || kc == RA))
		return (0);
	get_cos_sin(p);
	if (!new_pos(p, kc))
		return (fprintf(stderr, "%supdate_plr_position | CAN'T GO THERE%s\n", RED, RESET), 0);
	fprintf(stderr, "| %supdate_plyr_position%s\n| aov: %f\n| pos[X]: %f\n| pos[Y]: %f\n", BLU, RESET, p->aov, p->pos[X], p->pos[Y]);
	return (0);
}
