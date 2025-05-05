/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:23:35 by yehara            #+#    #+#             */
/*   Updated: 2025/04/07 18:30:27 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <scene.h>
#include <util.h>

int	parse_cylinder(char **elements, t_object **cylinder_ptr)
{
	t_object	*cylinder;

	cylinder = ft_xmalloc(sizeof(t_object));
	if (count_array(elements) != 5)
		return (free(cylinder), ERR_ARG_COUNT);
	if (parse_vector(elements[0], &cylinder->center) == EXIT_FAILURE)
		return (free(cylinder), ERR_VECTOR_FORMAT);
	if (parse_vector(elements[1], &cylinder->normal) == EXIT_FAILURE)
		return (free(cylinder), ERR_VECTOR_FORMAT);
	if (validate_and_set_vector(&cylinder->normal) == EXIT_FAILURE)
		return (free(cylinder), ERR_NORMALIZE);
	cylinder->diameter = ft_xatof(elements[2]);
	cylinder->height = ft_xatof(elements[3]);
	if (parse_color(elements[4], &cylinder->color) == EXIT_FAILURE)
		return (free(cylinder), ERR_COLOR_FORMAT);
	cylinder->shape = CYLINDER;
	*cylinder_ptr = cylinder;
	return (SUCCESS);
}
