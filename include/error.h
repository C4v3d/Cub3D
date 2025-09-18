/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/09/18 14:00:15 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ERROR_H
# define ERROR_H

/**
 * Default error header (asked by the subject).
 */
# define ERROR_HEADER "Error\n"
/**
 * @brief Opcode for error type
 *
 * List of three different error types,
 * this enum works along side the
 * w_error function.
 */
typedef enum e_errortype
{
	WARNING, /**< Error that are caused by the user or won't stop
				the correct execution of the program.*/
	ERROR, /**< Logical error in the code.*/
	CRITICAL, /**< Critical error that cause the abortion of
				the program (e.g: no more sys mem). */
	DEBUG, /** For debug purpose. */
}	t_errortype;

typedef enum e_errorcode
{
	SUCCESS,
	WRG_N_ARGS,
	MAP_FILE_NULL,
	WRG_MAP_EXT,
	NO_MAP_FILE,
	NO_DATA,
}	t_errorcode;

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
