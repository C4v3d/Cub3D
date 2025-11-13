/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:36:11 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/13 19:27:26 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//void	draw_texture_line(t_image *img, int x, int start, int end, int col)
//{
//	int	y_i;

//	y_i = start;
//	while (y_i <= end)
//		my_mlx_pixel_put(img, x, y_i++, col);
//}

void	draw_background(t_image *img)
{
	size_t	pos[AXIS];
	size_t	dim[AXIS];

	pos[X] = 0;
	pos[Y] = 0;
	dim[X] = 1280;
	dim[Y] = WINDOW_HEIGHT / 2;
	//draw(img, cub->dspl.win_dim, pos, cub->gfx.colors[1]->color);	//❌ BUG avec cub->gfx.colors[]->color
	draw(img, dim, pos, 0xA8FFFA);
	pos[Y] = WINDOW_HEIGHT / 2;
	dim[Y] = WINDOW_HEIGHT;
	//draw(img, cub->dspl.win_dim, pos, cub->gfx.colors[0]->color);	//❌ BUG avec cub->gfx.colors[]->color
	draw(img, dim, pos, 0xC2FFA8);
}

//void	draw_texture(t_main *cub, t_rays *r, t_image *img, int x)
//{
//	int	start;
//	int	end;


//	start = -r->wall_height / 2 + WINDOW_HEIGHT / 2;
//	if (start < 0)
//		start = 0;
//	end = r->wall_height / 2 + WINDOW_HEIGHT / 2;
//	if (end >= WINDOW_HEIGHT)
//		end = WINDOW_HEIGHT - 1;
//	if (r->wall_side == NO)
//		//draw_untextured_line(img, x, start, end, col0);
//	else if (r->wall_side == SO)
//		//draw_untextured_line(img, x, start, end, col2);
//	else if (r->wall_side == EA)
//		//draw_untextured_line(img, x, start, end, col3);
//	else
//		draw_untextured_line(img, x, start, end, col1);
//}

//❌ untextured
void	draw_untextured_line(t_image *img, int x, int start, int end, int col)
{
	int	y_i;

	y_i = start;
	while (y_i <= end)
		my_mlx_pixel_put(img, x, y_i++, col);
}

void	draw_untextured(t_main *cub, t_rays *r, t_image *img, int x)
{
	int	col1 = 0xFDE8F8;
	int	col2 = 0xF693DD;
	int	col3 = 0xEE3FC2;
	int	col0 = 0xC01194;
	(void)cub;

	int	start;
	int	end;

	start = -r->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = r->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (end >= WINDOW_HEIGHT)
		end = WINDOW_HEIGHT - 1;
	if (r->wall_side == 0)
		draw_untextured_line(img, x, start, end, col0);
	else if (r->wall_side == 2)
		draw_untextured_line(img, x, start, end, col2);
	else if (r->wall_side == 3)
		draw_untextured_line(img, x, start, end, col3);
	else
		draw_untextured_line(img, x, start, end, col1);
}

//v1 WORKING
void	init_ray_calculation(t_rays *r, t_player *p)
{
	if (r->dir[X] < 0)
	{
		r->steps[X] = -1;
		r->dist[X] = (p->pos[X] - r->map[X]) * r->delta[X];
	}
	else
	{
		r->steps[X] = 1;
		r->dist[X] = (r->map[X] + 1.0 - p->pos[X]) * r->delta[X];
	}
	if (r->dir[Y] < 0)
	{
		r->steps[Y] = 1;
		r->dist[Y] = (r->map[Y] + 1.0 - p->pos[Y]) * r->delta[Y];
	}
	else
	{
		r->steps[Y] = -1;
		r->dist[Y] = (p->pos[Y] - r->map[Y]) * r->delta[Y];
	}
}

void	init_draw(t_rays *r, t_player *p)
{
	if (r->wall_side == 0)
		r->wall_dist = (r->dist[X] - r->delta[X]);
	else
		r->wall_dist = (r->dist[Y] - r->delta[Y]);
	r->wall_height = (int)(WINDOW_HEIGHT / r->wall_dist);
	r->wall_side = check_wall_side(r->wall_side, p->pos, r->map, p->aov);
}

void	init_dda(t_rays *r, t_player *p, int x)
{
	r->cam_x = 2 * (double)x / (double)WINDOW_WIDTH - 1;
	r->dir[X] = p->dir[X] + r->plane[X] * r->cam_x;
	r->dir[Y] = p->dir[Y] + r->plane[Y] * r->cam_x;
	r->map[X] = (int)p->pos[X];
	r->map[Y] = (int)p->pos[Y];
	r->delta[X] = get_delta(r->dir[X]);
	r->delta[Y] = get_delta(r->dir[Y]);
	r->wall_side = -1;
	init_ray_calculation(r, p);
}

int		draw_scene(t_main *cub, t_rays *r, t_player *p, t_image *img)
{
	int	x;

	x = -1;
	while (++x <= WINDOW_WIDTH)
	{
		if (x == WINDOW_WIDTH / 2)					//❌ fix temporaire: repenser le calcul des distances pour les visions en ligne droite
			//draw_texture(cub, r, img, x);	//❌ fix temporaire: repenser le calcul des distances pour les visions en ligne droite
			draw_untextured(cub, r, img, x);	//❌ fix temporaire: repenser le calcul des distances pour les visions en ligne droite
		else
		{
			init_dda(r, p, x);
			//if (!wall_is_on_axis(r, p, cub->map.grid))	//❌ fix temporaire: repenser le calcul des distances pour les visions en ligne droite
			dda(r, cub->map.grid);
			init_draw(r, p);
			//draw_texture(cub, r, img, x);
			draw_untextured(cub, r, img, x);	//❌ untextured
		}
		//fprintf(stderr, "draw_scene | x: %d | wall_heighteight: %d | cam_x: %lf\n", x, r->wall_height, r->cam_x);
	}
	return (0);
}
