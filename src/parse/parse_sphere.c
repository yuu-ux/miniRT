/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:16:18 by yehara            #+#    #+#             */
/*   Updated: 2025/04/05 21:42:51 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <parse.h>

void	*parse_sphere(char **elements)
{
	t_sphere *sphere;

	sphere = ft_xmalloc(sizeof(t_sphere));
	if (count_array(elements) != 3)
		return (NULL);
	if (parse_vector(elements[0], &sphere->center) == EXIT_FAILURE)
		return (NULL);
	sphere->diameter = ft_atof(elements[1]);
	return (sphere);
}

