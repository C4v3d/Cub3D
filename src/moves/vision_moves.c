/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/08 11:46:18 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	update_aov(double *aov, float max_angle, int kc)
{
	if (!(kc == A || kc == D))
		return ;
	if (kc == A && *(aov) >= max_angle)
		*(aov) = 0;
	else if (kc == A)
		*(aov) += 1;
	else if (kc == D && *(aov) < 0.01)
		*(aov) = max_angle - 1;
	else if (kc == D)
		*(aov) -= 1;
	if (*(aov) == max_angle)
		*(aov) = 0;
	fprintf(stderr, "👁️‍🗨️ [update_aov]....%s%f%s\n", YEL, *aov, RESET);
}



int	update_plyr_vision(t_player *plyr, int	kc)
{
	if (!(kc == A || kc == D || kc == I || kc == O))
		return (0);
	update_aov(&plyr->aov, 360, kc);
	return (0);
}
