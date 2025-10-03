/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/03 15:36:39 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	update_aov(size_t *aov, size_t max_angle, int kc)
{
	if (!(kc == A || kc == D))
		return ;
	if (kc == A && *(aov) == 0 )
		*(aov) = max_angle;
	else if (kc == A && *(aov) > 0 && *(aov) <= max_angle)
		*(aov) -= 1;
	if (kc == D && *(aov) == max_angle)
		*(aov) = 0;
	else if (kc == D && (*(aov) == 0 || *(aov) > 0) && *(aov) < max_angle)
		*(aov) += 1;
	fprintf(stderr, "👁️‍🗨️ [update_aov]....%s%ld%s\n", YEL, *aov, RESET);
}



void	update_plyr_vision(t_player *plyr, int	kc)
{
	if (!(kc == A || kc == D || kc == I || kc == O))
		return ;
	update_aov(&plyr->aov, 360, kc);
}
