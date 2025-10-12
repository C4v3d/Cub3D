/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:45:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/12 22:31:54 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	get_angle(double x, double y)
{
	(void)x;
	(void)y;
	return (0);
}

double	extract_double(double n_float)
{
	int n_int;

	n_int = (int)n_float;
	return (n_float - n_int);

}

double	get_hypotenus(double x, double y)
{
	double	hypotenus;

	hypotenus = (x * x) + (y * y);
	return(sqrt(hypotenus));

}

void	get_cos_sin(t_player *p)
{
	if (p->aov == 0)
	{
		p->dir[X] = (int)1;
		p->dir[Y] = (int)0;
	}
	else if (p->aov == M_PI / 2)
	{
		p->dir[X] = (int)0;
		p->dir[Y] = (int)1;
	}
	else if (p->aov == M_PI)
	{
		p->dir[X] = (int)-1;
		p->dir[Y] = (int)0;
	}
	else if (p->aov == M_PI * 2)
	{
		p->dir[X] = (int)0;
		p->dir[Y] = (int)-1;
	}
	else
	{
		p->dir[X] = cos(p->aov);
		p->dir[Y] = sin(p->aov);
	}
}


double	degrees_to_radians(double degrees)
{
	double	radians;	// Angle in radians
	double	pi;

	pi = 3.14159;
	radians = degrees * pi / 180.0;
	return (radians);
}
