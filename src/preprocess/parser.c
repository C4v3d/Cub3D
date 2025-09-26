/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:07:22 by timmi             #+#    #+#             */
/*   Updated: 2025/09/26 16:55:34 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * Need to find a way to check doubled texture !
 */
static int	parse_texture(t_graphic *gfx, char *line, void **dest)
{
	line += ID_LEN; /** < Skip ID */
	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (ft_perror(gfx->cub, NO_DATA, WARNING));
	*dest = mlx_xpm_file_to_image(NULL, line, gfx->txtr_w, gfx->txtr_h);
	if (!dest)
		return (ft_perror(gfx->cub, MLX_FAIL, CRITICAL));
	return (0);
}

int	get_color(char *line, int len)
{
	int color;
	int	i;

	color = 0;
	i = 0;
	while (i < len)
		color = color * 10 + (line[i++] - '0');
	return (color);
}

static int	parse_color(char *line, t_color **dest)
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
		while (ft_isdigit(line[c_len])) /* Rewrite this bs */
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
	return (0);
}

/**
 * Maybe put this functions in utils ?
 */
static	int	get_id_len(char *line)
{
	int	len;

	len = 0;
	while (ft_isalnum(line[len])) 
		len++;
	return (len);
}

/**
 * Find a better way to write this nightmare
 */
static int	fetch_data(t_graphic *gfx, char *line)
{
	int	id_len;
	
	if (line[0] == '\n')
		return (0);
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
		parse_color(line, &gfx->colors[CEILING]);
	else if (ft_strncmp(line, F_ID, id_len) == 0)
		parse_color(line, &gfx->colors[FLOOR]);
	return (0);
}

/**
 * Write a checker to check
 * the number of element parsed.
 */
void	parse_data(t_graphic *gfx)
{
	char	*line;
	int		i;
	
	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(gfx->cub->pr.input_file_fd);
		if (!line)
			break ;
		fetch_data(gfx, line);
		w_free((void **)&line);
		i++;
	}
}

void	parse_map(t_map *map)
{
	return ;
}

int	parse_file(t_main *cub)
{
	parse_data(&cub->gfx);
	return (0);
}