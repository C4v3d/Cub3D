/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:49:09 by emonacho          #+#    #+#             */
/*   Updated: 2025/12/03 17:12:51 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static double	get_time(void)
{
	struct timeval	clock;
	double		now;

	if (gettimeofday(&clock, NULL))
		return (-1);
	now = clock.tv_usec / 1000;
	now += clock.tv_sec * 1000;
	return (now);
}

int	fps(t_prog *pr)
{
	double	now;
	double	frame_time;

	now = get_time();
	if (now < 0)
		return (-1);
	frame_time = now - pr->last_time;
	fprintf(stderr, "draw_fps | DEBUG | fps: %d\n", (int)frame_time);
	pr->move_speed = frame_time * 0.002;
	pr->rot_speed = frame_time * 0.0009;
	pr->last_time = now;
	return (0);
}
