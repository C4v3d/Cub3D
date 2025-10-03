/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:04:33 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/03 14:30:56 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//v2
static bool new_map_pos(t_player *p, t_map *m, int kc)
{
	// ⚠️ addd wall_check
	if (kc == W && (p->pos_mp[Y] + 1) < m->dim[Y])
		p->pos_mp[Y]++;
	else if (kc == LA && (p->pos_mp[X] - 1) > 1)
		p->pos_mp[X]--;
	else if (kc == S && (p->pos_mp[Y] - 1) > 1)
		p->pos_mp[Y]--;
	else if (kc == RA && (p->pos_mp[X] + 1) < m->dim[X])
		p->pos_mp[X]++;
	else
		return (false);
	fprintf(stderr, "🗺️  [%smap_pos%s].......X%s%ld%s/%ld Y%s%ld%s/%ld\n", BLU, RESET, YEL, p->pos_mp[X], RESET, m->dim[X], YEL, p->pos_mp[Y], RESET, m->dim[Y]);
	return (true);
}

//v1
//static bool new_map_pos(t_player *p, t_map *m, int kc)
//{

//	if (kc == W && (p->pos_mp[Y] + 1) < m->dim[Y]
//		&& m->grid[p->pos_mp[X]][p->pos_mp[Y] + 1] == 0)
//		p->pos_mp[Y]++;
//	else if (kc == A && (p->pos_mp[X] - 1) > 1
//		&& m->grid[p->pos_mp[X] - 1][p->pos_mp[Y]] == 0)
//		p->pos_mp[X]--;
//	else if (kc == S && (p->pos_mp[Y] - 1) > 1
//		&& m->grid[p->pos_mp[X]][p->pos_mp[Y] - 1] == 0)
//		p->pos_mp[Y]--;
//	else if (kc == D && (p->pos_mp[X] + 1) < m->dim[X]
//		&& m->grid[p->pos_mp[X] + 1][p->pos_mp[Y]] == 0)
//		p->pos_mp[X]++;
//	else
//		return (false);
//	fprintf(stderr, "🗺️  [%smap_pos%s].......X%s%ld%s/%ld Y%s%ld%s/%ld\n", BLU, RESET, YEL, p->pos_mp[X], RESET, m->dim[X], YEL, p->pos_mp[Y], RESET, m->dim[Y]);
//	return (true);
//}

/*
* mode == '+' ---> increment pos
* mode == '-' ---> decrement pos
*/
static bool	update_tile_pos(size_t *pos, size_t tile_size, char mode)
{
	if (mode == '+')
	{
		if (*pos + 1 > tile_size)
		{
			*pos = 1;
			return (true);
		}
		else if (*pos + 1 <= tile_size)
			(*pos)++;
	}
	else if (mode == '-')
	{
		if (*pos - 1 == 0)
		{
			*pos = tile_size;
			return (true);
		}
		else if (*pos - 1 > 0)
			(*pos)--;
	}
	return (false);
}

static bool	new_tile_pos(t_player *p, size_t tile_size, int kc)
{
	if (kc == W)
		return (update_tile_pos(&p->pos_ti[Y], tile_size, '+'));
	else if (kc == LA)
		return (update_tile_pos(&p->pos_ti[X], tile_size, '-'));
	else if (kc == S)
		return (update_tile_pos(&p->pos_ti[Y], tile_size, '-'));
	else if (kc == RA)
		return (update_tile_pos(&p->pos_ti[X], tile_size, '+'));
	return (false);
}

void	update_plyr_position(t_player *plyr, int	kc)
{
	size_t	last_pos_ti[2];

	if (!(kc == W || kc == RA || kc == S || kc == LA))
		return ;
	last_pos_ti[X] = plyr->pos_ti[X];
	last_pos_ti[Y] = plyr->pos_ti[Y];
	if (new_tile_pos(plyr, plyr->cub->gfx.txtr_res, kc) == true)
	{
		if (new_map_pos(plyr, &plyr->cub->map, kc) == false)
		{
			plyr->pos_ti[X] = last_pos_ti[X];
			plyr->pos_ti[Y] = last_pos_ti[Y];
			fprintf(stderr, "🟥 %sHIT A WALL! RESET to:%s\n", RED, RESET);
			fprintf(stderr, "🟥 🗺️  [map_pos]....X%s%ld%s/%ld Y%s%ld%s/%ld\n", YEL, plyr->pos_mp[X], RESET, plyr->cub->map.dim[X], YEL, plyr->pos_mp[Y], RESET, plyr->cub->map.dim[Y]);
			fprintf(stderr, "🟥 🔲 [tile_pos]...X%s%ld%s/%d Y%s%ld%s/%d\n", YEL, plyr->pos_ti[X], RESET, plyr->cub->gfx.txtr_res, YEL, plyr->pos_ti[Y], RESET, plyr->cub->gfx.txtr_res);
			fprintf(stderr, "🟥 %s.....................%s\n", RED, RESET);
			return ;
		}
	}
	draw_minimap(plyr->cub);
	fprintf(stderr, "🔲 [tile_pos]......X%s%ld%s/%d Y%s%ld%s/%d\n", YEL, plyr->pos_ti[X], RESET, plyr->cub->gfx.txtr_res, YEL, plyr->pos_ti[Y], RESET, plyr->cub->gfx.txtr_res);
}
