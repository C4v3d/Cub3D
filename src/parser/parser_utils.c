/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:24:37 by timmi             #+#    #+#             */
/*   Updated: 2025/09/16 16:31:30 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*get_id(char *line)
{
	char	*id;
	int		end;

	end = 0;
	while (line[end] && !ft_isspace(line[end]))
		end++;
	id = ft_substr(line, 0, end);
	if (!id)
		return (NULL);
	return (id);
}