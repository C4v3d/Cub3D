/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:42:38 by timmi             #+#    #+#             */
/*   Updated: 2025/09/30 11:48:48 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	parse_map(t_map *map)
{
	char	*line;
	
	line = NULL;
	(void)map;
	while (1)
	{
		line = get_next_line(map->cub->pr.input_file_fd);
		if (!line)
			break;
		fprintf(stderr, "line :%s\n", line);
		w_free((void **)&line);
	}
}