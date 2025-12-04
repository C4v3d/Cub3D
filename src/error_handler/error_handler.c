/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:27:59 by timmi             #+#    #+#             */
/*   Updated: 2025/12/03 16:34:41 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*ft_strerror(t_errorcode errcode)
{
	if (errcode <= INPUT_WRG_EXT)
		return (input_error_msg(errcode));
	if (errcode > INPUT_WRG_EXT && errcode <= DATA_WRG_TEXT_PATH)
		return (data_error_msg(errcode));
	if (errcode > DATA_WRG_TEXT_PATH && errcode <= MAP_NOT_FOUND)
		return (map_error_msg(errcode));
	if (errcode > MAP_NOT_FOUND)
		return (misc_error_msg(errcode));
	return (NULL);
}

static int	ft_warning(t_errorcode errcode)
{
	char	*err_msg;

	if (!errcode)
		err_msg = strerror(errno);
	else
		err_msg = ft_strerror(errcode);
	printf(YEL"Warning:	"RESET"%s\n", err_msg);
	return (errcode);
}

static int	ft_error(t_main *cub, t_errorcode errcode)
{
	char	*err_msg;

	cub->pr.fail = true;
	printf("%d\n", errcode);
	if (!errcode)
		err_msg = strerror(errno);
	else
		err_msg = ft_strerror(errcode);
	printf(YEL"Error:	"RESET"%s\n", err_msg);
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
	if (cub)
		free_cub(cub);
	exit(EXIT_FAILURE);
}

int	ft_perror(t_main *cub, t_errorcode errcode, t_errortype opcode)
{
	printf(ERROR_HEADER);
	if (opcode == WARNING)
		return (ft_warning(errcode));
	else if (opcode == ERROR)
		return (ft_error(cub, errcode));
	else if (opcode == CRITICAL)
		ft_fatal(cub, errcode);
	return (0);
}
