/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:07:22 by timmi             #+#    #+#             */
/*   Updated: 2025/09/18 16:44:53 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	parse_texture(t_main *cub, char *line, void **dest)
{
	line += ID_LEN; /** < Skip ID */
	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (ft_perror(cub, NO_DATA, WARNING));
	*dest = mlx_xpm_file_to_image(NULL, line, cub->gfx.txtr_w, cub->gfx.txtr_h);
	if (!dest)
		return (ft_perror(cub, MLX_FAIL, CRITICAL));
	if (!dest)
		return (ft_perror(cub, errno, CRITICAL));
	return (0);
}

// static int	prase_color(t_cub *cub)
// {
// 	return (0);
// }

// static int	prase_map(t_cub *cub)
// {
// 	return (0);
// }

static int	fetch_data(t_main *cub, char *line)
{
	int	id_len;
	
	id_len = 0;
	if (line[0] == '\n')
		return (0);
	while (ft_isspace(*line))
		line++;
	while (ft_isalnum(line[id_len]))
		id_len++;
	if (ft_strncmp(line, NO_ID, id_len) == 0)
		parse_texture(cub, line, &cub->gfx.txtr[NO]);
	else if (ft_strncmp(line, SO_ID, id_len) == 0)
		parse_texture(cub, line, &cub->gfx.txtr[SO]);
	else if (ft_strncmp(line, WE_ID, id_len) == 0)
		parse_texture(cub, line, &cub->gfx.txtr[WE]);
	else if (ft_strncmp(line, EA_ID, id_len) == 0)
		parse_texture(cub, line, &cub->gfx.txtr[EA]);
	return (0);
}

int	parse_file(t_main *cub)
{
	char	*line;
	
	line = NULL;
	while (1)
	{
		line = get_next_line(cub->pr.input_file_fd);
		if (!line)
			break ;
		fetch_data(cub, line);
		w_free((void **)&line);
	}
	log_data_scene(cub);
	return (0);
}