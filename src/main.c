/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/09/18 14:00:23 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_main		*cub;
	
	/**
	 * Maybe split the program into 3 main area :
	 * - Preprocess
	 * - execution
	 * - Cleaning
	 */
	if (argc == 1 || argc > 2)
		return (ft_perror(NULL, WRG_N_ARGS, ERROR));
	cub = malloc(sizeof(t_main));
	if (!cub)
		return (ft_perror(cub, ENOMEM, CRITICAL));
	if (init_cub(cub) != 0)
		return (1);
	if (!is_map_valid(&cub->pr, argv[1]))
	{
		printf("uh\n");
	}
	parser(&cub->pr);
	free_cub(cub);
	return (0);
}
