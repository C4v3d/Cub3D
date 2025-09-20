/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/20 20:33:45 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
* -	Déplacement du jouer avec WASD
* -	Comment gérer deux inputs clavier?
* -	Et du coup gérer les déplacements en diagonale?
*/

static bool	is_valid_pos(int *pos, int *last_pos, t_map *map)
{
	(void)pos;
	(void)last_pos;
	(void)map;
	//if ()
	return (true);
	//pos = last_pos;
	//return (false);
}

static int	update_axis(int *pos, int kc)
{
	if (pos[X] + 1 >= INT_MAX || pos[X] - 1 <= INT_MIN
			|| pos[Y] + 1 >= INT_MAX || pos[Y] - 1 <= INT_MIN)
		return (1);
	if (kc == W)
		pos[X]++;
	else if (kc == S)
		pos[X]--;
	else if (kc == A)
		pos[Y]--;
	else if (kc == D)
		pos[Y]++;
	return (0);
}

// `kc` = keycode
void	update_plyr_position(t_player *plyr, int	kc)
{
	int	*last_pos;

	last_pos = plyr->pos;
	update_axis(plyr->pos, kc);
	fprintf(stderr, "[update_axis] X%s%d%s/Y%s%d%s\n", YEL, plyr->pos[X], RESET, YEL, plyr->pos[Y], RESET);
	if (!is_valid_pos(plyr->pos, last_pos, &plyr->cub->map))
		return ;
}
