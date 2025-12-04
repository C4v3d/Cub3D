/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:40:52 by timmi             #+#    #+#             */
/*   Updated: 2025/12/04 14:51:25 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_color(char *line)
{
	int	c;

	c = 0;
	while (ft_isdigit(*line))
		c = c * 10 + (*(line++) - '0');
	return (c);
}

static int	parse_texture(t_graphic *gfx, t_image *t, char *line)
{
	char	*trimmed;

	ft_skip_spaces(&line);
	if (*line == '\0')
		return (ft_perror(gfx->cub, DATA_NOT_FOUND, ERROR));
	trimmed = ft_substr(line, 0, ft_strlen(line) - 1);
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

void	id_texture(t_graphic *gfx, char *line)
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

static void	color_atr(t_color **dest, int color, int n)
{
	if (n == 0)
		(*dest)->r = color;
	else if (n == 1)
		(*dest)->g = color;
	else
		(*dest)->b = color;
}

int	parse_color(t_main *cub, char *line, t_color **dest)
{
	int	c;
	int	c_count;

	c_count = 0;
	ft_skip_spaces(&line);
	if (!color_validation(line))
		return (ft_perror(cub, DATA_INV_COLOR_FORMAT, ERROR));
	while (*line && !(*line == '\0' || *line == '\n') && c_count < 3)
	{
		if (*line == ',')
			line++;
		if (*line == '\n' || *line == '\0')
			break;
		c = get_color(line);
		if (c > 255)
			return (ft_perror(cub, DATA_COLOR_MAX, ERROR));
		color_atr(dest, c, c_count);
		line += ft_intlen(c);
		c_count++;
	}
	if (c_count != 3){
		return (ft_perror(cub, DATA_INV_COLOR_FORMAT, ERROR));
	}
	cub->gfx.el_counter++;
	return (0);
}
