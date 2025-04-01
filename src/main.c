#include "miniRT.h"
#include "scene.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

int	parse_rt_file(const char *filename, t_scene *scene)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nFailed to open .rt file");
		return (1);
	}

	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	if (line[0] == '\n' || line[0] == '#')
	// 	{
	// 		free(line);
	// 		continue;
	// 	}
	// 	if (parse_rt_line(line, scene) != 0)
	// 	{
	// 		free(line);
	// 		close(fd);
	// 		return (1);
	// 	}
	// 	free(line);
	// }
	// close(fd);
	return (0);
}

int parse_rt_line(char *line, t_scene *scene)
{
	// if (ft_strncmp(line, "A ", 2) == 0)
	// 	return parse_ambient(line + 2, &scene->ambient);
	// else if (ft_strncmp(line, "C ", 2) == 0)
	// 	return parse_camera(line + 2, &scene->camera);
	// else if (ft_strncmp(line, "L ", 2) == 0)
	// 	return parse_light(line + 2, &scene->lights);
	// else if (ft_strncmp(line, "sp", 2) == 0)
	// 	return parse_sphere(line + 2, &scene->objects);
	// else if (ft_strncmp(line, "pl", 2) == 0)
	// 	return parse_plane(line + 2, &scene->objects);
	// else if (ft_strncmp(line, "cy", 2) == 0)
	// 	return parse_cylinder(line + 2, &scene->objects);
	// else
	// {
	// 	ft_putstr_fd("Error\nUnknown identifier\n", 2);
	// 	return (1);
	// }
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		return (printf("Usage: ./miniRT scene.rt\n"));

	// scene初期化
	// ft_bzero(&data, sizeof(t_data));
	// if (parse_rt_file(argv[1], &data.scene) != 0)
	// 	return (1);
	// render_scene(&data);
	return (0);
}
