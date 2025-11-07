/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:57:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/07 19:37:45 by emonacho         ###   ########.fr       */
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
	printf("- quit:                  Q, ESC\n");
	printf("----------------------------------------------------\n");

}

void	switch_bool(bool *val)
{
	if (*(val) == true)
		*(val) = false;
	else
		*(val) = true;
}
