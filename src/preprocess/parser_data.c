/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:40:52 by timmi             #+#    #+#             */
/*   Updated: 2025/12/03 15:05:36 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	parse_texture(t_graphic *gfx, t_image *t, char *line)
{
	char	*trimmed;

	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (ft_perror(gfx->cub, DATA_NOT_FOUND, ERROR));
	trimmed = ft_substr(line, 0, ft_strlen(line) - 1); /* BETTER TRIMMING*/
	if (!trimmed)
		ft_perror(gfx->cub, 0, ERROR);
	if (t->img != NULL)
	{
		w_free((void **)&trimmed);
		return (ft_perror(gfx->cub, DATA_DUP, ERROR));
	}
	t->img = mlx_xpm_file_to_image(gfx->cub->mlx, trimmed,
			&t->width, &t->height);
	w_free((void **)&trimmed);
	if (!t->img)
		return (ft_perror(gfx->cub, DATA_WRG_TEXT_PATH, ERROR));
	t->addr = mlx_get_data_addr(t->img, &t->bpp, &t->s_line, &t->endian);
	if (!t->addr)
		return (ft_perror(gfx->cub, MLX_FAIL, ERROR));
	(*gfx).el_counter += 1;
	return (0);
}

static int	get_color(char *line)
{
	int	c;
	
	c = 0;
	while (ft_isdigit(*line))
		c = c * 10 + (*(line++) - '0');
	return (c);
}

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	parse_color(t_main *cub, char *line, t_color **dest)
{
	int	c;
	int	c_count;

	c = 0;
	c_count = 0;
	while (ft_isspace(*line))
		line++;
	while (line && (*line == ',' || *line == '\n' || *line == '\0') && c_count < 3)
	{
		c = get_color(line);
		if (c > 255)
			return (ft_perror(cub, DATA_COLOR_MAX, ERROR));
		if (c_count == 0)
			(*dest)->r = c;
		else if (c_count == 1)
			(*dest)->g = c;
		else
			(*dest)->b = c;
		line += ft_intlen(c) + 1;
		c_count++;
	}
	if (c_count != 3)
		return (ft_perror(cub, DATA_INC_ID, ERROR));
	cub->gfx.el_counter++;
	return (0);
}

static void	id_texture(t_graphic *gfx, char *line)
{
	if (ft_strncmp(line, SO_ID, ID_LEN) == 0)
		parse_texture(gfx, &gfx->txtr[SO], line + ID_LEN);
	else if (ft_strncmp(line, NO_ID, ID_LEN) == 0)
		parse_texture(gfx, &gfx->txtr[NO], line + ID_LEN);
	else if (ft_strncmp(line, WE_ID, ID_LEN) == 0)
		parse_texture(gfx, &gfx->txtr[WE], line + ID_LEN);
	else if (ft_strncmp(line, EA_ID, ID_LEN) == 0)
		parse_texture(gfx, &gfx->txtr[EA], line + ID_LEN);
}

static void	fetch_data(t_graphic *gfx, char *line)
{
	int	id_len;

	if (line[0] == '\n')
		return ;
	while (ft_isspace(*line))
		line++;
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
			get_next_line(-1);
			free_cub(gfx->cub);
			exit(EXIT_FAILURE);
		}
	}
	if (gfx->el_counter != total_el)
		ft_perror(gfx->cub, DATA_MISSING, CRITICAL);
}
