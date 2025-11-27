/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:32:03 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/27 11:23:13 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITFREE_H
# define INITFREE_H

void	safe_destroy_image(void *mlx, void *img);
void	init_cub(t_main *cub);
int		init_parsed_data(t_main *cub);
int		free_cub(t_main *cub);

#endif
