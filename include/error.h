/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:15:10 by timmi             #+#    #+#             */
/*   Updated: 2025/09/11 14:54:56 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/**
 * @brief Opcode for error type
 * 
 * List of three different error types, this enum works along side
 * the w_error function.
 */
typedef enum e_errtype
{
	WARNING, /**< Error that are caused by the user or won't stop
				the correct execution of the program*/
	ERROR, /**< Logical error in the code*/
	CRITICAL, /**< Critical error that cause the abortion of
				the program (e.g: no more sys mem) */
}	t_errtype;

/**
 * This is a wrapper function that aim to ease error handling. It's going to
 * print out the error message on stdout (we are not allowed to use fprintf).
 * 
 * The function take as parameters a string that indicate the location
 * of the error, the error code
 * and the opcode corresonding to the error type.
 * @param loc
 * A string that indicate the location of the error.
 * @param errcode
 * The integer that correspon to the error code (e.g: errno).
 * @param opcode
 * The type of error (WARNING, ERROR, CRITICAL)
 */
int	w_error(const char *loc, const int errcode, t_errtype opcode);

#endif