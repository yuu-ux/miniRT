/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:56:00 by yehara            #+#    #+#             */
/*   Updated: 2025/04/03 19:42:01 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <scene.h>
#include <util.h>

int	parse_ambient(char **elements, t_ambient *ambient)
{
	double	brightness;

	if (ambient->brightness != -1 || ambient->color.r != -1
		|| ambient->color.g != -1 || ambient->color.b != -1)
		return (EXIT_FAILURE);
	if (count_array(elements) != 2)
		return (EXIT_FAILURE);
	brightness = ft_xatof(elements[0]);
	if (brightness < 0.0 || brightness > 1.0)
		return (EXIT_FAILURE);
	ambient->brightness = brightness;
	if (parse_color(elements[1], &ambient->color) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
