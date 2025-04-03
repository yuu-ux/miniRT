/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:56:00 by yehara            #+#    #+#             */
/*   Updated: 2025/04/03 19:26:14 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <parse.h>

int	parse_ambient(char **elements, t_ambient *ambient)
{
	char **colors;
	double brightness;

	colors = ft_split(elements[1], ',');
	if (count_array(elements) > 2)
		return (EXIT_FAILURE);
	brightness = ft_atof(elements[0]);
	if (brightness < 0.0 && brightness > 1.0)
		return (EXIT_FAILURE);
	ambient->brightness = ft_atof(elements[0]);
	if (parse_color(colors, &ambient->color) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

