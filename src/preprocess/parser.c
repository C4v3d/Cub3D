/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:07:22 by timmi             #+#    #+#             */
/*   Updated: 2025/09/19 15:10:47 by timmi            ###   ########.fr       */
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

static int	parse_color(t_main *cub, char *line, t_color **dest)
{
	int	c_len;
	int	n_color;

	(void)cub;
	line += ID_LEN - 1; /** < Skip ID */
	n_color = 0;
	while (ft_isspace(*line))
		line++;
	while (*line && n_color < 3)
	{
		c_len = 0;
		while (ft_isdigit(line[c_len]))
			c_len++;
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

static int	fetch_data(t_main *cub, char *line)
{
	int	id_len;
	
	if (line[0] == '\n')
		return (0);
	while (ft_isspace(*line))
		line++;
	id_len = get_id_len(line);
	if (ft_strncmp(line, NO_ID, id_len) == 0)
		parse_texture(cub, line, &cub->gfx.txtr[NO]);
	else if (ft_strncmp(line, SO_ID, id_len) == 0)
		parse_texture(cub, line, &cub->gfx.txtr[SO]);
	else if (ft_strncmp(line, WE_ID, id_len) == 0)
		parse_texture(cub, line, &cub->gfx.txtr[WE]);
	else if (ft_strncmp(line, EA_ID, id_len) == 0)
		parse_texture(cub, line, &cub->gfx.txtr[EA]);
	else if (ft_strncmp(line, C_ID, id_len) == 0)
		parse_color(cub, line, &cub->gfx.colors[CEILING]);
	else if (ft_strncmp(line, F_ID, id_len) == 0)
		parse_color(cub, line, &cub->gfx.colors[FLOOR]);
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
	return (0);
}