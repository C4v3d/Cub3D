/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:19:13 by timmi             #+#    #+#             */
/*   Updated: 2025/11/18 16:30:49 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_file_fd(t_main *cub, char *input_file)
{
	char	*full_path;
	int		fd;

	full_path = ft_strjoin(MAP_PATH, input_file);
	fprintf(stderr, "full_path: %s\n", full_path);
	if (!full_path)
		ft_perror(NULL, errno, ERROR);
	fd = open(full_path, O_RDONLY);
	w_free((void **)&full_path);
	if (fd == -1)
		ft_perror(cub, errno, CRITICAL);
	return (fd);
}


/**
 * Check if directory
 */
void	open_file(t_main *cub, char *input_file)
{
	cub->pr.input_file_fd = get_file_fd(cub, input_file);
	if (cub->pr.input_file_fd == -1)
		ft_perror(cub, MAP_FILE_NULL, CRITICAL);
}
