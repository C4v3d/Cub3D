/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/20 20:09:55 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
* -	Déplacement de la vision avec les flèches
* -	Comment gérer deux inputs clavier?
* -	get_aov... -> pour modifier `aov` quand 2 touches sont appuyée en
*	même temps (que faire quand c'est 3?)
*/

static int	update_aov(unsigned int *aov, int kc)
{
	if (kc == LA && *(aov) == 0 )
		*(aov) = 360;
	else if (kc == LA && *(aov) > 0 && *(aov) <= 360)
		*(aov) -= 1;
	if (kc == RA && *(aov) == 360)
		*(aov) = 0;
	else if (kc == RA && (*(aov) == 0 || *(aov) > 0) && *(aov) < 360)
		*(aov) += 1;
	return (0);
}

void	update_plyr_vision(t_player *plyr, int	kc)
{
	update_aov(&plyr->aov, kc);
	//update_fov(plyr); -> function to calculate texture tiles in field of vision
	fprintf(stderr, "[update_aov] aov: %s%d%s\n", YEL, plyr->aov, RESET);
}
