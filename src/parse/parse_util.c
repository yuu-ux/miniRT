/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:25:37 by yehara            #+#    #+#             */
/*   Updated: 2025/05/01 20:49:40 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <util.h>

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

int	validate_normalize(t_vec vector)
{
	double	magnitude;

	magnitude = length(vector);
	// 1e-6 is 0.000001
	// 0.999999 〜 1.000001 の範囲内に存在するかどうか
	// ベクトルが正規化できるかのチェック
	if (magnitude < 1 - 1e-5 || magnitude > 1 + 1e-5)
		return (EXIT_FAILURE); // message: "Invalid vector but we will normalize it"
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
	vector->x = x;
	vector->y = y;
	vector->z = z;
	free_double_array(vectors);
	return (EXIT_SUCCESS);
}
