/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:35:37 by timmi             #+#    #+#             */
/*   Updated: 2025/09/11 15:04:00 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	char *ptr = NULL;

	(void)argc;
	(void)argv;
	if (!ptr)
		w_error("main", ENOMEM, WARNING);
	return (0);
}
