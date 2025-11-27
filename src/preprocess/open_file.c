/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:19:13 by timmi             #+#    #+#             */
/*   Updated: 2025/11/27 09:48:49 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_file_fd(char *input_file)
{
	char	*full_path;
	int		fd;

	full_path = ft_strjoin(MAP_PATH, input_file);
	if (!full_path)
		ft_perror(NULL, 0, CRITICAL);
	fd = open(full_path, O_RDONLY);
	w_free((void **)&full_path);
	return (fd);
}

void	open_file(t_main *cub, char *input_file)
{
	cub->pr.input_file_fd = get_file_fd(input_file);
	if (cub->pr.input_file_fd == -1)
	{
		ft_perror(NULL, 0, WARNING);
		exit(errno);
	}
}
