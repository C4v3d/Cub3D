/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_cal_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:48:05 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/22 17:40:34 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	wall_is_on_axis(t_player *p, char **grid)
{
	int	x_tmp;
	int	y_tmp;

	x_tmp = p->pos[X];
	y_tmp = p->pos[Y];
	if (!(p->aov == 0 || p->aov == EA_RAD || p->aov == NO_RAD
			|| p->aov == WE_RAD || p->aov == SO_RAD))
		return (false);
	if (p->aov == 0)
		while (grid[y_tmp][++x_tmp] != '1')
			p->ray_len++;
	if (p->aov == NO_RAD)
		while (grid[--y_tmp][x_tmp] != '1')
			p->ray_len++;
	if (p->aov == WE_RAD)
		while (grid[y_tmp][--x_tmp] != '1')
			p->ray_len++;
	if (p->aov == SO_RAD)
		while (grid[++y_tmp][x_tmp] != '1')
			p->ray_len++;
	p->ray_len++;
	if (p->aov == 0 || p->aov == WE_RAD)
		p->ray_len += p->tile_pos[X];
	if (p->aov == NO_RAD || p->aov == SO_RAD)
		p->ray_len += p->tile_pos[Y];
	fprintf(stderr, "%swall_is_on_axis | see wall grid[Y]%d[X]%d | dist: %lf%s\n", YEL, y_tmp, x_tmp, p->ray_len, RESET);
	return (true);
}

double	calculate_ray_len(t_player *p, double x, double y)
{
	//fprintf(stderr, "calculate_ray_len | x: %lf | y: %lf\n", x, y);
	if (p->aov >= Q1_2 && p->aov < Q2_2)
		return (get_hypotenus(p->pos[X] - x, p->pos[Y]) - y);
	else if (p->aov >= Q2_2 && p->aov < Q3_2)
		return (get_hypotenus(x - p->pos[X], y - p->pos[Y]));
	else if (p->aov >= Q3_2 && p->aov <= Q4_2)
		return (get_hypotenus(p->pos[X] - x, y - p->pos[Y]));
	else
		return (get_hypotenus(x - p->pos[X], y - p->pos[Y])); //if (p->aov >= 0 && p->aov < Q1_2)
}

void	dda(t_player *p, char **grid, int *x, int *y)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		if (p->r.dist_next_tile[X] < p->r.dist_next_tile[Y])
		{
			p->r.dist_next_tile[X] += p->r.delta[X];
			(*x) += p->r.steps[X];
		}
		else
		{
			p->r.dist_next_tile[Y] += p->r.delta[Y];
			(*y) += p->r.steps[Y];
		}
		if (grid[(*y)][(*x)] == '1')
			hit = true;
	}
}

void	init_main_ray_calculation(t_player *p, int *x_wall, int *y_wall)
{
	p->ray_len = 0;
	p->r.delta[X] = get_delta(p->dir[X]);
	p->r.delta[Y] = get_delta(p->dir[Y]);
	*x_wall = p->pos[X];
	*y_wall = p->pos[Y];
	fprintf(stderr, "init_main_ray... | dir_x: %lf | dir_y: %lf | delta_x: %lf | delta_y: %lf\n", p->dir[X], p->dir[Y], p->r.delta[X], p->r.delta[Y]);
	if (p->dir[X] < 0)
	{
		p->r.steps[X] = -1;
		p->r.dist_next_tile[X] = (p->pos[X] - *x_wall) * p->r.delta[X];
	}
	else
	{
		p->r.steps[X] = 1;
		p->r.dist_next_tile[X] = (*x_wall + 1 - p->pos[X]) * p->r.delta[X];
	}
	if (p->dir[Y] < 0)
	{
		p->r.steps[Y] = 1;
		p->r.dist_next_tile[Y] = (*y_wall + 1 - p->pos[Y]) * p->r.delta[Y];
	}
	else
	{
		p->r.steps[Y] = -1;
		p->r.dist_next_tile[Y] = (p->pos[Y] - *y_wall) * p->r.delta[Y];
	}
}
