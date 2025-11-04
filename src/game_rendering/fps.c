/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:49:09 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/04 12:26:22 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	get_time(void)
{
	struct timeval	clock;
	double		now;

	if (gettimeofday(&clock, NULL))
		return (-1);
	now = clock.tv_usec / 1000;
	now += clock.tv_sec * 1000;
	return (now);
}

int	draw_fps(t_main *cub, t_image *img)
{
	(void)img;
	double	now;
	//double	frame_time;

	now = get_time();
	if (now < 0)
		return (-1);
	//frame_time = now - cub->pr.last_time;	//BUGGY🪲
	//fprintf(stderr, "draw_fps | DEBUG | fps: %d\n", (int)frame_time);
	//cub->pr.move_speed = frame_time * 0.001;	//BUGGY🪲
	//cub->pr.rot_speed = frame_time * 0.001;	//BUGGY🪲
	cub->pr.last_time = now;
	return (0);
}
