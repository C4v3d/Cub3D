/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:07:22 by timmi             #+#    #+#             */
/*   Updated: 2025/09/18 13:51:54 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	parse_texture(t_prog *pr, char *line, char **dest)
{
	line += ID_LEN; /** < Skip ID */
	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (ft_perror(pr->cub, NO_DATA, WARNING));
	*dest = ft_strdup(line);
	/**
	 * Directly parse with mlx function
	 */
	if (!dest)
		return (ft_perror(pr->cub, errno, CRITICAL));
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

static int	fetch_data(t_prog *pr, char *line)
{
	int	id_len;
	
	id_len = 0;
	if (line[0] == '\n')
		return (0);
	while (ft_isspace(*line))
		line++;
	while (ft_isalnum(line[id_len]))
		id_len++;
	if (ft_strncmp(line, NO, id_len) == 0)
		parse_texture(pr, line, &pr->parser->data_scene->textures.no);
	else if (ft_strncmp(line, SO, id_len) == 0)
		parse_texture(pr, line, &pr->parser->data_scene->textures.so);
	else if (ft_strncmp(line, WE, id_len) == 0)
		parse_texture(pr, line, &pr->parser->data_scene->textures.we);
	else if (ft_strncmp(line, EA, id_len) == 0)
		parse_texture(pr, line, &pr->parser->data_scene->textures.ea);
	return (0);
}

int	parser(t_prog *pr)
{
	char	*line;
	
	line = NULL;
	while (1)
	{
		line = get_next_line(pr->parser->input_file_fd);
		if (!line)
			break ;
		fetch_data(pr, line);
		w_free((void **)&line);
	}
	log_data_scene(pr);
	return (0);
}