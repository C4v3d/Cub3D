/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/21 17:32:16 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
* FOV: Field Of Vision
* -	Nombre de row de pixels visibles en meme temps
*/
void	calculate_fov(size_t *fov, size_t fov_val, size_t fov_max, size_t aov)
{
	(void)aov;
	(void)fov;
	(void)fov_val;
	(void)fov_max;
}


//static void	update_fov(t_player *plyr, int kc)
//{
//	if (!(kc == I || kc == O))
//		return ;
//	if (kc == I && (plyr->fov_val - 1 > 0 && plyr->fov_val - 1 > 0))
//		plyr->fov_val--;
//}

static void	update_aov(size_t *aov, size_t max_angle, int kc)
{
	if (!(kc == LA || kc == RA))
		return ;
	if (kc == LA && *(aov) == 0 )
		*(aov) = max_angle;
	else if (kc == LA && *(aov) > 0 && *(aov) <= max_angle)
		*(aov) -= 1;
	if (kc == RA && *(aov) == max_angle)
		*(aov) = 0;
	else if (kc == RA && (*(aov) == 0 || *(aov) > 0) && *(aov) < max_angle)
		*(aov) += 1;
	//fprintf(stderr, "👁️‍🗨️ [update_aov]....%s%ld%s\n", YEL, *aov, RESET);
}



void	update_plyr_vision(t_player *plyr, int	kc)
{
	if (!(kc == UA || kc == LA || kc == DA || kc == RA || kc == I || kc == O))
		return ;
	update_aov(&plyr->aov, plyr->fov_max, kc);
	//update_fov(plyr, kc);
	calculate_fov(plyr->fov, plyr->fov_val, plyr->fov_max, plyr->aov);
}
