/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:52:13 by timmi             #+#    #+#             */
/*   Updated: 2025/12/04 15:05:46 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*misc_error_msg(t_errorcode err)
{
	if (err == MLX_FAIL)
		return ("Oops ! MLX failed...");
	return (NULL);
}

char	*map_error_msg(t_errorcode err)
{
	if (err == MAP_UNAUTH_CHAR)
		return ("Unauthorized character used or map is invalid !\n");
	if (err == MAP_OPEN)
		return ("Map is not closed or is invalid !");
	if (err == MAP_DUP_START)
		return ("Duplicated Starting position found !");
	if (err == MAP_NO_START)
		return ("No starting position found.");
	if (err == MAP_NOT_FOUND)
		return ("No map in file.");
	return (NULL);
}

char	*data_error_msg(t_errorcode err)
{
	if (err == DATA_MISSING)
		return ("Map file is missing data (texture or color)");
	if (err == DATA_NOT_FOUND)
		return ("No texture found.");
	if (err == DATA_INC_ID)
		return ("Incorrect or missing texture/color id.\n"
			"(Correct IDs are: \"NO, SO, WE, EA, F, C).\"");
	if (err == DATA_DUP)
		return ("Duplicated texture/color");
	if (err == DATA_COLOR_MAX)
		return ("Color value to high (value must be between 0 - 255).");
	if (err == DATA_INV_COLOR_FORMAT)
		return ("Invalid color format ! (value must be between 0 - 255"
			" ex: \"10,120,67\")");
	if (err == DATA_WRG_COLOR)
		return ("The color you specified isn't valid !\n"
			"Must be \"C 130,10,0\"");
	if (err == DATA_WRG_TEXT_PATH)
		return ("Texture path couldn't be open !"
			" (Should be \"texture_example.xpm\")");
	return (NULL);
}

char	*input_error_msg(t_errorcode err)
{
	if (err == INPUT_WRG_NUM)
		return ("Wrong number of argument(s) !\n"
			"Should be \"./cub3d map/map_example.cub\"");
	if (err == INPUT_WRG_EXT)
		return ("Wrong map extension (must be .cub).");
	if (err == INPUT_WRG_FILE)
		return ("Map must be \".cub\" file.");
	return (NULL);
}
