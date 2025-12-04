/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:08:16 by timmi             #+#    #+#             */
/*   Updated: 2025/12/04 14:08:57 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* Allowed charset to build the map*/
# define CHARSET " 10NSEW"

void	parse_file(t_main *cub);
void	parse_map(t_map *map);
void	id_texture(t_graphic *gfx, char *line);
int		parse_color(t_main *cub, char *line, t_color **dest);

/**
 * Utils
 */
int		get_id_len(char *line);
void	get_start_dir(t_map *m, double dir[AXIS], double *orientation, char c);
bool	is_line_valid(const char *l);
bool	color_validation(char *s);

#endif
