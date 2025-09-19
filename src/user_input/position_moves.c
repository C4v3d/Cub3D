/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/19 14:07:14 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
* -	Déplacement du jouer avec WASD
* -	Comment gérer deux inputs clavier?
* -	Et du coup gérer les déplacements en diagonale?
*/

static int	update_axis(int *axis, int kc)
{
	if (axis[X] + 1 >= INT_MAX || axis[X] - 1 <= INT_MIN
			|| axis[Y] + 1 >= INT_MAX || axis[Y] - 1 <= INT_MIN)
		return (1);
	if (kc == W)
		axis[X]++;
	else if (kc == S)
		axis[X]--;
	else if (kc == A)
		axis[Y]--;
	else if (kc == D)
		axis[Y]++;
	fprintf(stderr, "update_axis axis[X]: %s%d%s\nupdate_axis axis[Y]: %s%d%s\n", YEL, axis[X], RESET, YEL, axis[Y], RESET);
	return (0);
}

// `kc` = keycode
void	update_plyr_pos(t_player *plyr, int	kc)
{
	update_axis(plyr->pos, kc);
}
