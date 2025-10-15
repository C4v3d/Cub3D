/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:40:52 by timmi             #+#    #+#             */
/*   Updated: 2025/10/15 16:39:38 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * Need to find a way to check doubled texture !
 */
static void	parse_texture(t_graphic *gfx, char *line, void **dest)
{
	line += ID_LEN; /** < Skip ID */
	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		ft_perror(gfx->cub, NO_DATA, WARNING);
	*dest = mlx_xpm_file_to_image(NULL, line, gfx->txtr_w, gfx->txtr_h);
	if (!dest)
		ft_perror(gfx->cub, MLX_FAIL, CRITICAL);
	(*gfx).el_counter += 1;
}

static void	parse_color(t_graphic *gfx, char *line, t_color **dest)
{
	int	c_len;
	int	n_color;

	line += ID_LEN - 1; /** < Skip ID */
	n_color = 0;
	while (ft_isspace(*line))
		line++;
	while (*line && n_color < 3)
	{
		c_len = 0;
		while (ft_isdigit(line[c_len])) /* Rewrite this bs (the whole function) */
			c_len++;					/* Maybe by bitshifting ?*/
		if (n_color == 0)
			(*dest)->r = get_color(line, c_len);
		else if (n_color == 1)
			(*dest)->g = get_color(line, c_len);
		else
			(*dest)->b = get_color(line, c_len);
		line += c_len + 1;
		n_color++;
	}
	(*gfx).el_counter += 1;
}

/**
 * Find a better way to write this nightmare
 */
static void	fetch_data(t_graphic *gfx, char *line)
{
	int	id_len;

	if (line[0] == '\n')
		return;
	while (ft_isspace(*line))
		line++;
	id_len = get_id_len(line);
	if (ft_strncmp(line, NO_ID, id_len) == 0)
		parse_texture(gfx, line, &gfx->txtr[NO]);
	else if (ft_strncmp(line, SO_ID, id_len) == 0)
		parse_texture(gfx, line, &gfx->txtr[SO]);
	else if (ft_strncmp(line, WE_ID, id_len) == 0)
		parse_texture(gfx, line, &gfx->txtr[WE]);
	else if (ft_strncmp(line, EA_ID, id_len) == 0)
		parse_texture(gfx, line, &gfx->txtr[EA]);
	else if (ft_strncmp(line, C_ID, id_len) == 0)
		parse_color(gfx, line, &gfx->colors[CEILING]);
	else if (ft_strncmp(line, F_ID, id_len) == 0)
		parse_color(gfx, line, &gfx->colors[FLOOR]);
}

void	parse_data(t_graphic *gfx)
{
	char	*line;
	int		total_el;
	int		col;
	int		txt;

	line = NULL;
	col = N_COLOR;
	txt = N_TEXTURE;
	total_el = col + txt;
	while (gfx->el_counter < total_el)
	{
		line = get_next_line(gfx->cub->pr.input_file_fd);
		if (!line)
			break ;
		fetch_data(gfx, line);
		w_free((void **)&line);
	}
	if (gfx->el_counter != total_el)
		ft_perror(gfx->cub, WRG_N_ARGS, CRITICAL);
}
