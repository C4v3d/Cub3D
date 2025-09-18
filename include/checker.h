/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:23:22 by timmi             #+#    #+#             */
/*   Updated: 2025/09/18 11:50:46 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define EXTENSION ".cub"
# define EXTENSION_LEN 4

/**
 * WIP : First check if the size has the correct extension.
 * if so it then open it and save the fd in main
 * struct. If the the file type is incorrect it return
 * an error and pass to ft_perrro in WARNING mod
 */
bool	is_map_valid(t_prog *pr, char *map_path);

#endif