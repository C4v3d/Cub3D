/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:35:10 by timmi             #+#    #+#             */
/*   Updated: 2025/09/26 13:51:59 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	preprocess(t_main *cub, char *input_file)
{
	init_cub(cub);
	open_file(cub, input_file);
	fprintf(stderr, "file opened !\n");
	// fprintf(stderr, "gfx : %d", );
	parse_file(cub);
	fprintf(stderr, "file parsed !\n");
	init_parsed_data(cub);
	// log_colors(cub);
}