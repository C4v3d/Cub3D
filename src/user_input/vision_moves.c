/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/03 19:20:13 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"



static void	update_aov(float *aov, float max_angle, int kc)
{
	if (!(kc == A || kc == D))
		return ;
	if (kc == A && *(aov) < 0.01)
		*(aov) = max_angle - MOVE_UNIT;
	else if (kc == A)
		*(aov) -= MOVE_UNIT;
	if (kc == D && *(aov) > max_angle - 0.01)
		*(aov) = MOVE_UNIT;
	else if (kc == D)
		*(aov) += MOVE_UNIT;
	fprintf(stderr, "👁️‍🗨️ [update_aov]....%s%f%s\n", YEL, *aov, RESET);
}



void	update_plyr_vision(t_player *plyr, int	kc)
{
	if (!(kc == A || kc == D || kc == I || kc == O))
		return ;
	update_aov(&plyr->aov, 360, kc);
}
