/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/21 14:50:55 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	new_pos_is_valid(size_t *pos, t_map *map)
{
	(void)pos;
	(void)map;
	//if ()
	return (true);
	//pos = last_pos;
	//return (false);
}

static void	get_map_pos(size_t *pos, size_t map_width, size_t map_height, int kc)
{
	if (kc == W && pos[Y] + 1 < map_width)
		pos[Y]++;
	else if (kc == A && pos[X] - 1 > 0)
		pos[X]--;
	else if (kc == S && pos[Y] - 1 > 0)
		pos[Y]--;
	else if (kc == D && pos[X] + 1 < map_height)
		pos[X]++;
	fprintf(stderr, "🗺️  [%smap_pos%s]....X%s%ld%s/%ld Y%s%ld%s/%ld\n", BLU, RESET, YEL, pos[X], RESET, map_width, YEL, pos[Y], RESET, map_height);
}

static bool	get_tile_pos(t_player *p, size_t tile_size, int kc)
{
	if (kc == W)
		return (update_tile_pos(&p->pos_ti[Y], tile_size, '+'));
	else if (kc == A)
		return (update_tile_pos(&p->pos_ti[X], tile_size, '-'));
	else if (kc == S)
		return (update_tile_pos(&p->pos_ti[Y], tile_size, '-'));
	else if (kc == D)
		return (update_tile_pos(&p->pos_ti[X], tile_size, '+'));
	return (false);
}

// `kc` = keycode
void	update_plyr_position(t_player *plyr, int	kc)
{
	size_t	*last_pos_mp;
	size_t	*last_pos_ti;

	if (!(kc == W || kc == A || kc == S || kc == D))
		return ;
	last_pos_mp = plyr->pos_mp;
	last_pos_ti = plyr->pos_ti;
	if (get_tile_pos(plyr, plyr->cub->gfx.txtr_res, kc) == true)
		get_map_pos(plyr->pos_mp, plyr->cub->map.dim[X], plyr->cub->map.dim[Y], kc);
	if (!new_pos_is_valid(plyr->pos_mp, &plyr->cub->map))
	{
		plyr->pos_mp = last_pos_mp;
		plyr->pos_ti = last_pos_ti;
		return ;
	}
	fprintf(stderr, "⬜ [tile_pos]...X%s%ld%sY%s%ld%s/%d\n", YEL, plyr->pos_ti[X], RESET, YEL, plyr->pos_ti[Y], RESET, plyr->cub->gfx.txtr_res);
}
