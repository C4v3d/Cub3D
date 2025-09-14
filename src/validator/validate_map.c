/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:19:13 by timmi             #+#    #+#             */
/*   Updated: 2025/09/14 17:56:16 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	validate_input_str(char *path)
{
	size_t	len;
	char*	p;
	/**
	 * Not sure :
	 * - map.cub.cub
	 * - map....cub
	 */
	len = ft_strlen(path);
	p = path;
	if (len == 0 || len == EXT_LEN)
		return (ft_perror(NULL, MAP_FILE_NULL, WARNING));
	p += (len - EXT_LEN);
	if (ft_strncmp(p, EXT, EXT_LEN) != 0)
		return (ft_perror(NULL, WRG_MAP_EXT, WARNING));
	return (0);
}

bool	is_map_valid(char *map_path)
{
	if (!validate_input_str(map_path))
	{
		printf("rewrew\n");
	}
	return (true);
}