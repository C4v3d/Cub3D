/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:08:16 by timmi             #+#    #+#             */
/*   Updated: 2025/11/02 12:35:19 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

void	parse_file(t_main *cub);
void	parse_data(t_graphic *gfx);
int		get_color(char *line, int len);
int		get_id_len(char *line);
void	parse_map(t_map *map);

/**
 * Utils
 */
int	get_color(char *line, int len);
int	get_id_len(char *line);
void get_start_dir(double dir[AXIS], double *orientation, char c);


#endif