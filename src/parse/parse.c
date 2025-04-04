/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:21:03 by yehara            #+#    #+#             */
/*   Updated: 2025/04/04 21:20:22 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <scene.h>
#include <util.h>

static int	parse_rt_line(char *line, t_scene *scene)
{
	char	**elements;

	elements = ft_split(line, ' ');
	if (ft_strncmp(elements[0], "A", 1) == 0)
		return (parse_ambient(elements + 1, &scene->ambient));
	// else if (ft_strncmp(elements[0], "C", 1) == 0)
	// 	parse_camera(elements + 1, &scene->camera);
	// else if (ft_strncmp(elements[0], "L", 1) == 0)
	// 	parse_light(elements + 1, &scene->lights);
	// else if (ft_strncmp(elements[0], "sp", 2) == 0)
	// 	parse_sphere(elements[0] + 2, &scene->objects);
	// else if (ft_strncmp(elements[0], "pl", 2) == 0)
	// 	parse_plane(elements[0] + 2, &scene->objects);
	// else if (ft_strncmp(elements[0], "cy", 2) == 0)
	// 	parse_cylinder(elements[0] + 2, &scene->objects);
	// else
	// {
	// 	ft_putstr_fd("Error\nUnknown identifier\n", 2);
	// 	exit(EXIT_FAILURE);
	// }
	return (EXIT_SUCCESS);
}

int	parse_rt_file(const char *filename, t_scene *scene)
{
	int		fd;
	char	*line;

	fd = ft_xopen(filename, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		line = ft_chomp(line);
		if (ft_strlen(line) <= 0 || parse_rt_line(line, scene) == EXIT_FAILURE)
		{
			error_exit("map error");
			return (EXIT_FAILURE);
		}
		free(line);
	}
	ft_xclose(fd);
	return (EXIT_SUCCESS);
}
