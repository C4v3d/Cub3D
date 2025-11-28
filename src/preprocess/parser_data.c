/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:40:52 by timmi             #+#    #+#             */
/*   Updated: 2025/11/28 15:55:25 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	parse_texture(t_graphic *gfx, t_image *t, char *line)
{
	char	*trimmed;

	line += ID_LEN;
	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (ft_perror(gfx->cub, NO_DATA, ERROR));
	trimmed = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!trimmed)
		ft_perror(gfx->cub, 0, ERROR);
	if (t->img != NULL)
	{
		w_free((void **)&trimmed);
		return (ft_perror(gfx->cub, DUP, ERROR));
	}
	t->img = mlx_xpm_file_to_image(gfx->cub->mlx, trimmed,
			&t->width, &t->height);
	w_free((void **)&trimmed);
	if (!t->img)
		return (ft_perror(gfx->cub, MLX_FAIL, ERROR));
	t->addr = mlx_get_data_addr(t->img, &t->bpp, &t->s_line, &t->endian);
	if (!t->addr)
		return (ft_perror(gfx->cub, MLX_FAIL, ERROR));
	(*gfx).el_counter += 1;
	return (0);
}

static int	parse_color(t_main *cub, char *line, t_color **dest)
{
	int	c_len;
	int	n_color;

	line += ID_LEN - 1;
	n_color = 0;
	if ((*dest)->color != -1)
		return (ft_perror(cub, DUP, ERROR));
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
		else if (n_color == 2)
			(*dest)->b = get_color(line, c_len);
		line += c_len + 1;
		n_color++;
	}
	cub->gfx.el_counter += 1;
	return (0);
}

static bool	is_color_valid(t_main *cub, char *line)
{
	int	i;

	i = 2;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_isdigit(line[i]) && line[i] != ',')
		{
			ft_perror(cub, BAD_COLOR, ERROR);
			return (false);
		}
		i++;
	}
	return (true);
}

static void	fetch_data(t_graphic *gfx, char *line)
{
	int	id_len;

	if (line[0] == '\n')
		return ;
	while (ft_isspace(*line))
		line++;
	id_len = get_id_len(line);
	if (ft_strncmp(line, NO_ID, id_len) == 0)
		parse_texture(gfx, &gfx->txtr[NO], line);
	else if (ft_strncmp(line, SO_ID, id_len) == 0)
		parse_texture(gfx, &gfx->txtr[SO], line);
	else if (ft_strncmp(line, WE_ID, id_len) == 0)
		parse_texture(gfx, &gfx->txtr[WE], line);
	else if (ft_strncmp(line, EA_ID, id_len) == 0)
		parse_texture(gfx, &gfx->txtr[EA], line);
	else if (ft_strncmp(line, C_ID, id_len) == 0)
	{
		if (is_color_valid(gfx->cub, line))
			parse_color(gfx->cub, line, &gfx->ceiling);
	}
	else if (ft_strncmp(line, F_ID, id_len) == 0)
	{
		if (is_color_valid(gfx->cub, line))
			parse_color(gfx->cub, line, &gfx->floor);
	}
}

void	parse_data(t_graphic *gfx)
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
			free_cub(gfx->cub);
			exit(EXIT_FAILURE);
		}
	}
	if (gfx->el_counter != total_el)
		ft_perror(gfx->cub, INC_MAP_FILE, CRITICAL);
}
