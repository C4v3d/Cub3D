/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:35:10 by timmi             #+#    #+#             */
/*   Updated: 2025/10/02 13:53:19 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * Main function for the preprocess
 * Wrapper all the function that
 * are needed in the preprocess phase
 * 
 * Preprocess phase aims to prepare everything
 * for the execution phase.
 * easy management and debugging since everything
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
	fprintf(stderr, GRN"Input string valid !\n"RESET);
	init_cub(cub);
	fprintf(stderr, GRN"Cub initialized\n"RESET);
	open_file(cub, input_file);
	fprintf(stderr, GRN"File opened\n"RESET);
	parse_file(cub);
	// validate_map(cub->map);
	init_parsed_data(cub);
	// log_colors(cub);
}