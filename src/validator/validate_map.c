/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:19:13 by timmi             #+#    #+#             */
/*   Updated: 2025/09/14 18:49:54 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	validate_input_str(char *map_file)
{
	size_t	len;
	char*	p;

	/**
	 * Not sure :
	 * - map.cub.cub
	 * - map....cub
	 */
	len = ft_strlen(map_file);
	p = map_file;
	if (len == 0 || len == EXTENSION_LEN)
		return (ft_perror(NULL, MAP_FILE_NULL, WARNING));
	p += (len - EXTENSION_LEN);
	if (ft_strncmp(p, EXTENSION, EXTENSION_LEN) != 0)
		return (ft_perror(NULL, WRG_MAP_EXT, WARNING));
	return (0);
}

static int	open_map(char *map_file)
{
	int	fd;

	(void)map_file;
	fd = open(MAP_PATH"map_file", O_RDONLY);
	if (fd < 0)
		ft_perror(NULL, NO_MAP_FILE, WARNING);
	return (fd);
}

bool	is_map_valid(char *map_file)
{
	int	map_fd;

	if (validate_input_str(map_file) != 0)
		return (false);
	map_fd = open_map(map_file);
	printf("fd is %d\n", map_fd);
	return (true);
}
