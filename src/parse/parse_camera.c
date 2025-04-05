/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:56:00 by yehara            #+#    #+#             */
/*   Updated: 2025/04/03 19:42:01 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <parse.h>
#include <scene.h>

int	parse_camera(char **elements, t_camera *camera)
{
	double	fov;

	if (camera->position.x != -1 || camera->position.y != -1
		|| camera->position.z != -1 || camera->orientation.x != -1
        || camera->orientation.y != -1 || camera->orientation.z != -1
        || camera->fov != -1)
		return (EXIT_FAILURE);
	if (count_array(elements) != 3)
		return (EXIT_FAILURE);
	if (parse_vector(elements[0], &camera->position) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (parse_vector(elements[1], &camera->orientation) == EXIT_FAILURE)
		return (EXIT_FAILURE);
    if (validate_vector(camera->orientation) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    fov = ft_atof(elements[2]);
	if (fov < 0 || fov > 180)
		return (EXIT_FAILURE);
	camera->fov = fov;
	return (EXIT_SUCCESS);
}
