/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:45:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/08 11:52:07 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_cos_sin(t_player *p)
{
	if (p->aov == 0 || p->aov == 360)
	{
		p->trgo.cos_a = (int)1;
		p->trgo.sin_a = (int)0;
	}
	else if (p->aov == 90)
	{
		p->trgo.cos_a = (int)0;
		p->trgo.sin_a = (int)1;
	}
	else if (p->aov == 180)
	{
		p->trgo.cos_a = (int)-1;
		p->trgo.sin_a = (int)0;
	}
	else if (p->aov == 270)
	{
		p->trgo.cos_a = (int)0;
		p->trgo.sin_a = (int)-1;
	}
	else
	{
		p->trgo.cos_a = cos(p->trgo.a_rad);
		p->trgo.sin_a = sin(p->trgo.a_rad);
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
