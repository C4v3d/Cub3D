/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:11:33 by timmi             #+#    #+#             */
/*   Updated: 2025/12/02 14:19:21 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

/**
 * Default error header (asked by the subject).
 */
# define ERROR_HEADER "Error\n"

typedef enum e_errorcode
{
	/* Input errors*/
	INPUT_WRG_NUM,
	INPUT_WRG_EXT,
	/* Data errors*/
	DATA_MISSING,
	DATA_NOT_FOUND,
	DATA_DUP,
	DATA_WRG_COLOR,
	DATA_WRG_TEXT_PATH,
	/* Map errors*/
	MAP_FILE_NULL,
	MAP_UNAUTH_CHAR,
	MAP_OPEN,
	MAP_DUP_START,
	MAP_NO_START,
	MAP_NOT_FOUND,
	/* MISC */
	MLX_FAIL,
}	t_errorcode;

char	*misc_error_msg(t_errorcode err);
char	*map_error_msg(t_errorcode err);
char	*data_error_msg(t_errorcode err);
char	*input_error_msg(t_errorcode err);

#endif