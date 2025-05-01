/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:01:11 by yehara            #+#    #+#             */
/*   Updated: 2025/04/07 20:33:37 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <scene.h>

int	parse_plane(char **elements, t_object **plane_ptr)
{
	t_object	*plane;

	plane = ft_xmalloc(sizeof(t_object));
	if (count_array(elements) != 3)
		return (free(plane), ERR_ARG_COUNT);
	if (parse_vector(elements[0], &plane->center) == EXIT_FAILURE)
		return (free(plane), ERR_VECTOR_FORMAT);
	if (parse_vector(elements[1], &plane->normal) == EXIT_FAILURE)
		return (free(plane), ERR_VECTOR_FORMAT);
	if (validate_normalize(plane->normal) == EXIT_FAILURE)
		return (free(plane), ERR_NORMALIZE);
	if (parse_color(elements[2], &plane->color) == EXIT_FAILURE)
		return (free(plane), ERR_COLOR_FORMAT);
	plane->shape = PLANE;
	*plane_ptr = plane;
	return (SUCCESS);
}
