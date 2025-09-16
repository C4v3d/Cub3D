/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/16 23:09:21 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	init_game_data(t_game *gd)
{
	(void)gd;
	return (0);
}

int	init_cub(t_main *cub)
{
	int	ret;

	ret = 0;
	if (!ret && init_game_data(&cub->gd) != 0)
		ret = 1;
	if (ret)
		free_cub(cub);
	return (0);
}
