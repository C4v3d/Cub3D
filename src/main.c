/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/11/01 18:43:32 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_main	cub;

	if (argc == 2)
	{
		preprocess(&cub, argv[1]);
		log_data(&cub);
		fprintf(stderr, "go loop\n");
		mlx_loop(cub.mlx);
		//free_cub(&cub);	// USELESS?
		//return (0);		// USELESS?
	}
	else
		return (ft_perror(&cub, WRG_N_ARGS, ERROR));
	free_cub(&cub);
	return (0);
}
