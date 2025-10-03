/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:32:03 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/03 11:56:17 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITFREE_H
# define INITFREE_H

void	init_cub(t_main *cub);
int		init_parsed_data(t_main *cub);
int		init_display(t_display *dspl, t_main *cub);
int		init_hooks(t_main *cub);
int		init_user_inputs(t_usr_ctrl_in *ctrl, t_main *cub);
int		free_cub(t_main *cub);
int		to_close_program(t_main *cub);
char		**init_2d_array(int height, int width);

#endif
