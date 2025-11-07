/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:57:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/07 18:53:48 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	welcome_cub3d(void)
{
	printf("----------------------------------------------------\n");
	printf("CUB3D\n");
	printf("----------------------CONTROLS----------------------\n");
	printf("- W-A-S-D keys to move up, down, left and right\n");
	printf("- Left and right arrows to move vision\n");
	printf("- O-I keys to increase/decrease FOV\n");
	printf("- M key to turn off/on minimap\n");
	printf("- ESC-Q to quit the game\n");
	printf("----------------------------------------------------\n");

}

void	switch_bool(bool *val)
{
	if (*(val) == true)
		*(val) = false;
	else
		*(val) = true;
}
