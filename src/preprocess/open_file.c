/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:19:13 by timmi             #+#    #+#             */
/*   Updated: 2025/12/02 13:50:16 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	open_file(t_main *cub, char *input_file)
{
	cub->pr.input_file_fd = open(input_file, O_RDONLY);
	if (cub->pr.input_file_fd == -1)
		exit(ft_perror(NULL, 0, WARNING));
}
