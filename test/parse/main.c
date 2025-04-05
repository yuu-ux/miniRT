#include <parse.h>

void	init_data(t_scene *scene)
{
	scene->ambient.brightness = -1;
	scene->ambient.color.r = -1;
	scene->ambient.color.g = -1;
	scene->ambient.color.b = -1;
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
	{
		printf("usage: ./parse file.rt\n");
		return (EXIT_FAILURE);
	}
	scene = ft_xmalloc(sizeof(t_scene));
	init_data(scene);
	return (parse_rt_file(argv[1], scene));
}

