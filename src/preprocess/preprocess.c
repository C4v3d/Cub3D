/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:35:10 by timmi             #+#    #+#             */
/*   Updated: 2025/10/26 18:05:19 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * Main function for the preprocess.
 * Wrap all the function that
 * are needed in the preprocess phase.
 *
 * Preprocess phase task is to prepare everything
 * for the execution phase.
 * Easy management and debugging since everything
 * is broken down into separeted function !
 *
 * Break down the main struct into 2 separeted
 * area
 *  - Preprocess data
 *  - Execution data
 * might be good idk ?
 */
void	preprocess(t_main *cub, char *input_file)
{
	if (is_input_valid(input_file) == false)
		exit(1);
	init_cub(cub);
	open_file(cub, input_file);
	/*Check if map is before data*/
	parse_file(cub);
	// validate_map(&cub->map);
	init_parsed_data(cub);
	get_cos_sin(&cub->plyr);
	rays_calculation(&cub->plyr, &cub->map);
	draw_minimap(cub);
}
