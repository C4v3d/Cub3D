/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:23:22 by timmi             #+#    #+#             */
/*   Updated: 2025/09/16 22:56:29 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define EXTENSION ".cub"
# define EXTENSION_LEN 4

# include "cubstructs.h"

bool	is_map_valid(t_main *cub, char *map_path);

#endif