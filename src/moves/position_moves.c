/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/04 19:27:39 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	new_pos(t_player *p, int kc)
{
	fprintf(stderr, "new_pos_is_valid | x: %lf | y: %lf | cos: %lf | sin: %lf\n", p->pos[X], p->pos[Y], p->trgo.cos_a, p->trgo.sin_a);

	//if (kc == W)
	//	if (p->pos[X] + p->trgo.cos_a > p->cub->map.dim[X] && p->pos[Y] + p->trgo.sin_a > p->cub->map.dim[Y])
	//		return (fprintf(stderr, "%sPlayer try to walk ot of map limits%s\n", RED, RESET), false);
	//if (kc == S)
	//	if (p->pos[X] + p->trgo.cos_a < p->cub->map.dim[X] && p->pos[Y] + p->trgo.sin_a < p->cub->map.dim[Y])
	//		return (fprintf(stderr, "%sPlayer try to walk ot of map limits%s\n", RED, RESET), false);
	//if (p->cub->map.grid[(int)(p->pos[Y] + p->trgo.sin_a)][(int)(p->pos[X] + p->trgo.cos_a)] == '1')
	//		return (fprintf(stderr, "%sPlayer try to walk through wall%s\n", RED, RESET), false);
	if (kc == W)
	{
		p->pos[X] -= p->trgo.cos_a;
		p->pos[Y] -= p->trgo.sin_a;
	}
	if (kc == S)
	{
		p->pos[X] += p->trgo.cos_a;
		p->pos[Y] += p->trgo.sin_a;
	}
	return (true);
}

int	update_plyr_position(t_player *p, int kc)
{
	if (!(kc == W || kc == LA || kc == S || kc == RA))
		return (0);
	p->trgo.a_rad = degrees_to_radians(p);
	p->trgo.cos_a = cos(p->trgo.a_rad);
	p->trgo.sin_a = sin(p->trgo.a_rad);
	if (!new_pos(p, kc))
		return (0);
	//fprintf(stderr, "| %supdate_plyr_position%s\n| a_rad: %lf\n| cos_a: %lf\n| sin_a: %lf\n", BLU, RESET, p->trgo.a_rad, p->trgo.cos_a, p->trgo.sin_a);
	fprintf(stderr, "| %supdate_plyr_position%s\n| aov: %f\n| pos[X]: %f\n| pos[Y]: %f\n", BLU, RESET, p->aov, p->pos[X], p->pos[Y]);
	return (0);
}
