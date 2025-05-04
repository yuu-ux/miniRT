/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:56:00 by yehara            #+#    #+#             */
/*   Updated: 2025/04/14 19:15:23 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parse.h>
#include <scene.h>
#include <util.h>

int	parse_camera(char **elements, t_camera *camera)
{
	double	fov;

	if (camera->position.x != -1 || camera->position.y != -1
		|| camera->position.z != -1 || camera->orientation.x != -1
		|| camera->orientation.y != -1 || camera->orientation.z != -1
		|| camera->fov != -1)
		return (ERR_DUPLICATE);
	if (count_array(elements) != 3)
		return (ERR_ARG_COUNT);
	if (parse_vector(elements[0], &camera->position) == EXIT_FAILURE)
		return (ERR_VECTOR_FORMAT);
	if (parse_vector(elements[1], &camera->orientation) == EXIT_FAILURE)
		return (ERR_VECTOR_FORMAT);
	if (validate_and_set_vector(&camera->orientation) == EXIT_FAILURE)
		return (ERR_NORMALIZE);
	fov = ft_xatof(elements[2]);
	if (fov < 0 || fov > 180)
		return (ERR_FOV_RANGE);
	camera->fov = fov;
	return (SUCCESS);
}
