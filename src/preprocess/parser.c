/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:07:22 by timmi             #+#    #+#             */
/*   Updated: 2025/12/04 15:04:16 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	fetch_data(t_graphic *gfx, char *line)
{
	int	id_len;

	if (line[0] == '\n')
		return ;
	ft_skip_spaces(&line);
	if (!line || *line == '\n' || *line == '\0')
		return ;
	id_len = get_id_len(line);
	if (id_len == ID_LEN)
		id_texture(gfx, line);
	else if (id_len > ID_LEN)
		ft_perror(gfx->cub, DATA_INC_ID, ERROR);
	else
	{
		if (line[0] == 'C')
			parse_color(gfx->cub, line + ID_LEN - 1, &gfx->ceiling);
		else if (line[0] == 'F')
			parse_color(gfx->cub, line + ID_LEN - 1, &gfx->floor);
		else
			ft_perror(gfx->cub, DATA_INC_ID, ERROR);
	}
}

static void	parse_data(t_graphic *gfx)
{
	char		*line;
	const int	total_el = N_COLOR + N_TEXTURE;

	line = NULL;
	while (gfx->el_counter < total_el)
	{
		line = get_next_line(gfx->cub->pr.input_file_fd);
		if (!line)
			break ;
		fetch_data(gfx, line);
		w_free((void **)&line);
		if (gfx->cub->pr.fail)
		{
			get_next_line(-1);
			free_cub(gfx->cub);
			exit(EXIT_FAILURE);
		}
	}
	if (gfx->el_counter != total_el)
		ft_perror(gfx->cub, DATA_MISSING, CRITICAL);
}

void	parse_file(t_main *cub)
{
	parse_data(&cub->gfx);
	parse_map(&cub->map);
}
