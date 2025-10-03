/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/03 20:50:30 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool		new_pos_is_valid(t_player *p, int kc, float f)
{
	(void)kc;
	float	fr; //factor remainder

	fr = 100 - f;
	fprintf(stderr, "update_plyr_position | factor: %f | factor remainder: %f\n", f, fr);
	//if (p->aov > 90 && p->aov <= 180)

	//else if (p->aov > 180 && p->aov <= 270)

	//else if (p->aov > 270 && p->aov <= 360)

	//else

	return (true);
}

static float	get_factor(t_player *p)
{
	if (p->aov > 90 && p->aov <= 180)
		return (((p->aov - 90) * 100) / 90);
	else if (p->aov > 180 && p->aov <= 270)
		return (((p->aov - 180) * 100) / 90);
	else if (p->aov > 270 && p->aov <= 360)
		return (((p->aov - 270) * 100) / 90);
	return ((p->aov * 100) / 90);
}

void	update_plyr_position(t_player *p, int	kc)
{
	float	factor;
	float	last_pos[2];

	if (!(kc == W || kc == LA || kc == S || kc == RA))
		return ;
	last_pos[X] = p->pos[X];
	last_pos[Y] = p->pos[Y];
	factor = get_factor(p);
	fprintf(stderr, "update_plyr_position | factor: %f\n", factor);
	if (!new_pos_is_valid(p, kc, factor))
	{
		p->pos[X] = last_pos[X];
		p->pos[Y] = last_pos[Y];
	}
	fprintf(stderr, "| %supdate_plyr_position%s\n| aov: %f\n| pos[X]: %f\n| pos[Y]: %f\n", BLU, RESET, p->aov, p->pos[X], p->pos[Y]);
}
