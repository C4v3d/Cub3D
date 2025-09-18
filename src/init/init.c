/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:08:08 by timmi             #+#    #+#             */
/*   Updated: 2025/09/16 14:40:45 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_cub(t_cub *cub)
{
	cub->data_scene.textures.no = NULL;
	cub->data_scene.textures.so = NULL;
	cub->data_scene.textures.ea = NULL;
	cub->data_scene.textures.we = NULL;
}