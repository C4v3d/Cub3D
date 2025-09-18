/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/09/18 16:22:05 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_main	cub;

	if (argc == 2)
	{
		preprocess(&cub, argv[1]);
		// execution();
		// cleaning();
		// parser(&cub->pr);
		// free_cub(cub);
		return (0);	
	}
	else
		return (ft_perror(&cub, WRG_N_ARGS, ERROR));
}
