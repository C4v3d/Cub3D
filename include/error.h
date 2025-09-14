/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:15:10 by timmi             #+#    #+#             */
/*   Updated: 2025/09/14 17:51:07 by timmi            ###   ########.fr       */
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
 * List of three different error types, this enum works along side
 * the w_error function.
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
	WRG_N_ARGS,
	MAP_FILE_NULL,
	WRG_MAP_EXT,
}	t_errorcode;

/**
 * This is a wrapper function that aim to ease error handling. It's going to
 * print out the error message on stdout (we are not allowed to use fprintf).
 * 
 * The function take as parameters a string that indicate the location
 * of the error, the error code
 * and the opcode corresonding to the error type.
 * @param loc
 * A string that indicate the caller function (e.g: "main").
 * @param errcode
 * The integer that correspon to the error code (e.g: CUSTOM_ERROR).
 * @param opcode
 * The type of error (WARNING, ERROR, CRITICAL)
 */
int	ft_perror(const char *loc, const t_errorcode errcode, t_errortype opcode);

#endif