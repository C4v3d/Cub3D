/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/09/19 13:15:57 by emonacho         ###   ########.fr       */
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
		printf("main | map_invalid\n");
	//parser(&cub->pr);
	mlx_loop(cub->mlx);
	free_cub(cub);
	return (0);
}
