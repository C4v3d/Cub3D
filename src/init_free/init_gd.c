/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:14:42 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/17 09:23:33 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	init_graphic_data(t_graphic *gfx)
{
	gfx->txtr = malloc(sizeof(void *) * 4);
	if (!gfx->txtr)
		return (ft_perror(gfx->gd->cub, ENOMEM, CRITICAL));
	return (0);
}

int	init_game_data(t_game *gd)
{
	if (init_graphic_data(&gd->gfx) != 0)
		return (ft_perror(gd->cub, ENOMEM, CRITICAL));
	return (0);
}
