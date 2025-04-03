#include <parse.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_test_case
{
	const char	*filepath;
	int			expected;
}				t_test_case;

void	init_scene(t_scene *scene)
{
	scene->ambient.brightness = -1;
	scene->ambient.color.r = -1;
	scene->ambient.color.g = -1;
	scene->ambient.color.b = -1;
}

int	main(void)
{
	t_scene	*scene;
	int		total;
	int		result;

	scene = ft_xmalloc(sizeof(t_scene));
	t_test_case tests[] = {
		{"./ambient/error_brightness_big.rt", EXIT_FAILURE},
		{"./ambient/error_brightness_small.rt", EXIT_FAILURE},
		{"./ambient/error_color_big.rt", EXIT_FAILURE},
		{"./ambient/error_color_small.rt", EXIT_FAILURE},
		{"./ambient/error_duplicate.rt", EXIT_FAILURE},
		{"./ambient/success.rt", EXIT_SUCCESS},
	};
	total = sizeof(tests) / sizeof(tests[0]);
	for (int i = 0; i < total; i++)
	{
		init_scene(scene);
		result = parse_rt_file(tests[i].filepath, scene);
		if (result != tests[i].expected)
		{
			printf("[FAIL] %s\n", tests[i].filepath);
		}
		else
		{
			printf("[OK]   %s\n", tests[i].filepath);
		}
	}
	// 成功時に scene の中身を見る
	if (parse_rt_file("./ambient/success.rt", scene) == EXIT_SUCCESS)
	{
		printf("ambient.brightness = %f\n", scene->ambient.brightness);
		printf("ambient.color.r = %f\n", scene->ambient.color.r);
		printf("ambient.color.g = %f\n", scene->ambient.color.g);
		printf("ambient.color.b = %f\n", scene->ambient.color.b);
	}
	return (EXIT_SUCCESS);
}
