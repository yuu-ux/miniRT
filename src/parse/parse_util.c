/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:25:37 by yehara            #+#    #+#             */
/*   Updated: 2025/04/03 19:25:56 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

int	count_array(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

int	parse_color(char **colors, t_color *color)
{
	double red;
	double green;
	double blue;

	red = ft_atof(colors[0]);
	green = ft_atof(colors[1]);
	blue = ft_atof(colors[2]);
	if ((red < 0 && red > 255)
		|| (green < 0 && green > 255)
		|| (blue < 0 && blue > 255))
		return (EXIT_FAILURE);
	color->r = red;
	color->g = green;
	color->b = blue;
	return (EXIT_SUCCESS);
}
