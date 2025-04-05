/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:24:01 by yehara            #+#    #+#             */
/*   Updated: 2025/04/05 21:42:46 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <scene.h>

int	parse_rt_file(const char *filename, t_scene *scene);
int	parse_ambient(char **elements, t_ambient *ambient);
int	parse_camera(char **elements, t_camera *camera);
int	parse_light(char **elements, t_light *light);
void	*parse_sphere(char **elements);

// util
int	count_array(char **array);
int	parse_color(char *elements, t_color *color);
int	parse_vector(char *elements, t_vec *vector);
int	validate_vector(t_vec vector);
#endif
