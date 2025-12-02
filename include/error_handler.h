/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:33:34 by timmi             #+#    #+#             */
/*   Updated: 2025/12/02 14:13:35 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

/**
 * @brief Opcode for error type
 *
 * List of three different error types,
 * this enum works along side the
 * w_error function.
 */
typedef enum e_errortype
{
	WARNING,
	ERROR, /**< Logical error in the code.*/
	CRITICAL, /**< Critical error that cause the abortion of
				the program (e.g: no more sys mem). */
	DEBUG, /** For debug purpose. */
}	t_errortype;



/**
 * This is a wrapper function that aim to ease error handling. It's going to
 * print out the error message on stdout (we are not allowed to use fprintf).
 *
 * The function take as parameters a string that indicate the location
 * of the error, the error code
 * and the opcode corresonding to the error type.
 * @param cub
 * A pointer reference to the main struct, allowing us to
 * free everything in case of a critical error.
 * @param errcode
 * The integer that correspon to the error code (e.g: CUSTOM_ERROR).
 * pass errno if it is a syscall error.
 * @param opcode
 * The type of error (WARNING, ERROR, CRITICAL). Critical errors
 * make the program stop while error and Warning let you decide
 * weather you want to exit or not by returning their error code.
 */
int	ft_perror(t_main *cub, t_errorcode errcode, t_errortype opcode);

#endif
