/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:07:22 by timmi             #+#    #+#             */
/*   Updated: 2025/10/03 12:07:38 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	parse_file(t_main *cub)
{
	parse_data(&cub->gfx);
	fprintf(stderr, GRN"Data parsed\n"RESET);
	parse_map(&cub->map);
	fprintf(stderr, GRN"Map parsed\n"RESET);
	log_map_data(cub);
}