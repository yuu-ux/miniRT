/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:56:00 by yehara            #+#    #+#             */
/*   Updated: 2025/04/02 21:28:39 by yehara           ###   ########.fr       */
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

void	parse_ambient(char **elements, t_ambient *ambient)
{
	char **colors;

	colors = ft_split(elements[1], ',');
	if (count_array(elements) > 2)
		exit(EXIT_FAILURE);
	ambient->brightness = ft_atof(elements[0]);
	ambient->color.r = ft_atof(colors[0]);
	ambient->color.g = ft_atof(colors[1]);
	ambient->color.b = ft_atof(colors[2]);
}

// typedef struct s_ambient {
// 	double	brightness;// [0.0〜1.0]
// 	t_color	color;
// }			t_ambient;
