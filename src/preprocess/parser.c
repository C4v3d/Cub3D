/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:07:22 by timmi             #+#    #+#             */
/*   Updated: 2025/11/19 13:33:47 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	parse_file(t_main *cub)
{
	parse_data(&cub->gfx);
	fprintf(stderr, "Data parsed !\n");
	parse_map(&cub->map);
	fprintf(stderr, "Map Parsed !\n");
}