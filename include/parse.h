/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:24:01 by yehara            #+#    #+#             */
/*   Updated: 2025/05/04 12:21:24 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <scene.h>
# include <mlx_util.h>

typedef enum e_error_status
{
	SUCCESS,
	ERR_ATOF,
	ERR_DUPLICATE,
	ERR_ARG_COUNT,
	ERR_BRIGHTNESS_RANGE,
	ERR_COLOR_FORMAT,
	ERR_VECTOR_FORMAT,
	ERR_NORMALIZE,
	ERR_FOV_RANGE,
}	t_error_status;

int	parse_rt_file(const char *filename, t_scene *scene, t_mlx *mlx);
int	parse_ambient(char **elements, t_ambient *ambient);
int	parse_camera(char **elements, t_camera *camera);
int	parse_light(char **elements, t_light *light);
int	parse_sphere(char **elements, t_object **sphere);
int	parse_plane(char **elements, t_object **plane);
int	parse_cylinder(char **elements, t_object **cylinder);

// util
int	count_array(char **array);
int	parse_color(char *elements, t_color *color);
int	parse_vector(char *elements, t_vec *vector);
int	validate_and_set_vector(t_vec *vector);

#endif
