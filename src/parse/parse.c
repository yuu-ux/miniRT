/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:21:03 by yehara            #+#    #+#             */
/*   Updated: 2025/04/07 20:15:02 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <scene.h>
#include <util.h>

static	int	parse_objects(char **elements, t_list **objects, int (*parse_object)(char **elements, t_object **obj))
{
	t_object 	*content;
	int			status;

	content = NULL;
	status = parse_object(elements, &content);
	if (status != SUCCESS)
		return (status);
	if (*objects == NULL)
		*objects = ft_lstnew(content);
	else
		ft_lstadd_back(objects, ft_lstnew(content));
	return (SUCCESS);
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
	else if (ft_strncmp(elements[0], "pl", 2) == 0)
		status = parse_objects(elements + 1, &scene->objects, parse_plane);
	else if (ft_strncmp(elements[0], "cy", 2) == 0)
		status = parse_objects(elements + 1, &scene->objects, parse_cylinder);
	else
		status = EXIT_FAILURE;
	return (status);
}


int	parse_rt_file(const char *filename, t_scene *scene)
{
	int		fd;
	char	*line;
	int		status;

	fd = ft_xopen(filename, O_RDONLY);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line = ft_chomp(line);
		if (ft_strlen(line) <= 0)
		{
			status = parse_rt_line(line, scene);
            printf("%d\n", status);
			if (status != SUCCESS)
				error_exit(NULL, status);
		}
		free(line);
	}
	ft_xclose(fd);
	return (EXIT_SUCCESS);
}

