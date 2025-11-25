/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:43:23 by timmi             #+#    #+#             */
/*   Updated: 2025/11/25 14:50:03 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_start_dir(double dir[AXIS], double *orientation, char c)
{
	if (c == 'N')
	{
		dir[X] = 0;
		dir[Y] = 1;
		*orientation = NO_RAD;
	}
	else if (c == 'S')
	{
		dir[X] = 0;
		dir[Y] = -1;
		*orientation = SO_RAD;
	}
	else if (c == 'W')
	{
		dir[X] = -1;
		dir[Y] = 0;
		*orientation = WE_RAD;
	}
	else
	{
		dir[X] = 1;
		dir[Y] = 0;
		*orientation = EA_RAD;
	}
}

int	get_color(char *line, int len)
{
	int	color;
	int	i;

	color = 0;
	i = 0;
	while (i < len)
		color = color * 10 + (line[i++] - '0');
	return (color);
}

/**
 * Maybe put this functions in utils ?
 */
int	get_id_len(char *line)
{
	int	len;

	len = 0;
	while (ft_isalnum(line[len]))
		len++;
	return (len);
}

bool	is_line_valid(const char *l)
{
	char	*p;

	p = (char *)l;
	while (!*p && *p != '\n')
	{
		if (!ft_strchr(CHARSET, *p))
			return (false);
		p++;
	}
	return (true);
}
