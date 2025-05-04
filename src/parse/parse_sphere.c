/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:16:18 by yehara            #+#    #+#             */
/*   Updated: 2025/04/14 18:32:50 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <scene.h>
#include <util.h>

int	parse_sphere(char **elements, t_object **sphere_ptr)
{
	t_object	*sphere;

	sphere = ft_xmalloc(sizeof(t_object));
	if (count_array(elements) != 3)
		return (free(sphere), ERR_ARG_COUNT);
	if (parse_vector(elements[0], &sphere->center) == EXIT_FAILURE)
		return (free(sphere), ERR_VECTOR_FORMAT);
	if (parse_color(elements[2], &sphere->color) == EXIT_FAILURE)
		return (free(sphere), ERR_COLOR_FORMAT);
	sphere->diameter = ft_xatof(elements[1]);
	if (sphere->diameter == -1)
		return (free(sphere), ERR_ATOF);
	sphere->shape = SPHERE;
	*sphere_ptr = sphere;
	return (SUCCESS);
}
