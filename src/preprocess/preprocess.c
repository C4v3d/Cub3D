/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:35:10 by timmi             #+#    #+#             */
/*   Updated: 2025/09/19 14:57:04 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	preprocess(t_main *cub, char *input_file)
{	
	init_cub(cub);
	open_file(cub, input_file);
	parse_file(cub);
	fprintf(stderr, "test %d\n", cub->gfx.colors[CEILING]->r);
	fprintf(stderr, "test %d\n", cub->gfx.colors[CEILING]->g);
	fprintf(stderr, "test %d\n", cub->gfx.colors[CEILING]->b);
	fprintf(stderr, "%d", cub->gfx.colors[CEILING]->color);
}