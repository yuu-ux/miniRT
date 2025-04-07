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

t_object	*parse_cylinder(char **elements)
{
	t_object	*cylinder;

	cylinder = ft_xmalloc(sizeof(t_object));
	if (count_array(elements) != 5)
		return (NULL);
	if (parse_vector(elements[0], &cylinder->center) == EXIT_FAILURE)
		return (NULL);
	if (parse_vector(elements[1], &cylinder->normal) == EXIT_FAILURE)
		return (NULL);
	if (validate_vector(cylinder->normal) == EXIT_FAILURE)
		return (NULL);
	cylinder->diameter = ft_atof(elements[2]);
	cylinder->height = ft_atof(elements[3]);
	if (parse_color(elements[4], &cylinder->color) == EXIT_FAILURE)
		return (NULL);
	cylinder->shape = CYLINDER;
	return (cylinder);
}
