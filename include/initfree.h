/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:32:03 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/01 18:54:54 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITFREE_H
# define INITFREE_H

void	safe_destroy_image(t_main *cub, void *ptr);
void	init_cub(t_main *cub);
int		init_parsed_data(t_main *cub);
int		init_display(t_display *dspl, t_main *cub);
int		init_hooks(t_main *cub);
int		free_cub(t_main *cub);
int		loop(t_main *cub);
// char	**init_2d_array(int height, int width);

#endif