/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:40:52 by timmi             #+#    #+#             */
/*   Updated: 2025/11/23 16:38:52 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//v2
static void	parse_texture(t_graphic *gfx, t_image *t, char *line)
{
	line += ID_LEN; /** < Skip ID */
	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		ft_perror(gfx->cub, NO_DATA, WARNING);
	line = ft_strtrim(line, "\n\t");
	printf("cub3d: loading '%s', please wait...\n", line);
	t->img = mlx_xpm_file_to_image(gfx->cub->mlx, line, &t->width, &t->height);
	if (!t->img)
		ft_perror(gfx->cub, MLX_FAIL, CRITICAL);
	if (gfx->txtr_res == -1)			// init texture resolution for the game -> FAUX ou USELESS?
		gfx->txtr_res = t->width;
	else if (t->width != gfx->txtr_res)	// check if all textures are same res -> FAUX ou USELESS?
		ft_perror(gfx->cub, MLX_FAIL, CRITICAL);
	t->addr = mlx_get_data_addr(t->img, &t->bpp, &t->s_line, &t->endian);
	if (!t->addr)
		ft_perror(gfx->cub, MLX_FAIL, CRITICAL);
}

static void	parse_color(char *line, t_color **dest)
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
		else if (n_color == 2)
			(*dest)->b = get_color(line, c_len);
		line += c_len + 1;
		n_color++;
	}
}

//v2
static void	fetch_data(t_graphic *gfx, char *line)
{
	int	id_len;

	if (line[0] == '\n')
		return;
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
		parse_color(line, &gfx->ceiling);
	else if (ft_strncmp(line, F_ID, id_len) == 0)
		parse_color(line, &gfx->floor);
	(*gfx).el_counter += 1;
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
	}
	if (gfx->el_counter != total_el)
		ft_perror(gfx->cub, WRG_N_ARGS, CRITICAL);
}
