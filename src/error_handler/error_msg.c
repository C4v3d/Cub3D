/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:27:59 by timmi             #+#    #+#             */
/*   Updated: 2025/09/12 15:33:05 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_warning(const char *caller, const int errcode)
{
	(void)errcode; // To replace with correct errcode
	printf(YEL"Warning:	"RESET"Warning message\n"
		"From caller:	"YEL"%s\n"RESET, caller);
	return (errcode);
}

static int	ft_error(const char *caller, const int errcode)
{
	(void)errcode; // To replace with correct errcode
	printf(YEL"/!\\	"RESET"Error message\n"
		"From caller:	"YEL"%s\n"RESET, caller);
	return (errcode);
}

static void	ft_fatal(const char *caller)
{
	char	*err_msg;

	err_msg = strerror(errno);
	printf(RED"Fatal error:	"RESET"%s\n"
		"From caller:	"YEL"%s\n"RESET, err_msg, caller);
	printf("\n"RED"	<--- Exiting ! --->"RESET"\n");
	exit(EXIT_FAILURE);
}

int	print_error(const char *caller, const int errcode, t_errcode opcode)
{
	printf(ERROR_HEADER);
	if (opcode == WARNING)
		return (ft_warning(caller, errcode));
	else if (opcode == ERROR)
		return (ft_error(caller, errcode));
	else if (opcode == CRITICAL)
		ft_fatal(caller);
	return (0);
}
