/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:49:43 by yehara            #+#    #+#             */
/*   Updated: 2025/04/05 19:37:19 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <scene.h>
#include <util.h>

int	parse_light(char **elements, t_light *light)
{
	double	brightness;

	if (light->position.x != -1 || light->position.y != -1
		|| light->position.z != -1 || light->brightness != -1
		|| light->color.r != -1 || light->color.g != -1
		|| light->color.b != -1)
		return (ERR_DUPLICATE);
	if (count_array(elements) != 3)
		return (ERR_ARG_COUNT);
	if (parse_vector(elements[0], &light->position) == EXIT_FAILURE)
		return (ERR_VECTOR_FORMAT);
	brightness = ft_xatof(elements[1]);
	if (brightness < 0.0 || brightness > 1.0)
		return (ERR_BRIGHTNESS_RANGE);
	light->brightness = brightness;
	if (parse_color(elements[2], &light->color) == EXIT_FAILURE)
		return (ERR_COLOR_FORMAT);
	return (SUCCESS);
}

