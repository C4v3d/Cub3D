/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:07:22 by timmi             #+#    #+#             */
/*   Updated: 2025/09/30 11:56:26 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	parse_file(t_main *cub)
{
	parse_data(&cub->gfx);
	fprintf(stderr, "parsed data\n");
	parse_map(&cub->map);
	return (0);
}