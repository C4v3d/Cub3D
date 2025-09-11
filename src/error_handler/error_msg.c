/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:27:59 by timmi             #+#    #+#             */
/*   Updated: 2025/09/11 15:10:44 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_warning(const char *loc, const int errcode)
{
	char *error_msg;
	
	if (errcode)
	{
		error_msg = strerror(errcode);
		printf(RED"%s"RESET"\nFrom caller: " YEL"%s\n"RESET,error_msg, loc);
	}
	else
		printf("Oops, dont know what happend from caller :%s\n", loc);
	return (errcode);
}

static int	ft_error(const char *loc, const int errcode)
{
	char *error_msg;

	error_msg = strerror(errcode);
	printf("%s\nFrom caller :%s\n",error_msg, loc);
	return (errcode);
}

static void	ft_fatal(const char *loc)
{
	perror("Fatal error, exiting !\n");
	printf("caller :%s\n", loc);
	exit(EXIT_FAILURE);
}

int	w_error(const char *loc, const int errcode, t_errtype opcode)
{
	printf(RED"Error\n"RESET);
	if (opcode == WARNING)
		return (ft_warning(loc, errcode));
	else if (opcode == ERROR)
		return (ft_error(loc, errcode));
	else if (opcode == CRITICAL)
		ft_fatal(loc);
	return (0);
}
