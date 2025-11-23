/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:27:59 by timmi             #+#    #+#             */
/*   Updated: 2025/11/19 13:38:31 by timmi            ###   ########.fr       */
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
	if (errcode == NO_MAP_FILE)
		return ("Map file does not exist.");
	if (errcode == NO_DATA)
		return ("No data found.");
	if (errcode == MLX_FAIL)
		return ("MLX failed.");
	if (errcode == DUP)
		return ("Duplicated texture/color");
	return (NULL);
}

static int	ft_warning(t_errorcode errcode)
{
	printf(YEL"Warning:	"RESET"%s\n", ft_strerror(errcode));
	return (errcode);
}

static int	ft_error(t_errorcode errcode)
{
	printf(YEL"Error:	"RESET"%s\n", ft_strerror(errcode));
	return (errcode);
}

static void	ft_fatal(t_main *cub, t_errorcode errcode)
{
	char	*err_msg;

	if (!errcode)
		err_msg = strerror(errno);
	else
		err_msg = ft_strerror(errcode);
	printf(RED"Fatal error:	"RESET"%s\n", err_msg);
	printf("\n"RED"	<--- Exiting ! --->"RESET"\n");
	free_cub(cub);
	exit(EXIT_FAILURE);
}

int	ft_perror(t_main *cub, t_errorcode errcode, t_errortype opcode)
{
	printf(ERROR_HEADER);
	if (opcode == WARNING)
		return (ft_warning(errcode));
	else if (opcode == ERROR)
		return (ft_error(errcode));
	else if (opcode == CRITICAL)
		ft_fatal(cub, errcode);
	return (0);
}
