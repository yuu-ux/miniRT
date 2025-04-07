/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:01:11 by yehara            #+#    #+#             */
/*   Updated: 2025/04/07 18:02:05 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <scene.h>

t_object	*parse_plane(char **elements)
{
	t_object	*plane;

	plane = ft_xmalloc(sizeof(t_object));
	if (count_array(elements) != 3)
		return (NULL);
	if (parse_vector(elements[0], &plane->center) == EXIT_FAILURE)
		return (NULL);
	if (parse_vector(elements[1], &plane->center) == EXIT_FAILURE)
		return (NULL);
	if (validate_vector(plane->center) == EXIT_FAILURE)
		return (NULL);
	if (parse_color(elements[2], &plane->color) == EXIT_FAILURE)
		return (NULL);
	plane->shape = PLANE;
	return (plane);
}
