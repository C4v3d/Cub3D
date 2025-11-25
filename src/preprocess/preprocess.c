/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:35:10 by timmi             #+#    #+#             */
/*   Updated: 2025/11/25 14:18:46 by timmi            ###   ########.fr       */
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
 */
void	preprocess(t_main *cub, char *input_file)
{
	if (is_input_valid(input_file) == false)
		exit(1);
	init_cub(cub);
	open_file(cub, input_file);
	parse_file(cub);
	init_parsed_data(cub);
	map_validation(&cub->map);
}
