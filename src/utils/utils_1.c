/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:57:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/12/01 16:03:01 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	welcome_cub3d(void)
{
	printf("----------------------------------------------------\n");
	printf("CUB3D\n");
	printf("----------------------CONTROLS----------------------\n");
	printf("- move left and right:   A, D\n");
	printf("- move up and down:      W, S, up-arrow, down-arrow\n");
	printf("- move vision:           left-arrow, right-arrow\n");
	printf("- increase/decrease FOV: O, I\n");
	printf("- minimap:               M\n");
	printf("- quit:                  ESC\n");
	printf("----------------------------------------------------\n");

}

void	switch_bool(bool *val)
{
	if (*(val) == true)
		*(val) = false;
	else
		*(val) = true;
}

double	get_delta(double val)
{
	if (val == 0)
		return (fabs(1 / 1e30));
	return (fabs(1 / val));
}
