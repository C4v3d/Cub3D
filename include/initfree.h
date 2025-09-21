/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:32:03 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/18 12:25:34 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITFREE_H
# define INITFREE_H

int		init_cub(t_main *cub);
int		init_display(t_display *dspl, t_main *cub);
int		init_user_inputs(t_usr_ctrl_in *ctrl, t_main *cub);
void	free_cub(t_main *cub);
int		**init_2d_array(int height, int width);

#endif