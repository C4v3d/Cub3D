/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:35:37 by timmi             #+#    #+#             */
/*   Updated: 2025/09/18 13:41:00 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_main	*cub;

	if (argc == 1 || argc > 2)
		return (ft_perror(NULL, WRG_N_ARGS, ERROR));
	cub = malloc(sizeof(t_main));
	if (!cub)
		return (ft_perror(cub, ENOMEM, CRITICAL));
	if (init_cub(cub) != 0)
		return (1);
	if (!is_map_valid(cub, argv[1]))
	{
		printf("uh\n");
	}
	free_cub(cub);
	return (0);
}
