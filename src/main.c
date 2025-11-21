/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/11/21 11:49:15 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_main	cub;

	if (argc == 2)
	{
		preprocess(&cub, argv[1]);
		// log_data(&cub);
		welcome_cub3d();
		mlx_loop(cub.mlx);
		//free_cub(&cub);	// USELESS?
		//return (0);		// USELESS?
	}
	else
		return (ft_perror(&cub, WRG_N_ARGS, ERROR));
	free_cub(&cub);
	return (0);
}
