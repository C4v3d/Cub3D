/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:45:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/09 19:30:41 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_cos_sin(t_player *p)
{
	if (p->aov == 0)
	{
		p->trgo.cos_a = (int)1;
		p->trgo.sin_a = (int)0;
	}
	else if (p->aov == M_PI / 2)
	{
		p->trgo.cos_a = (int)0;
		p->trgo.sin_a = (int)1;
	}
	else if (p->aov == M_PI)
	{
		p->trgo.cos_a = (int)-1;
		p->trgo.sin_a = (int)0;
	}
	else if (p->aov == M_PI * 2)
	{
		p->trgo.cos_a = (int)0;
		p->trgo.sin_a = (int)-1;
	}
	else
	{
		p->trgo.cos_a = cos(p->aov);
		p->trgo.sin_a = sin(p->aov);
		fprintf(stderr, "get_cos_sin | cos: %lf | sin: %lf | rad: %lf\n", p->trgo.cos_a, p->trgo.sin_a, p->aov);
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
