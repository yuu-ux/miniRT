#include <parse.h>

void	init_data(t_scene *scene)
{
	scene->ambient.brightness = -1;
	scene->ambient.color.r = -1;
	scene->ambient.color.g = -1;
	scene->ambient.color.b = -1;
	scene->camera.position.x = -1;
	scene->camera.position.y = -1;
	scene->camera.position.z = -1;
	scene->camera.orientation.x = -1;
	scene->camera.orientation.y = -1;
	scene->camera.orientation.z = -1;
	scene->camera.fov = -1;
	scene->light.position.x = -1;
	scene->light.position.y = -1;
	scene->light.position.z = -1;
	scene->light.brightness = -1;
	scene->light.color.r = -1;
	scene->light.color.g = -1;
	scene->light.color.b = -1;
}

int	main(int argc, char **argv)
{
	t_scene	*scene;
	int		status;

	if (argc != 2)
	{
		printf("usage: ./parse file.rt\n");
		return (EXIT_FAILURE);
	}
	scene = ft_xmalloc(sizeof(t_scene));
	init_data(scene);
	status = parse_rt_file(argv[1], scene);
	if (status == EXIT_SUCCESS)
	{
		printf("brightness: %f\n", scene->ambient.brightness);
		printf("red: %f\n", scene->ambient.color.r);
		printf("green: %f\n", scene->ambient.color.g);
		printf("blue: %f\n", scene->ambient.color.b);
		printf("x: %f\n", scene->camera.position.x);
		printf("y: %f\n", scene->camera.position.y);
		printf("z: %f\n", scene->camera.position.z);
		printf("x: %f\n", scene->camera.orientation.x);
		printf("y: %f\n", scene->camera.orientation.y);
		printf("z: %f\n", scene->camera.orientation.z);
		printf("fov: %f\n", scene->camera.fov);
		printf("x: %f\n", scene->light.position.x);
		printf("y: %f\n", scene->light.position.y);
		printf("z: %f\n", scene->light.position.z);
		printf("brightness: %f\n", scene->light.brightness);
		printf("red: %f\n", scene->light.color.r);
		printf("green: %f\n", scene->light.color.g);
		printf("blue: %f\n", scene->light.color.b);
        while (scene->objects)
        {
            printf("shape: %d\n", ((t_object *)scene->objects->content)->shape);
            printf("x: %f\n", ((t_object *)scene->objects->content)->center.x);
            printf("y: %f\n", ((t_object *)scene->objects->content)->center.y);
            printf("z: %f\n", ((t_object *)scene->objects->content)->center.z);
            printf("x: %f\n", ((t_object *)scene->objects->content)->normal.x);
            printf("y: %f\n", ((t_object *)scene->objects->content)->normal.y);
            printf("z: %f\n", ((t_object *)scene->objects->content)->normal.z);
            printf("diameter: %f\n", ((t_object *)scene->objects->content)->diameter);
            printf("height: %f\n", ((t_object *)scene->objects->content)->height);
            printf("red: %f\n", ((t_object *)scene->objects->content)->color.r);
            printf("green: %f\n", ((t_object *)scene->objects->content)->color.g);
            printf("blue: %f\n", ((t_object *)scene->objects->content)->color.b);
            scene->objects = scene->objects->next;
        }
	}
	return (status);
}
