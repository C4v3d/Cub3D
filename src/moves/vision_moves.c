/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/26 19:32:46 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	return (0);
}
