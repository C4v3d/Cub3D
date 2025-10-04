/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:45:35 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/04 17:55:25 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	degrees_to_radians(t_player *p)
{
	double	a_rad;	//angle in radians
	double	pi;

	pi = 3.14159;
	a_rad = p->aov * pi / 180.0;
	return (a_rad);
}
