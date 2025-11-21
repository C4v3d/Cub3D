/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:17:37 by timmi             #+#    #+#             */
/*   Updated: 2025/11/21 11:50:09 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	is_input_valid(char *input_file)
{
	size_t	len;
	char*	p;

	len = ft_strlen(input_file);
	p = input_file;
	if (len == 0 || len <= EXTENSION_LEN)
	{
		ft_perror(NULL, MAP_FILE_NULL, WARNING);
		return (false);
	}
	p += (len - EXTENSION_LEN);
	if (ft_strncmp(p, EXTENSION, EXTENSION_LEN) != 0)
	{
		ft_perror(NULL, WRG_MAP_EXT, WARNING);
		return (false);
	}
	return (true);
}
