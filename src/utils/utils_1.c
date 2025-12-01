/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:57:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/12/01 11:48:55 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	close_window(t_main *cub)
{
	cub->pr.close_program = true;
	return (0);
}

void	welcome_cub3d(void)
{
	printf("===============================================\n");
	printf("           WELCOME TO CUB3D\n");
	printf("===============================================\n");
	printf("---------------CONTROLS-----------------------\n");
	printf("- Move Left and Right:   A, D\n");
	printf("- Move Up and Down:      W, S, Up-Arrow, Down-Arrow\n");
	printf("- Move Vision:           Left-Arrow, Right-Arrow\n");
	printf("- Minimap:               M\n");
	printf("- Quit:                  ESC\n");
	printf("===============================================\n");
}

double	get_delta(double val)
{
	if (val == 0)
		return (fabs(1 / 1e30));
	return (fabs(1 / val));
}
