/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:45:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/17 16:28:24 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	get_delta(double val)
{
	if (val == 0)
		return (fabs(1 / 1e30));
	return (fabs(1 / val));
}

/*	1 = x++ && y--
*	2 = x-- && y--
*	3 = x-- && y++
*	4 = x++ && y++ */
//🚨 USELESS ❓
float	get_quadrant(double aov)
{
	if (aov >= 0 && aov < Q1_1)
		return (1.1);
	else if (aov >= Q1_1 && aov < Q1_2)
		return (1.2);
	else if (aov >= Q1_2 && aov < Q2_1)
		return (2.1);
	else if (aov >= Q2_1 && aov < Q2_2)
		return (2.2);
	else if (aov >= Q2_2 && aov < Q3_1)
		return (3.1);
	else if (aov >= Q3_1 && aov < Q3_2)
		return (3.2);
	else if (aov >= Q3_2 && aov < Q4_1)
		return (4.1);
	else if (aov >= Q4_1 && aov <= Q4_2)
		return (4.2);
	return (0.0);
}

//🚨 USELESS ❓
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

//🚨 USELESS ❓
double	degrees_to_radians(double degrees)
{
	double	radians;	// Angle in radians
	double	pi;

	pi = 3.14159;
	radians = degrees * pi / 180.0;
	return (radians);
}
