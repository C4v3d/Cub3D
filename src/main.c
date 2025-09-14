/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:35:37 by timmi             #+#    #+#             */
/*   Updated: 2025/09/14 17:32:50 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	if (argc == 1 || argc > 2)
		return (ft_perror("main", WRG_N_ARGS, ERROR));
	if (!is_map_valid(argv[1]))
	{
		
	}
	return (0);
}
