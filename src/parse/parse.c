/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:21:03 by yehara            #+#    #+#             */
/*   Updated: 2025/04/05 21:48:35 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <scene.h>
#include <util.h>

static	int	parse_objects(char **elements, t_list **objects, t_object *(*parse_object)(char **elements))
{
	void 	*content;

	content = parse_object(elements);
	if (content == NULL)
		return (EXIT_FAILURE);
	if (*objects == NULL)
		*objects = ft_lstnew(content);
	else
		ft_lstadd_back(objects, ft_lstnew(content));
	return (EXIT_SUCCESS);
}

static int	parse_rt_line(char *line, t_scene *scene)
{
	char	**elements;
	int		status;

	status = 0;
	elements = ft_xsplit(line, ' ');
	if (ft_strncmp(elements[0], "A", 1) == 0)
		status = parse_ambient(elements + 1, &scene->ambient);
	else if (ft_strncmp(elements[0], "C", 1) == 0)
		status = parse_camera(elements + 1, &scene->camera);
	else if (ft_strncmp(elements[0], "L", 1) == 0)
		status = parse_light(elements + 1, &scene->light);
	else if (ft_strncmp(elements[0], "sp", 2) == 0)
		status = parse_objects(elements + 1, &scene->objects, parse_sphere);
	// else if (ft_strncmp(elements[0], "pl", 2) == 0)
	// 	parse_plane(elements[0] + 2, &scene->objects);
	// else if (ft_strncmp(elements[0], "cy", 2) == 0)
	// 	parse_cylinder(elements[0] + 2, &scene->objects);
	// else
	// {
	// 	ft_putstr_fd("Error\nUnknown identifier\n", 2);
	// 	exit(EXIT_FAILURE);
	// }
	free_double_array(elements);
	return (status);
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
			error_exit("input error");
			return (EXIT_FAILURE);
		}
		free(line);
	}
	ft_xclose(fd);
	return (EXIT_SUCCESS);
}
