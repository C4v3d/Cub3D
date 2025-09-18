/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:19:13 by timmi             #+#    #+#             */
/*   Updated: 2025/09/18 11:34:15 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	validate_input_str(char *map_path)
{
	size_t	len;
	char*	p;

	/**
	 * Not sure :
	 * - map.cub.cub
	 * - map....cub
	*/
	len = ft_strlen(map_path);
	p = map_path;
	if (len == 0 || len <= EXTENSION_LEN)
		return (ft_perror(NULL, MAP_FILE_NULL, WARNING));
	p += (len - EXTENSION_LEN);
	if (ft_strncmp(p, EXTENSION, EXTENSION_LEN) != 0)
		return (ft_perror(NULL, WRG_MAP_EXT, WARNING));
	return (0);
}

static int	get_map_fd(t_prog *pr, char *map_path)
{
	char	*full_path;

	full_path = ft_strjoin(MAP_PATH, map_path);
	if (!full_path)
		return (ft_perror(NULL, errno, ERROR));
	pr->parser->input_file_fd = open(full_path, O_RDONLY);
	w_free((void **)&full_path);
	if (pr->parser->input_file_fd == -1)
		return (ft_perror(pr->cub, errno, CRITICAL));
	return (0);
}

bool	is_map_valid(t_prog *pr, char *map_path)
{
	if (validate_input_str(map_path) != 0)
		return (false);
	if (get_map_fd(pr, map_path) != 0)
		return (false);
	return (true);
}
