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

#include <scene.h>
#include <parse.h>
#include <util.h>

t_object    *parse_sphere(char **elements)
{
	t_object *sphere;

	sphere = ft_xmalloc(sizeof(t_object));
	if (count_array(elements) != 3)
		return (free(sphere), NULL);
	if (parse_vector(elements[0], &sphere->center) == EXIT_FAILURE)
		return (free(sphere), NULL);
    if (parse_color(elements[2], &sphere->color) == EXIT_FAILURE)
        return (free(sphere), NULL);
    sphere->diameter = ft_xatof(elements[1]);
    sphere->shape = SPHERE;
	return (sphere);
}

