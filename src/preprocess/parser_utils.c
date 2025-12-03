/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:43:23 by timmi             #+#    #+#             */
/*   Updated: 2025/12/03 14:11:40 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	is_color_valid(t_main *cub, char *line)
{
	int	i;

	i = 2;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_isdigit(line[i]) && line[i] != ',')
		{
			ft_perror(cub, DATA_WRG_COLOR, ERROR);
			return (false);
		}
		i++;
	}
	return (true);
}

void	get_start_dir(t_map *m, double dir[AXIS], double *orientation, char c)
{
	if (c == 'N')
	{
		dir[X] = 0;
		dir[Y] = 1;
		*orientation = m->no_rad;
	}
	else if (c == 'S')
	{
		dir[X] = 0;
		dir[Y] = -1;
		*orientation = m->so_rad;
	}
	else if (c == 'W')
	{
		dir[X] = -1;
		dir[Y] = 0;
		*orientation = m->we_rad;
	}
	else
	{
		dir[X] = 1;
		dir[Y] = 0;
		*orientation = m->ea_rad;
	}
}

int	get_id_len(char *line)
{
	int	len;

	len = 0;
	while (!ft_isspace(line[len]))
		len++;
	return (len);
}

bool	is_line_valid(const char *l)
{
	char	*p;

	p = (char *)l;
	while (*p && *p == '\n')
		p++;
	while (*p)
	{
		if (!ft_strchr(CHARSET, *p) && *p != '\n')
			return (false);
		if (*p == '\n' && *(p + 1) == '\n')
		{
			p++;
			break ;
		}
		p++;
	}
	while (*p)
	{
		if (*p != '\n')
			return (false);
		p++;
	}
	return (true);
}
