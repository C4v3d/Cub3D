/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:36:11 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/26 18:09:58 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int game_rendering(t_main *cub)
{
	fprintf(stderr, "game_rendering\n");
	draw_scene(cub);
	draw_minimap(cub);
	return (0);
}
