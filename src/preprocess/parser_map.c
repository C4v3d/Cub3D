/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:42:38 by timmi             #+#    #+#             */
/*   Updated: 2025/09/30 15:08:44 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	process_line(t_map *map)
{
	char	*line;
	char	*inline_map;
	char	*fp;
	
	(void)map;
	line = NULL;
	inline_map = NULL;
	if (line[0] == '\n')
		return;
	while (1)
	{
		line = get_next_line(map->cub->pr.input_file_fd);
		if (!line)
			break;
		if (inline_map)
			fp = inline_map;
		inline_map = ft_strjoin(inline_map, line);
		w_free((void **)&fp);
		w_free((void **)&line);
	}
	printf("line :%s\n", inline_map);
}


void	parse_map(t_map *map)
{
	(void)map;
	process_line(map);
}
