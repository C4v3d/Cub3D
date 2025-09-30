/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:43:23 by timmi             #+#    #+#             */
/*   Updated: 2025/09/30 11:48:48 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
