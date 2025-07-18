/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:25:37 by yehara            #+#    #+#             */
/*   Updated: 2025/04/04 23:00:54 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <util.h>
#include <parse.h>

int	count_array(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

int	parse_color(char *elements, t_color *color)
{
	double	red;
	double	green;
	double	blue;
	char	**colors;

	colors = ft_xsplit(elements, ',');
	if (count_array(colors) != 3)
		return (free_double_array(colors));
	red = ft_xatof(colors[0]);
	green = ft_xatof(colors[1]);
	blue = ft_xatof(colors[2]);
	if ((red < 0 || red > 255) || (green < 0 || green > 255) || (blue < 0
			|| blue > 255))
		return (free_double_array(colors));
	color->r = red;
	color->g = green;
	color->b = blue;
	free_double_array(colors);
	return (EXIT_SUCCESS);
}

int	validate_and_set_vector(t_vec *vector)
{
	double	magnitude;

	magnitude = length(*vector);
	if (vector->x > 1 || vector->x < -1 || vector->y > 1 || vector->y < -1
		|| vector->z > 1 || vector->z < -1)
		return (EXIT_FAILURE);
	if (magnitude < 1 - 1e-6 || magnitude > 1 + 1e-6)
	{
		ft_putstr_fd("The length is not normalized, \
			so we will normalize the vector after parsing.", STDERR_FILENO);
		*vector = normalize(*vector);
	}
	return (EXIT_SUCCESS);
}

int	parse_vector(char *elements, t_vec *vector)
{
	double	x;
	double	y;
	double	z;
	char	**vectors;

	vectors = ft_xsplit(elements, ',');
	if (count_array(vectors) != 3)
		return (free_double_array(vectors));
	x = ft_xatof(vectors[0]);
	y = ft_xatof(vectors[1]);
	z = ft_xatof(vectors[2]);
	if (x == ERR_ATOF_NUM || y == ERR_ATOF_NUM || z == ERR_ATOF_NUM)
		return (free_double_array(vectors));
	vector->x = x;
	vector->y = y;
	vector->z = z;
	free_double_array(vectors);
	return (EXIT_SUCCESS);
}
