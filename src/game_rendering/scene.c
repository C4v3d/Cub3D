/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:28:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/27 12:07:48 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//static int	draw_walls(t_main *cub, t_player *p, t_image *img, int line_h)
//{
//	int	h;
//	int	draw_start;
//	int	draw_end;

//	h = WINDOW_HEIGHT;
//	draw_start = -line_h / 2 + h / 2;
//	if (draw_start < 0)
//		draw_start = 0;
//	draw_end = line_h / 2 + h / 2;
//	if (draw_end >= h)
//		draw_end = h -1;
//	int color;
//	switch(cub->map.grid[p->r.w_seen[Y]][p->r.w_seen[X]])
//	{
//		case 1:  color = RED;	break; //red
//		case 2:  color = GRN;	break; //green
//		case 3:  color = BLU;	break; //blue
//		case 4:  color = CYN;	break; //cyan
//		default: color = YEL;	break; //yellow
//	}
//	//give x and y sides different brightness
//	if(p->r.w_side == 1 || p->r.w_side == 0)
//		color = color / 2;
//	//draw the pixels of the stripe as a vertical line
//	verLine(x, draw_start, draw_end, color);
//	return (0);
//}

static int	draw_background(t_main *cub, t_image *img)
{
	//v1
	//size_t	pos[AXIS];

	//pos[X] = 0;
	//pos[Y] = 0;
	//paint(img, cub->dspl.win_dim, pos, cub->gfx.colors[1]->color);
	//pos[X] = WINDOW_WIDTH / 2;
	//pos[Y] = WINDOW_HEIGHT / 2;
	//paint(img, cub->dspl.win_dim, pos, cub->gfx.colors[0]->color);

	//v2
	paint(img, cub->dspl.win_dim,
		(size_t[]){0, 0}, cub->gfx.colors[1]->color);
	paint(img, cub->dspl.win_dim,
		(size_t[]){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2},
			cub->gfx.colors[0]->color);
	return (0);
}

int	draw_scene(t_main *cub)
{
	draw_background(cub, &cub->gfx.map);
	//draw_walls(cub, &cub->plyr, &cub->gfx.map, &cub->plyr.r.line_h);
	return (0);
}
