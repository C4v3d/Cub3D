/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:27:59 by timmi             #+#    #+#             */
/*   Updated: 2025/09/14 17:52:11 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*ft_strerror(t_errorcode errcode)
{
	if (errcode == WRG_N_ARGS)
		return ("Wrong number of argument(s). "
			"You need to specify one map to play.");
	if (errcode == MAP_FILE_NULL)
		return ("Map file is null");
	if (errcode == WRG_MAP_EXT)
		return ("Wrong map extension (must be .cub).");
	return (NULL);
}

static int	ft_warning(t_errorcode errcode)
{
	printf(YEL"Warning:	"RESET"%s\n", ft_strerror(errcode));
	return (errcode);
}

static int	ft_error(const char *caller, t_errorcode errcode)
{
	printf(YEL"/!\\	"RESET"%s\n"
		"From caller:	"YEL"%s\n"RESET, ft_strerror(errcode), caller);
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

int	ft_perror(const char *caller, t_errorcode errcode, t_errortype opcode)
{
	printf(ERROR_HEADER);
	if (opcode == WARNING)
		return (ft_warning(errcode));
	else if (opcode == ERROR)
		return (ft_error(caller, errcode));
	else if (opcode == CRITICAL)
		ft_fatal(caller);
	return (0);
}
