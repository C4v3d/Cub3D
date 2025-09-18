/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:19:13 by timmi             #+#    #+#             */
/*   Updated: 2025/09/18 16:39:59 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	validate_input_str(t_main *cub, char *input_file)
{
	size_t	len;
	char*	p;

	/**
	 * Not sure :
	 * - map.cub.cub
	 * - map....cub
	*/
	len = ft_strlen(input_file);
	p = input_file;
	if (len == 0 || len <= EXTENSION_LEN)
		return (ft_perror(cub, MAP_FILE_NULL, CRITICAL));
	p += (len - EXTENSION_LEN);
	if (ft_strncmp(p, EXTENSION, EXTENSION_LEN) != 0)
		return (ft_perror(cub, WRG_MAP_EXT, CRITICAL));
	return (0);
}

static int	get_file_fd(t_main *cub, char *input_file)
{
	char	*full_path;
	int		fd;

	full_path = ft_strjoin(MAP_PATH, input_file);
	if (!full_path)
		ft_perror(NULL, errno, ERROR);
	fd = open(full_path, O_RDONLY);
	w_free((void **)&full_path);
	if (fd == -1)
		ft_perror(cub, errno, CRITICAL);
	return (fd);
}

void	open_file(t_main *cub, char *input_file)
{
	validate_input_str(cub, input_file);
	cub->pr.input_file_fd = get_file_fd(cub, input_file);
	if (cub->pr.input_file_fd == -1)
		ft_perror(cub, MAP_FILE_NULL, CRITICAL);
}
