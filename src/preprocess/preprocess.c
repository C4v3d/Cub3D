/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:35:10 by timmi             #+#    #+#             */
/*   Updated: 2025/09/19 15:10:11 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	preprocess(t_main *cub, char *input_file)
{	
	init_cub(cub);
	open_file(cub, input_file);
	parse_file(cub);
	log_colors(cub);
}