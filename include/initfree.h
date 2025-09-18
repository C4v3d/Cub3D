/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:32:03 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/18 16:20:06 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITFREE_H
# define INITFREE_H

void	init_cub(t_main *cub);
int		init_display(t_display *dspl, t_main *cub);
int		init_user_inputs(t_usr_ctrl_in *ctrl, t_main *cub);
void	free_cub(t_main *cub);
int		**init_2d_array(int height, int width);

#endif