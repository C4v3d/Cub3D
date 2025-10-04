/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/04 17:55:27 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool		new_pos_is_valid(t_player *p, int kc, float a_rad)
{
	(void)kc;
	(void)p;
	(void)a_rad;
	//fprintf(stderr, "update_plyr_position | angle in radian: %f\n", a_rad);
	return (true);
}

void	update_plyr_position(t_player *p, int	kc)
{
	float	last_pos[2];

	(void)p;
	if (!(kc == W || kc == LA || kc == S || kc == RA))
		return ;
	last_pos[X] = p->pos[X];
	last_pos[Y] = p->pos[Y];
	p->trgo.a_rad = degrees_to_radians(p);
	p->trgo.cos_a = cos(p->trgo.a_rad);
	p->trgo.sin_a = sin(p->trgo.a_rad);
	if (!new_pos_is_valid(p, kc, p->trgo.a_rad))
	{
		p->pos[X] = last_pos[X];
		p->pos[Y] = last_pos[Y];
	}
	fprintf(stderr, "| %supdate_plyr_position%s\n| a_rad: %lf\n| cos_a: %lf\n| sin_a: %lf\n", BLU, RESET, p->trgo.a_rad, p->trgo.cos_a, p->trgo.sin_a);
	//fprintf(stderr, "| %supdate_plyr_position%s\n| aov: %f\n| pos[X]: %f\n| pos[Y]: %f\n", BLU, RESET, p->aov, p->pos[X], p->pos[Y]);
}
