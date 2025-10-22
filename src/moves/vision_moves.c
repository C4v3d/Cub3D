/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/22 15:08:47 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	update_aov(double *aov, float max_angle, int kc)
{
	float	move_unit;

	move_unit = 0.05;
	if (!(kc == A || kc == D))
		return ;
	if (kc == A && *(aov) + move_unit >= max_angle - move_unit)
		*(aov) = 0;
	else if (kc == A)
		*(aov) += move_unit;
	else if (kc == D && *(aov) - move_unit <= 0)
		*(aov) = max_angle - move_unit;
	else if (kc == D)
		*(aov) -= move_unit;
}



int	update_plyr_vision(t_player *p, int	kc)
{
	if (!(kc == A || kc == D || kc == I || kc == O))
		return (0);
	update_aov(&p->aov, AOV_MAX, kc);
	return (0);
}
